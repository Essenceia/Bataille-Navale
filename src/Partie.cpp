#include "../lib/Partie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
#include "../lib/Helper.h"
// contructeur par default
Partie::Partie():alleg_present(false)
{

}

// destructeur
Partie::~Partie()
{

}

// les getteurs
// les setteurs

// gestion du tableau

void Partie::AfficherTab(int numtab, bool visible) //affichage
{
    /* affichage du tabeau numtab
    selon le fait qu'il soit le premier ou le second tableau et surtout qu'il
    soit celui que le joueur peut voir ou pas)*/

}
void Partie::changer_val_tableau(int numtab, unsigned int coordonees_x,unsigned int coordonees_y, char newval)
{
    //Changer la valeure d'un des deux tableau
}


/*\fn chargement_partie
* \brief charger une partie
*/
void Partie::chargement_partie(std::string num)
{
    std::string path;

    path = "../Sauvegardes/";
    path += num;
    path += ".txt";
    std::ifstream ifs(path.c_str()); // c_str() retourne le contenu d'une String sous forme de char*
    if (ifs) // si le fichier est bien ouvert
    {
        /*
            ifs >> data recupere la prochaine valeur de ifs et la stocke dans data
            il faut ensuite allouer data à une variable

            exemple :

                ifs >> data ;
                m_snoopy.setPosx(data);

        */
        int data;

    }
    else // en cas d'erreur
    {
        std::cout << "Inexisting Profil" << path << std::endl;
    }

    ifs.close(); // fermeture du flux
}


/// Sauvegarde dans le fichier
void Partie::sauvegarder_partie(std::string num)
{
    // std::ios::app (append) : écrire à la suite
    // Pour ces modes d'ouverture, si le fichier n'existe pas ou s'il n'est pas trouvé, il sera créé.
    std::string path = "../Sauvegardes/";
    path += num;
    path += ".txt";

    std::ofstream ofs(path.c_str(), std::ios::out | std::ios::trunc); // Ouverture fichier en mode "w" et le créé s'il n'existe pas
    //et (truncate) : lorsqu'on ouvre le fichier en écriture, efface tout s'il existe déjà, pour laisser un fichier vide
    if (ofs) // si l'ouverture a réussi
    {

        ///exemple
        // ofs << m_level.get_attr_balle(1) << std::endl;


        ofs.close(); // fermeture du flux
    }


}

void Partie::affichageAlleg(int i){

    blit(alleg.getImage(i),screen,0,0,0,0,SCREEN_W,SCREEN_H);

}

void Partie::affichageCons(unsigned int currentplayer, unsigned int otherplayer){


    for(unsigned int h=0;h<2;h++){
        ConsPrint(0,4+40*h);
        std::cout << "  A B C D E F G H I J K L M N O  ";
        ConsPrint(1,4+40*h);
        std::cout << "* * * * * * * * * * * * * * * * *";
        for(unsigned int i=1;i<16;i++){
            if(i<10) ConsPrint(1+i,2+40*h);
            else ConsPrint(1+i,1+40*h);
            std::cout << i << " *                               *";
        }
        ConsPrint(17,4+40*h);
        std::cout << "* * * * * * * * * * * * * * * * *";
    }



    //Affichage des navires du joueur courant
    for(unsigned int i=0; i<battab[currentplayer].size();i++)
        for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++){
            ConsPrint(2+battab[currentplayer][i]->get_etaty(j),6+battab[currentplayer][i]->get_etatx(j)*2);
            if(battab[currentplayer][i]->get_etattouche(j)) std::cout << "t";
            else switch(battab[currentplayer][i]->get_taille()){

                case 1: std::cout << "s";
                    break;
                case 3: std::cout << "d";
                    break;
                case 5: std::cout << "c";
                    break;
                case 7: std::cout << "K";
                    break;


            }
        }

    ///Affichage des morceaux d'épaves de l'autre joueur
    for(unsigned int i=0; i<battab[otherplayer].size();i++)
        for(unsigned int taille=0;taille<battab[otherplayer][i]->get_taille();taille++)
            if(battab[otherplayer][i]->get_etattouche(taille)==1){
                ConsPrint(2+battab[otherplayer][i]->get_etaty(taille),46+battab[otherplayer][i]->get_etatx(taille)*2);
                std::cout << "t";
            }


    ConsPrint(19,45);
    std::cout << "Ennemis restants";
    ConsPrint(19,63);
    std::cout << "Cuirasse K :  "<< Cui2;
    ConsPrint(20,63);
    std::cout << "Croiseur c :  "<< Cro2;
    ConsPrint(21,63);
    std::cout << "Destroyer d : "<< Des2;
    ConsPrint(22,63);
    std::cout << "Sousmarin s : "<< Sou2;

}

void Partie::LancerPartie(bool ia)
{

    if (alleg_present==1) ChargerImages();

    initPartie();

    int x= 0;
    int y= 0;

    unsigned int choixx=0;
    unsigned int choixy=0;
    unsigned int currentplayer = 0;
    unsigned int otherplayer = 1;
    unsigned int numbatselected = 50;
    unsigned int IAcount = 0;
    bool choixaction = false;
    bool action = false;
    bool tourIA = false;
    bool IAselect = false;
    bool oklength=false;
    std::string num;
    std::string choix;
    bool exitboucle = false;

    srand(time(NULL));


    VerifRestant();
    affichageCons(currentplayer,otherplayer);


    ///BOUCLE DE JEU
    while (!exitboucle)
    {
        if(ia&&currentplayer==1) tourIA=true;
        else tourIA=false;

        VerifRestant();

        //Reset affichage
        if(!tourIA){
            if (alleg_present==1)  blit(alleg.getImage(1),alleg.getImage(0),0,0,0,0,SCREEN_W,SCREEN_H);
        }

        //Premier affichage avec les elements dans les tableaux
        if(!tourIA){
            if (alleg_present==1){
                for(unsigned int i=0; i<battab[currentplayer].size();i++){
                    //Si c'est plus grand q'un sous marin
                    if(battab[currentplayer][i]->get_taille()>2){
                        //On affiche déjà le corps du bateau
                        for(unsigned int taille=0;taille<battab[currentplayer][i]->get_taille()-2;taille++){
                            if(battab[currentplayer][i]->get_etattouche(taille)==0){
                                if(battab[currentplayer][i]->get_orientation()=='h') draw_sprite(alleg.getImage(0), alleg.getImage(61), battab[currentplayer][i]->get_etatx(taille)*21+51, battab[currentplayer][i]->get_etaty(taille)*21+51);
                                else rotate_sprite(alleg.getImage(0), alleg.getImage(61), battab[currentplayer][i]->get_etatx(taille)*21+51, battab[currentplayer][i]->get_etaty(taille)*21+51, ftofix(64));
                            }
                            else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(taille)*21+51, battab[currentplayer][i]->get_etaty(taille)*21+51);
                        }
                        //On affiche les bouts
                        if(battab[currentplayer][i]->get_orientation()=='h'){
                            if(battab[currentplayer][i]->get_etattouche(battab[currentplayer][i]->get_taille()-2)==0) rotate_sprite(alleg.getImage(0), alleg.getImage(60), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-2)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-2)*21+51, ftofix(0));
                            else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-2)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-2)*21+51);
                            if(battab[currentplayer][i]->get_etattouche(battab[currentplayer][i]->get_taille()-1)==0) rotate_sprite(alleg.getImage(0), alleg.getImage(60), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-1)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-1)*21+51, ftofix(128));
                            else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-1)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-1)*21+51);
                        }
                        else{
                            if(battab[currentplayer][i]->get_etattouche(battab[currentplayer][i]->get_taille()-2)==0) rotate_sprite(alleg.getImage(0), alleg.getImage(60), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-2)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-2)*21+51, ftofix(64));
                            else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-2)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-2)*21+51);
                            if(battab[currentplayer][i]->get_etattouche(battab[currentplayer][i]->get_taille()-1)==0) rotate_sprite(alleg.getImage(0), alleg.getImage(60), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-1)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-1)*21+51, ftofix(192));
                            else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(battab[currentplayer][i]->get_taille()-1)*21+51, battab[currentplayer][i]->get_etaty(battab[currentplayer][i]->get_taille()-1)*21+51);
                        }
                    }
                    //Si c'est un sous marin
                    else{
                        if(battab[currentplayer][i]->get_etattouche(0)==0) draw_sprite(alleg.getImage(0), alleg.getImage(62), battab[currentplayer][i]->get_etatx(0)*21+51, battab[currentplayer][i]->get_etaty(0)*21+51);
                        else draw_sprite(alleg.getImage(0), alleg.getImage(63), battab[currentplayer][i]->get_etatx(0)*21+51, battab[currentplayer][i]->get_etaty(0)*21+51);
                    }

                }

                ///Affichage des morceaux d'épaves de l'autre joueur
                for(unsigned int i=0; i<battab[otherplayer].size();i++)
                   for(unsigned int taille=0;taille<battab[otherplayer][i]->get_taille();taille++)
                            if(battab[otherplayer][i]->get_etattouche(taille)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(taille)*21+401, battab[otherplayer][i]->get_etaty(taille)*21+51);


            }
        }

        if(choixaction){


            if(!tourIA){
                if (alleg_present==1) {
                    affichageCons(currentplayer,otherplayer);
                    affichageAlleg(0);
                    rest(1000);
                }

                else{
                    affichageCons(currentplayer,otherplayer);
                    ConsPrint(23,0);
                    system("pause");
                    ConsPrint(23,0);
                    std::cout << "                                                            ";
                }
            }
                otherplayer=currentplayer;
                if(otherplayer==0) currentplayer=1;
                else currentplayer=0;
                choixx=0;
                choixy=0;
                choixaction=false;

                if(Tot1==0){
                    if (alleg_present==1) {
                            draw_sprite(alleg.getImage(0), alleg.getImage(92), 0, 0);
                            affichageAlleg(0);
                            while(!key[KEY_E]);
                            while(key[KEY_E]);
                        }

                        else{
                                system("cls");
                                ConsPrint(10,20);
                                std::cout << "Le Joueur 2 a vaincu le Joueur 1 !";
                                ConsPrint(23,0);
                                system("pause");

                        }
                    exitboucle=true;

                }

                else if(Tot2==0){
                    if (alleg_present==1) {
                            draw_sprite(alleg.getImage(0), alleg.getImage(91), 0, 0);
                            affichageAlleg(0);
                            while(!key[KEY_E]);
                            while(key[KEY_E]);
                        }

                        else{
                                system("cls");
                                ConsPrint(10,20);
                                std::cout << "Le Joueur 1 a vaincu le Joueur 2 !";
                                ConsPrint(23,0);
                                system("pause");

                        }
                    exitboucle=true;

                }

                else if (alleg_present==1 && !ia) {
                    draw_sprite(alleg.getImage(0), alleg.getImage(90), 0, 0);
                    affichageAlleg(0);
                    while(!key[KEY_E]);
                    while(key[KEY_E]);
                }

                else if(alleg_present==0 && !ia){
                    system("cls");
                    ConsPrint(10,20);
                    std::cout << "Veuillez proceder a l'echange de Joueur...";
                    ConsPrint(23,0);
                    system("pause");

                    system("cls");
                    affichageCons(currentplayer,otherplayer);

                }

        }

        else {

            //On regarde si le joueur n'est pas en cooldown du pivotement du cuirasse
            if(battab[currentplayer][0]->get_cd())
            {
                choixaction=true;
                battab[currentplayer][0]->set_cd();
            }

            //Commandes
            else if (alleg_present==1) {

                if(!tourIA){
                ///Selection du bateau
                    //Deplacement du curseur
                    draw_sprite(alleg.getImage(0), alleg.getImage(51),choixx*21+50,choixy*21+50);
                    if(key[KEY_W]){
                        if(choixy!=0) choixy--;
                        while(key[KEY_W]);
                    }
                    if(key[KEY_A]){
                        if(choixx!=0) choixx--;
                        while(key[KEY_A]);
                    }
                    if(key[KEY_S]){
                        if(choixy!=14) choixy++;
                        while(key[KEY_S]);
                    }
                    if(key[KEY_D]){
                        if(choixx!=14) choixx++;
                        while(key[KEY_D]);
                    }

                    //Appui sur e = choix du bateau
                    if(key[KEY_E]){

                        //Verif si y a un bateau ou affichage de "pas de bateau à cet endroit
                        for(unsigned int i=0; i<battab[currentplayer].size();i++)
                                for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++)
                                    if(battab[currentplayer][i]->get_etatx(j)== choixx && battab[currentplayer][i]->get_etaty(j)==choixy && battab[currentplayer][i]->get_etattouche(j)==0)
                                        numbatselected = i;


                        draw_sprite(alleg.getImage(2), alleg.getImage(0), 0, 0);

                        //Bateau selectionné ou pas
                        if(numbatselected!=50){
                            while(!action){

                                x= mouse_x;
                                y= mouse_y;


                                if( x>=105 && x<=295 && y>=120 && y<=220 && mouse_b & 1 ){

                                    Tirer(currentplayer,otherplayer,numbatselected,tourIA);
                                    choixaction=true;
                                    action=true;
                                }

                                //Joueur clique sur pivoter
                                if( x>=305 && x<=495 && y>=120 && y<=220 && mouse_b & 1 ){

                                    choixaction=TournerBateau(currentplayer,numbatselected);
                                    action=true;
                                }

                                if( x>=505 && x<=695 && y>=120 && y<=220 && mouse_b & 1 ){

                                    choixaction=DeplacerBateau(currentplayer,numbatselected);
                                    action=true;
                                }

                                if(!action){
                                    //Choix de l'action
                                    draw_sprite(alleg.getImage(0), alleg.getImage(10), 50, 100);
                                    affichageAlleg(0);
                                }

                            }
                            action=false;

                            //Choix de la cible de l'action
                        }

                        else {
                            draw_sprite(alleg.getImage(0), alleg.getImage(11), 50, 100);
                            affichageAlleg(0);
                            rest(1000);
                        }

                        numbatselected=50;

                    }

                    //Sauvegarde
                    if(key[KEY_S]) {

                            //Recuperer via clic quel num de sauvegarde
                            sauvegarder_partie(num);
                    }

                    //Quitter
                    if(key[KEY_ESC]) exitboucle=true;
                }
            }

            else {

                if(!tourIA){
                    numbatselected = 50;

                    ConsPrint(19,6);
                    std::cout << "Veuillez choisir votre bateau :";
                    ConsPrint(20,8);
                    std::cout << "exemple : b6 (s pour save)";

                    oklength=false;
                    while(!oklength){
                        ConsPrint(22,10);
                        std::cout << "               ";
                        ConsPrint(22,10);
                        std::cin >> choix;


                        if(choix.length()==1||choix.length()==2||choix.length()==3) oklength=true;

                    }

                    ConsPrint(22,10);

                    switch(choix[0]){
                        case 'a' : choixx=0; break;
                        case 'b' : choixx=1; break;
                        case 'c' : choixx=2; break;
                        case 'd' : choixx=3; break;
                        case 'e' : choixx=4; break;
                        case 'f' : choixx=5; break;
                        case 'g' : choixx=6; break;
                        case 'h' : choixx=7; break;
                        case 'i' : choixx=8; break;
                        case 'j' : choixx=9; break;
                        case 'k' : choixx=10; break;
                        case 'l' : choixx=11; break;
                        case 'm' : choixx=12; break;
                        case 'n' : choixx=13; break;
                        case 'o' : choixx=14; break;
                        case 's' : sauvegarder_partie(num);
                    }
                    if(choix.length()>=2){
                        switch(choix[1]){
                            case '1' : if(choix.length()==3)
                                        switch(choix[2]){
                                            case '0' : choixy=9; break;
                                            case '1' : choixy=10; break;
                                            case '2' : choixy=11; break;
                                            case '3' : choixy=12; break;
                                            case '4' : choixy=13; break;
                                            case '5' : choixy=14; break;

                                        }
                                        else choixy=0; break;
                            case '2' : choixy=1; break;
                            case '3' : choixy=2; break;
                            case '4' : choixy=3; break;
                            case '5' : choixy=4; break;
                            case '6' : choixy=5; break;
                            case '7' : choixy=6; break;
                            case '8' : choixy=7; break;
                            case '9' : choixy=8; break;
                        }
                    for(unsigned int i=0; i<battab[currentplayer].size();i++)
                        for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++)
                            if(battab[currentplayer][i]->get_etatx(j)== choixx && battab[currentplayer][i]->get_etaty(j)==choixy && battab[currentplayer][i]->get_etattouche(j)==0)
                                numbatselected = i;

                    }

                    //Bateau selectionné ou pas
                    if(numbatselected!=50){
                        while(!action){
                        ConsPrint(19,6);
                        std::cout << "Veuillez choisir votre action :";
                        ConsPrint(20,8);
                        std::cout << "t : tirer, p : pivoter, d : deplacement";
                        oklength=false;
                            while(!oklength){
                                ConsPrint(22,10);
                                std::cout << "          ";
                                ConsPrint(22,10);
                                std::cin >> choix;

                                if(choix.length()==1) oklength=true;
                            }
                        ConsPrint(20,8);
                        std::cout << "                                       ";

                        switch(choix[0]){
                                case 't' :  Tirer(currentplayer,otherplayer,numbatselected,tourIA);
                                            choixaction=true;
                                            action=true;
                                    break;
                                case 'p' :  choixaction=TournerBateau(currentplayer,numbatselected);
                                            action=true;
                                    break;
                                case 'd' :  choixaction=DeplacerBateau(currentplayer,numbatselected);
                                            action=true;
                                    break;
                            }
                        }
                        action=false;


                    }
                }
            }

            if(tourIA){


                IAselect=false;
                IAcount=0;

                while(!IAselect)
                {
                    if(!battab[currentplayer][IAcount]->is_dead()){
                        numbatselected=IAcount;
                        IAselect=true;
                    }
                    IAcount++;
                }

                Tirer(currentplayer,otherplayer,numbatselected,tourIA);
                choixaction=true;

            }
        }

        //Dernier affichage
        if(!tourIA) {
            if (alleg_present==1)  affichageAlleg(0);
        }

    }

    resetpartie();
    if (alleg_present==1) DestroyImages();
}

void Partie::VerifRestant()
{
    Cui1=1; Cui2=1; Cro1=2; Cro2=2; Des1=3; Des2=3; Sou1=4; Sou2=4;

    //Verifier l'état des bateaux
    for(unsigned int i=0; i<battab[0].size();i++)
    if(battab[0][i]->is_dead())
        switch(battab[0][i]->get_taille()){
            case 1 : Sou1--;
                break;
            case 3 : Des1--;
                break;
            case 5 : Cro1--;
                break;
            case 7 : Cui1--;
                break;
        }
    for(unsigned int i=0; i<battab[1].size();i++)
    if(battab[1][i]->is_dead())
        switch(battab[1][i]->get_taille()){
            case 1 : Sou2--;
                break;
            case 3 : Des2--;
                break;
            case 5 : Cro2--;
                break;
            case 7 : Cui2--;
                break;
        }


    //Faire le total
    Tot1=Cui1+Cro1+Des1+Sou1;
    Tot2=Cui2+Cro2+Des2+Sou2;
}

void Partie::setal(bool al)
{
    alleg_present=al;
}

void Partie::ConsPrint(unsigned int y,unsigned int x)
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );
}

void Partie::ChargerImages()
{
    alleg.ChargerImages();
}

void Partie::DestroyImages()
{
    alleg.DestroyImages();
}

void Partie::Tirer(unsigned int currentplayer, unsigned int otherplayer, unsigned int numbatselected, bool tourIA)
{

    //Recup type de tir avec rayon d'action
    unsigned int dest_x=0;
    unsigned int dest_y=0;
    unsigned int rayon=0;
    unsigned int maxvalue=0;
    bool oklength=false;
    std::string choixplace;
    bool isfusee = battab[currentplayer][numbatselected]->get_fusee();
    bool choix=false;
    srand(time(NULL));

    switch(battab[currentplayer][numbatselected]->get_taille())
    {
        case 1 : rayon=1;
            break;
        case 3 : if(isfusee) rayon=4;
            else rayon=1;
            break;
        case 5 : rayon=2;
            break;
        case 7 : rayon=3;
            break;

    }

    if(tourIA){
        maxvalue=16-rayon;
        dest_x=rand()%maxvalue;
        dest_y=rand()%maxvalue;
        choix=true;
    }

    //Laisse le joueur choisir où tirer
    while(!choix){
        //Commandes
        if (alleg_present==1) {

            ///Selection du bateau
            //Deplacement du curseur
            draw_sprite(alleg.getImage(3), alleg.getImage(2),0,0);

            draw_sprite(alleg.getImage(3), alleg.getImage(50+rayon),dest_x*21+400,dest_y*21+50);


            if(key[KEY_W]){
                if(dest_y!=0) dest_y--;
                while(key[KEY_W]);
            }
            if(key[KEY_A]){
                if(dest_x!=0) dest_x--;
                while(key[KEY_A]);
            }
            if(key[KEY_S]){
                if(dest_y!=15-rayon) dest_y++;
                while(key[KEY_S]);
            }
            if(key[KEY_D]){
                if(dest_x!=15-rayon) dest_x++;
                while(key[KEY_D]);
            }

            //Appuie sur E et action selon le type du bateau
            if(key[KEY_E]){
                choix=true;
                while(key[KEY_E]);
            }

            //Affichage des options
            affichageAlleg(3);
        }

        else{

            ConsPrint(19,6);
            std::cout << "Veuillez choisir votre cible : ";
            ConsPrint(20,8);
            std::cout << "exemple : b6";

                oklength=false;
                while(!oklength){
                    ConsPrint(22,10);
                    std::cout << "          ";
                    ConsPrint(22,10);
                    std::cin >> choixplace;

                    if(choixplace.length()==2||choixplace.length()==3) oklength=true;

                }

                ConsPrint(22,10);
                std::cout << "          ";

                switch(choixplace[0]){
                    case 'a' : dest_x=0; break;
                    case 'b' : dest_x=1; break;
                    case 'c' : dest_x=2; break;
                    case 'd' : dest_x=3; break;
                    case 'e' : dest_x=4; break;
                    case 'f' : dest_x=5; break;
                    case 'g' : dest_x=6; break;
                    case 'h' : dest_x=7; break;
                    case 'i' : dest_x=8; break;
                    case 'j' : dest_x=9; break;
                    case 'k' : dest_x=10; break;
                    case 'l' : dest_x=11; break;
                    case 'm' : dest_x=12; break;
                    case 'n' : dest_x=13; break;
                    case 'o' : dest_x=14; break;
                }
                switch(choixplace[1]){
                        case '1' : if(choixplace.length()==3)
                                    switch(choixplace[2]){
                                        case '0' : dest_y=9; break;
                                        case '1' : dest_y=10; break;
                                        case '2' : dest_y=11; break;
                                        case '3' : dest_y=12; break;
                                        case '4' : dest_y=13; break;
                                        case '5' : dest_y=14; break;

                                    }
                                    else dest_y=0; break;
                        case '2' : dest_y=1; break;
                        case '3' : dest_y=2; break;
                        case '4' : dest_y=3; break;
                        case '5' : dest_y=4; break;
                        case '6' : dest_y=5; break;
                        case '7' : dest_y=6; break;
                        case '8' : dest_y=7; break;
                        case '9' : dest_y=8; break;
                }
            choix=true;
        }
    }

    if(!tourIA && alleg_present==1) draw_sprite(alleg.getImage(3), alleg.getImage(2),0,0);

    //On effectue l'action pour chaque type de tir

    for(unsigned int i=0; i<battab[otherplayer].size();i++)
        for(unsigned int j=0; j<battab[otherplayer][i]->get_taille();j++)
            for(unsigned int k=0;k<rayon;k++)
                for(unsigned int l=0;l<rayon;l++)
                {
                    //fusee
                    if(isfusee&&(dest_x+k==battab[otherplayer][i]->get_etatx(j)&&dest_y+l==battab[otherplayer][i]->get_etaty(j))){
                         if(alleg_present==1) draw_sprite(alleg.getImage(3), alleg.getImage(71),(dest_x+k)*21+401,(dest_y+l)*21+51);
                         else {
                            ConsPrint(2+battab[otherplayer][i]->get_etaty(j),46+battab[otherplayer][i]->get_etatx(j)*2);
                            std::cout << "!";

                         }
                         battab[currentplayer][numbatselected]->set_fusee();
                    }

                    //Faiblesse du sousmarin
                    else if((battab[currentplayer][numbatselected]->get_taille()==1)&&
                            (dest_x==battab[otherplayer][i]->get_etatx(j)&&dest_y==battab[otherplayer][i]->get_etaty(j))
                            &&(battab[otherplayer][i]->get_taille()==1)){
                        battab[otherplayer][i]->set_etat(0,1);
                        if(alleg_present==1) draw_sprite(alleg.getImage(3), alleg.getImage(70),(dest_x)*21+401,(dest_y)*21+51);

                    }
                    //Destruction pure et dure
                    else if(dest_x+k==battab[otherplayer][i]->get_etatx(j)&&dest_y+l==battab[otherplayer][i]->get_etaty(j)){
                         if(alleg_present==1) draw_sprite(alleg.getImage(3), alleg.getImage(70),(dest_x+k)*21+401,(dest_y+l)*21+51);
                         battab[otherplayer][i]->set_etat(j,1);
                    }
                }

    if(!tourIA){
        if(alleg_present==1) {
            affichageAlleg(3);
            rest(2000);
        }
        else {
            if(isfusee){
                ConsPrint(23,0);
                system("pause");
                ConsPrint(23,0);
                std::cout << "                                                            ";
            }
            affichageCons(currentplayer,otherplayer);
        }
    }
}

bool Partie::DeplacerBateau(unsigned int currentplayer, unsigned int numbatselected){

    bool ok=true, okh=true, okb=true, okd=true, okg=true, oklength=false;
    unsigned int x0 = battab[currentplayer][numbatselected]->get_etatx(0);
    unsigned int y0 = battab[currentplayer][numbatselected]->get_etaty(0);
    unsigned int t = battab[currentplayer][numbatselected]->get_taille();
    bool choixaction=false;
    std::string choixplace;
    unsigned int choix=5; //0=h, 1=b, 2=d, 3=g

    //On vérifie si le bateau est endommagé
    for(unsigned int j=0; j<battab[currentplayer][numbatselected]->get_taille();j++)
        if(battab[currentplayer][numbatselected]->get_etattouche(j)==1)
            ok = false;

    //On vérifie maintenant si il peut se déplacer sans entrer en collision avec un autre bateau
    for(unsigned int i=0; i<battab[currentplayer].size();i++)
        for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++){
                if((x0==battab[currentplayer][i]->get_etatx(j)&&y0-((t+1)/2)==battab[currentplayer][i]->get_etaty(j))||y0==((t-1)/2)) okh=false;
                if((x0==battab[currentplayer][i]->get_etatx(j)&&y0+((t+1)/2)==battab[currentplayer][i]->get_etaty(j))||y0==14-((t-1)/2)) okb=false;
                if((x0+((t+1)/2)==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||x0==14-((t-1)/2)) okd=false;
                if((x0-((t+1)/2)==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||x0==((t-1)/2)) okg=false;
            }

    if(battab[currentplayer][numbatselected]->get_taille()>1&&battab[currentplayer][numbatselected]->get_orientation()=='h'){
        okh=false; okb=false;
    }

    if(battab[currentplayer][numbatselected]->get_taille()>1&&battab[currentplayer][numbatselected]->get_orientation()=='v'){
        okd=false; okg=false;
    }

    if(okh||okb||okd||okg){
        while(!choixaction){

            if(alleg_present==1){
                //On affiche les possibilités de déplacements en fn des bateaux
                if(okh) draw_sprite(alleg.getImage(2), alleg.getImage(51), x0*21+50, y0*21+50-21*((t+1)/2));
                if(okb) draw_sprite(alleg.getImage(2), alleg.getImage(51), x0*21+50, y0*21+50+21*((t+1)/2));
                if(okd) draw_sprite(alleg.getImage(2), alleg.getImage(51), x0*21+50+21*((t+1)/2), y0*21+50);
                if(okg) draw_sprite(alleg.getImage(2), alleg.getImage(51), x0*21+50-21*((t+1)/2), y0*21+50);

                //on recup l'input user et on effectue le deplacement

                 if(key[KEY_W]&&okh){
                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                        battab[currentplayer][numbatselected]->set_etaty(j, battab[currentplayer][numbatselected]->get_etaty(j)-1);
                    choixaction=true;
                    while(key[KEY_W]);
                }
                if(key[KEY_A]&&okg){
                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                        battab[currentplayer][numbatselected]->set_etatx(j, battab[currentplayer][numbatselected]->get_etatx(j)-1);
                    choixaction=true;
                    while(key[KEY_A]);
                }
                if(key[KEY_S]&&okb){
                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                        battab[currentplayer][numbatselected]->set_etaty(j, battab[currentplayer][numbatselected]->get_etaty(j)+1);
                    choixaction=true;
                    while(key[KEY_S]);
                }
                if(key[KEY_D]&&okd){
                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                        battab[currentplayer][numbatselected]->set_etatx(j, battab[currentplayer][numbatselected]->get_etatx(j)+1);
                    choixaction=true;
                    while(key[KEY_D]);
                }

                //Affichage des options
                affichageAlleg(2);
            }

            else{

                ConsPrint(19,6);
                std::cout << "Veuillez choisir la direction :";
                ConsPrint(20,8);
                std::cout << "h,b,g ou d";

                    oklength=false;
                    while(!oklength){
                        ConsPrint(22,10);
                        std::cout << "          ";
                        ConsPrint(22,10);
                        std::cin >> choixplace;

                        if(choixplace.length()==1) oklength=true;

                    }

                    ConsPrint(22,10);
                    std::cout << "          ";

                    switch(choixplace[0]){
                        case 'h' : if(okh)
                                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                                        battab[currentplayer][numbatselected]->set_etaty(j, battab[currentplayer][numbatselected]->get_etaty(j)-1);
                                    choixaction=true;
                            break;
                        case 'b' : if(okb)
                                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                                        battab[currentplayer][numbatselected]->set_etaty(j, battab[currentplayer][numbatselected]->get_etaty(j)+1);
                                    choixaction=true;
                            break;
                        case 'g' : if(okg)
                                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                                        battab[currentplayer][numbatselected]->set_etatx(j, battab[currentplayer][numbatselected]->get_etatx(j)-1);
                                    choixaction=true;
                            break;
                        case 'd' : if(okd)
                                    for(unsigned int j=0;j<battab[currentplayer][numbatselected]->get_taille();j++)
                                        battab[currentplayer][numbatselected]->set_etatx(j, battab[currentplayer][numbatselected]->get_etatx(j)+1);
                                    choixaction=true;
                            break;
                    }

            }
        }
        choixaction=false;
    }
    else ok=false;


    if(!ok) {

        if(alleg_present){
            draw_sprite(alleg.getImage(0), alleg.getImage(12), 50, 100);
            affichageAlleg(0);
            rest(1000);
        }
    }

    return ok;

}

bool Partie::TournerBateau(unsigned int currentplayer, unsigned int numbatselected){

    bool ok=true;
    unsigned int h=1, v=1, plac=1;
    unsigned int x0 = battab[currentplayer][numbatselected]->get_etatx(0);
    unsigned int y0 = battab[currentplayer][numbatselected]->get_etaty(0);


    //On vérifie si le bateau est endommagé
    for(unsigned int j=0; j<battab[currentplayer][numbatselected]->get_taille();j++)
        if(battab[currentplayer][numbatselected]->get_etattouche(j)==1 || battab[currentplayer][numbatselected]->get_taille()==1)
            ok = false;

    //On vérifie maintenant si il peut pivoter dans entrer en collision avec un autre bateau
    switch(battab[currentplayer][numbatselected]->get_taille())
    {
        //Sous marin (ne peut pas pivoter)
        case 1 :    ok = false;
            break;
        case 3 :    for(unsigned int i=0; i<battab[currentplayer].size();i++)
                for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++){
                    if(battab[currentplayer][numbatselected]->get_orientation()=='h')
                        if((x0==battab[currentplayer][i]->get_etatx(j)&&y0-1==battab[currentplayer][i]->get_etaty(j))||
                            (x0==battab[currentplayer][i]->get_etatx(j)&&y0+1==battab[currentplayer][i]->get_etaty(j)))
                                ok=false;
                    if(battab[currentplayer][numbatselected]->get_orientation()=='v')
                        if((x0-1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                            (x0+1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j)))
                                ok=false;
                }
            break;
        case 5 :    for(unsigned int i=0; i<battab[currentplayer].size();i++)
                        for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++){
                            if(battab[currentplayer][numbatselected]->get_orientation()=='h')
                                if((x0==battab[currentplayer][i]->get_etatx(j)&&y0-1==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0+1==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0-2==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0+2==battab[currentplayer][i]->get_etaty(j)))
                                        ok=false;
                            if(battab[currentplayer][numbatselected]->get_orientation()=='v')
                                if((x0-1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0+1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0-2==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0+2==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j)))
                                        ok=false;
                        }
            break;
        case 7 :       for(unsigned int i=0; i<battab[currentplayer].size();i++)
                        for(unsigned int j=0; j<battab[currentplayer][i]->get_taille();j++){
                            if(battab[currentplayer][numbatselected]->get_orientation()=='h')
                                if((x0==battab[currentplayer][i]->get_etatx(j)&&y0-1==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0+1==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0-2==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0+2==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0-3==battab[currentplayer][i]->get_etaty(j))||
                                    (x0==battab[currentplayer][i]->get_etatx(j)&&y0+3==battab[currentplayer][i]->get_etaty(j)))
                                        ok=false;
                            if(battab[currentplayer][numbatselected]->get_orientation()=='v')
                                if((x0-1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0+1==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0-2==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0+2==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0-3==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j))||
                                    (x0+3==battab[currentplayer][i]->get_etatx(j)&&y0==battab[currentplayer][i]->get_etaty(j)))
                                        ok=false;
                        }
            break;

    }


    if(ok==true){
        //On effectue le pivotement
        if(battab[currentplayer][numbatselected]->get_orientation()=='h') {
                battab[currentplayer][numbatselected]->set_orientation('v');
                h=0;
        }
        else {
                battab[currentplayer][numbatselected]->set_orientation('h');
                v=0;
        }

        for(unsigned int i=1;i<(battab[currentplayer][numbatselected]->get_taille()-1);i=i+2) {
            battab[currentplayer][numbatselected]->set_etatx(i, x0-plac*h);
            battab[currentplayer][numbatselected]->set_etaty(i, y0-plac*v);

            battab[currentplayer][numbatselected]->set_etatx(i+1, x0+plac*h);
            battab[currentplayer][numbatselected]->set_etaty(i+1, y0+plac*v);

            plac++;
        }
        plac=1;
        h=1;
        v=1;

        if(battab[currentplayer][numbatselected]->get_taille()==7) battab[currentplayer][numbatselected]->set_cd();
    }
    else {

        if(alleg_present){
            draw_sprite(alleg.getImage(0), alleg.getImage(12), 50, 100);
            affichageAlleg(0);
            rest(1000);
        }
    }


    return ok;
}

void Partie::resetpartie()//Gros reset pour remettre la partie à 0 à la fin de celle ci ou au retour au menu
{
    ///IL FAUT CLEAR LES VECTEURS ET VIRER LES CASES EN FAISANT ATTENTION AU FAIT QUE CE SOIT DES POINTEURS

    battab.clear();

}

void Partie::initPartie()//Initialisation avec le placement des bateaux surtout
{

    char orirand=0;
    unsigned int xrand=0;
    unsigned int yrand=0;
    bool ok=false;
    ///INITIALISER LES VECTEURS ICI
    srand (time(NULL));

    //Initialiser les bateaux !
    battab.resize(2);

    //POUR CHAQUE JOUEUR
    for(unsigned int i=0;i<2;i++){
        //POUR CHAQUE BATEAU
        for(unsigned int j=0;j<10;j++)
        {
            //orientation
            if(rand()%2==0) orirand='h';
            else orirand='v';

            switch(j){
            //x, y
            //Verifier tout x et y libres
            //placer bateau

            case 0:
                xrand = rand()%9 +3;
                yrand = rand()%9 +3;

                battab[i].push_back(new Cuirasse(xrand,yrand,7,orirand));
                break;

            case 1:
            case 2:
                while(!ok){
                    ok=true;
                    xrand = rand()%11 +2;
                    yrand = rand()%11 +2;
                    for(unsigned int numbat=0;numbat<battab[i].size();numbat++)
                        for(unsigned int taille=0;taille<battab[i][numbat]->get_taille();taille++){
                            if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                            if( orirand=='h' ){
                                if( battab[i][numbat]->get_etatx(taille)==xrand-1 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand+1 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand-2 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand+2 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                            }
                            else{
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand-1 ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand+1 ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand-2 ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand+2 ) ok=false;

                            }
                        }
                }
                ok=false;

                battab[i].push_back(new Croiseur(xrand,yrand,5,orirand));
                break;

            case 3:
            case 4:
            case 5:
                while(!ok){
                    ok=true;
                    xrand = rand()%13 +1;
                    yrand = rand()%13 +1;
                    for(unsigned int numbat=0;numbat<battab[i].size();numbat++)
                        for(unsigned int taille=0;taille<battab[i][numbat]->get_taille();taille++){
                            if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                            if( orirand=='h' ){
                                if( battab[i][numbat]->get_etatx(taille)==xrand-1 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand+1 && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                            }
                            else{
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand-1 ) ok=false;
                                if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand+1 ) ok=false;

                            }
                        }
                }
                ok=false;

                battab[i].push_back(new Destroyer(xrand,yrand,3,orirand));
                break;

            case 6:
            case 7:
            case 8:
            case 9:
                while(!ok){
                    ok=true;
                    xrand = rand()%15;
                    yrand = rand()%15;
                    for(unsigned int numbat=0;numbat<j;numbat++)
                        for(unsigned int taille=0;taille<battab[i][numbat]->get_taille();taille++)
                            if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
                }
                ok=false;

                battab[i].push_back(new Sousmarin(xrand,yrand,1,orirand));
                break;
            }
        }
    }




}
