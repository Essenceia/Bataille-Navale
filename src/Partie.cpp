#include "../lib/Partie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <time.h>
#include "../lib/Helper.h"
#include "Allegro.h"
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

void Partie::affichageAlleg(){

    blit(alleg.getImage(0),screen,0,0,0,0,SCREEN_W,SCREEN_H);

}

void Partie::affichageCons(){

}

void Partie::LancerPartie(bool ia)
{

    if (alleg_present==1) ChargerImages();
    initPartie();

    int x= 0;
    int y= 0;

    unsigned int choixx=0;
    unsigned int choixy=0;
    unsigned int currentplayer = 1;
    unsigned int otherplayer = 0;
    unsigned int numbatselected = 50;
    bool choixaction = false;
    std::string num;
    bool exitboucle = false;
    ///BOUCLE DE JEU
    while (!exitboucle)
    {

        //Reset affichage
        if (alleg_present==1)  blit(alleg.getImage(1),alleg.getImage(0),0,0,0,0,SCREEN_W,SCREEN_H);
        else system("cls");

        //Premier affichage avec les elements dans les tableaux
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
            for(unsigned int i=0; i<battab[otherplayer].size();i++){
                //Si c'est plus grand q'un sous marin
                if(battab[otherplayer][i]->get_taille()>2){
                    //On affiche déjà le corps du bateau
                    for(unsigned int taille=0;taille<battab[otherplayer][i]->get_taille()-2;taille++){
                        if(battab[otherplayer][i]->get_etattouche(taille)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(taille)*21+401, battab[otherplayer][i]->get_etaty(taille)*21+51);
                    }
                    //On affiche les bouts
                    if(battab[otherplayer][i]->get_orientation()=='h'){
                        if(battab[otherplayer][i]->get_etattouche(battab[otherplayer][i]->get_taille()-2)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(battab[otherplayer][i]->get_taille()-2)*21+401, battab[otherplayer][i]->get_etaty(battab[otherplayer][i]->get_taille()-2)*21+51);
                        if(battab[otherplayer][i]->get_etattouche(battab[otherplayer][i]->get_taille()-1)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(battab[otherplayer][i]->get_taille()-1)*21+401, battab[otherplayer][i]->get_etaty(battab[otherplayer][i]->get_taille()-1)*21+51);
                    }
                    else{
                        if(battab[otherplayer][i]->get_etattouche(battab[otherplayer][i]->get_taille()-2)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(battab[otherplayer][i]->get_taille()-2)*21+401, battab[otherplayer][i]->get_etaty(battab[otherplayer][i]->get_taille()-2)*21+51);
                        if(battab[otherplayer][i]->get_etattouche(battab[otherplayer][i]->get_taille()-1)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(battab[otherplayer][i]->get_taille()-1)*21+401, battab[otherplayer][i]->get_etaty(battab[otherplayer][i]->get_taille()-1)*21+51);
                    }
                }
                //Si c'est un sous marin
                else{
                    if(battab[otherplayer][i]->get_etattouche(0)==1) draw_sprite(alleg.getImage(0), alleg.getImage(70), battab[otherplayer][i]->get_etatx(0)*401+51, battab[otherplayer][i]->get_etaty(0)*21+51);
                }

            }
        }
        else{

        }

        //Commandes
        if (alleg_present==1) {

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

                //Bateau selectionné ou pas
                if(numbatselected!=50){
                    while(!choixaction){

                        x= mouse_x;
                        y= mouse_y;

                        if( x>=105 && x<=295 && y>=120 && y<=220 && mouse_b & 1 ){

                                //Choix de la cible

                                choixaction=true;
                        }

                        if( x>=305 && x<=495 && y>=120 && y<=220 && mouse_b & 1 ){

                                //Choix de la cible

                                choixaction=true;
                        }

                        if( x>=505 && x<=695 && y>=120 && y<=220 && mouse_b & 1 ){

                                //battab[currentplayer][numbatselected]->Tourner();
                                choixaction=true;
                        }

                        //Choix de l'action
                        draw_sprite(alleg.getImage(0), alleg.getImage(10), 50, 100);
                        affichageAlleg();

                    }

                    //Choix de la cible de l'action
                }

                else {
                    draw_sprite(alleg.getImage(0), alleg.getImage(11), 50, 100);
                    affichageAlleg();
                }

                numbatselected=50;
                choixaction=false;
                while(key[KEY_E]);

            }


            if(key[KEY_Q]){
                otherplayer=currentplayer;
                if(otherplayer==0) currentplayer=1;
                else currentplayer=0;
                while(key[KEY_Q]);
            }

            //Sauvegarde
            if(key[KEY_S]) {

                    //Recuperer via clic quel num de sauvegarde
                    sauvegarder_partie(num);
            }

            //Quitter
            if(key[KEY_ESC]) exitboucle=true;
        }

        else {

            //Affichage des différentes demandes d'actions
            //Recuperation de l'action


        }

        //Dernier affichage
        if (alleg_present==1)  affichageAlleg();
        else affichageCons();


    }

    resetpartie();
    if (alleg_present==1) DestroyImages();
}

void Partie::setal(bool al)
{
    alleg_present=al;
}

void Partie::ConsPrint(unsigned int y,unsigned int x)
{
#ifdef WINDOWS
    COORD xy;
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );
#else

        printf("\033[%d;%dH", y+1, x+1);
#endif
}

void Partie::ChargerImages()
{
    alleg.ChargerImages();
}

void Partie::DestroyImages()
{
    alleg.DestroyImages();
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

   //Resize
    tabj.resize(2);
    for(unsigned int i=0; i<2 ; i++){
        tabj[i].resize(2);
        for(unsigned int j=0; j<2; j++){
            tabj[i][j].resize(15);
            for(unsigned int k=0; k<15; k++)
                tabj[i][j][k].resize(15);
        }
    }
    //Init
    for(unsigned int p=0; p<2 ; p++)
        for(unsigned int i=0; i<2 ; i++)
            for(unsigned int j=0; j<15; j++)
                for(unsigned int k=0; k<15; k++)
                    tabj[p][i][j][k] = ' ';

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

Bateau* Partie::get_Bateau(unsigned int x, unsigned int y,unsigned int idplayer){
  /*bool found = false;
  Bateau* tmpbat;
  for( int i = 0 ; i < battab[idplayer].size() ; i++){
    tmpbat = battab[idplayer][i];
    if(tmpbat.get_existe()){
      //si le bateau n'est pas encore couler
      switch(tmpbat.get_orientation()){
        case ('h' || 'g'): if(tmpbat.get_px()==x){
          if((tmpbat.get_py()-((tmpbat.get_taille()-1)/2))==y){
           goto END;
          }
        }
        break;
        case ('v' || 'b'): if(tmpbat.get_py()==y){
          if((tmpbat.get_px()-((tmpbat.get_taille()-1)/2))==y){
           goto END;//c'est plus propre
          }
        }break;
      }
    }
  }
  END:
  return tmpbat;*/
}
/**
* \fn char Tirer(char player_number, unsigned int x, unsigned int y);
* \brief Fonction de verification de si ont a toucher un bateau sur la grille adversse
*
* \param \enum char player_number : identifiant du joueur
*\enum unsigned int x , y : corrdonners du tire
*\return Un char valant:
*\enum 0 si on a rien toucher
*\enum 1 si ont a toucher un bateau adverse
*\enum 2 si on a toucher et couler un bateau adversse
*/
char Partie::Tirer(unsigned int pn ,unsigned int x, unsigned int y,char typetire,Bateau* tireur){
  Bateau *bat;
  unsigned int s;
  if((x<15)&&(y<15)){
    //blindage
  if(tabj[pn][1][x][y]!=' '){
    //nous avons un bateau - maintenant il faut le trouver
  bat=get_Bateau(x,y,pn);
  s=bat->get_taille();
  switch(bat->get_orientation()){
    case 'h': bat->set_etat(y-bat->get_py());
    break;
    case 'v': bat->set_etat(x-bat->get_px());
    break;
  }
  return bat->is_dead()? 2:1;
  }
  #ifdef DEBUG
  std::cout << "Partie::Tirer : Rien toucher";
  #endif //DEBUG
return 0;
}
std::cerr<<"Erreur : Partie::Tirer nous somme en dehord de la taille du tableau";
return 0; //erreur

return 0;}

//recupere la selection du joueur sur la grille adverse
std::pair<Bateau*,std::pair<unsigned int , unsigned  int >> Partie::select_grille()
{

}