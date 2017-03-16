#include "../lib/Partie.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>
#include "../lib/Helper.h"
// contructeur par default
Partie::Partie():alleg_present(false)
{
    ///INITIALISER LES VECTEURS ICI
    //resize des vecteurs
    tabj.resize(2);
    tabj.resize(2);
    for(unsigned int p=0; p < NOMBREJOUEUR ; p++){
    for(int i=0;i<2;i++){
      tabj[p][i].resize(15);
      tabj[p][i].resize(15);
        for(int j=0;j<14;j++){
          tabj[p][i][j].resize(15);
          tabj[p][i][j].resize(15);
            for(int k=0;k<14;k++){
                tabj[p][i][j][k]=' ';
                tabj[p][i][j][k]=' ';
            }}}}

    battab[0].push_back(new Cuirasse(0,0,7,'h'));
    battab[0].push_back(new Croiseur(0,0,5,'h'));
    battab[0].push_back(new Croiseur(0,0,5,'h'));
    battab[0].push_back(new Destroyer(0,0,3,'h'));
    battab[0].push_back(new Destroyer(0,0,3,'h'));
    battab[0].push_back(new Destroyer(0,0,3,'h'));
    battab[0].push_back(new Sousmarin(0,0,1,'h'));
    battab[0].push_back(new Sousmarin(0,0,1,'h'));
    battab[0].push_back(new Sousmarin(0,0,1,'h'));
    battab[0].push_back(new Sousmarin(0,0,1,'h'));

    battab[1].push_back(new Cuirasse(0,0,7,'h'));
    battab[1].push_back(new Croiseur(0,0,5,'h'));
    battab[1].push_back(new Croiseur(0,0,5,'h'));
    battab[1].push_back(new Destroyer(0,0,3,'h'));
    battab[1].push_back(new Destroyer(0,0,3,'h'));
    battab[1].push_back(new Destroyer(0,0,3,'h'));
    battab[1].push_back(new Sousmarin(0,0,1,'h'));
    battab[1].push_back(new Sousmarin(0,0,1,'h'));
    battab[1].push_back(new Sousmarin(0,0,1,'h'));
    battab[1].push_back(new Sousmarin(0,0,1,'h'));
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

    path = "Sauvegardes/";
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
    std::string path = "Sauvegardes/";
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

void Partie::LancerPartie()
{
#ifdef USINGALLEGRO
    ///BOUCLE DE JEU
    while (!key[KEY_ESC])
    {

    }
#endif //USIINGALLEGRO
}

void Partie::setal(bool al)
{
    alleg_present=al;
}

void Partie::ConsPrint(unsigned int y,unsigned int x)
{
  #ifdef COORD
    COORD xy;
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );
    #endif
}

void Partie::ChargerImages()
{
  #ifdef USINGALLEGRO
    alleg.ChargerImages();
  #endif//USINGALLEGRO
}

void Partie::DestroyImages()
{
  #ifdef USINGALLEGRO
    alleg.DestroyImages();
    #endif //USINGALLEGRO
}

void Partie::resetpartie()//Gros reset pour remettre la partie à 0 à la fin de celle ci ou au retour au menu
{

}

void Partie::initPartie()//Initialisation avec le placement des bateaux surtout
{

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
  if(ptotab[pn][x][y]!=' '){
    //nous avons un bateau - maintenant il faut le trouver
  bat=get_Bateau(x,y,pn);
  s=bat.get_taille();
  switch(bat.get_orientation()){
    case 'h': bat.set_etat(y-bat.get_py());
    break;
    case 'v': bat.set_etat(x-bat.get_px());
    break;
    case 'b': bat.set_etat(abs(x-bat.get_px()));
    break;
    case 'g': bat.set_etat(abs(y-bat.get_px()));
    break;
  }
  return ?(bat.is_dead()) 2:1;
  }
  #ifdef DEBUG
  std::cout << "Partie::Tirer : Rien toucher";
  #endif //DEBUG
return 0;
}
std::cerr<<"Erreur : Partie::Tirer nous somme en dehord de la taille du tableau";
return 0; //erreur

return 0;}
