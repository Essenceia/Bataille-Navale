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

void Partie::affichageAlleg(){

}

void Partie::affichageCons(){

}

void Partie::LancerPartie()
{

    initPartie();

    std::string num;
    bool exitboucle = false;
    ///BOUCLE DE JEU
    while (!exitboucle)
    {
        //Reset affichage
        if (alleg_present==1)  blit(alleg.getImage(1),alleg.getImage(0),0,0,0,0,SCREEN_W,SCREEN_H);
        else system("cls");

        //Premier affichage
        if (alleg_present==1)  affichageAlleg();
        else affichageCons();

        //Commandes
        if (alleg_present==1) {

            //Clic sur les endroits



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

void Partie::resetpartie()//Gros reset pour remettre la partie à 0 à la fin de celle ci ou au retour au menu
{

}

void Partie::initPartie()//Initialisation avec le placement des bateaux surtout
{

    ///IL FAUT CLEAR LES VECTEURS ET VIRER LES CASES EN FAISANT ATTENTION AU FAIT QUE CE SOIT DES POINTEURS

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
                    for(unsigned int numbat=0;numbat<j;numbat++)
                        for(unsigned int taille=0;taille<battab[i][numbat]->get_taille();taille++)
                            if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
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
                    for(unsigned int numbat=0;numbat<j;numbat++)
                        for(unsigned int taille=0;taille<battab[i][numbat]->get_taille();taille++)
                            if( battab[i][numbat]->get_etatx(taille)==xrand && battab[i][numbat]->get_etaty(taille)==yrand ) ok=false;
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
