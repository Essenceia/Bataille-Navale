#include "Partie.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>

// contructeur par default
Partie::Partie()
    : alleg_present(false)
{
    ///INITIALISER LES VECTEURS ICI
    for(int i=0;i<2;i++)
        for(int j=0;j<14;j++)
            for(int k=0;k<14;k++){
                tabj1[i][j][k]=' ';
                tabj2[i][j][k]=' ';
            }

    battab1.push_back(new Cuirasse(0,0,7,'h'));
    battab1.push_back(new Croiseur(0,0,5,'h'));
    battab1.push_back(new Croiseur(0,0,5,'h'));
    battab1.push_back(new Destroyer(0,0,3,'h'));
    battab1.push_back(new Destroyer(0,0,3,'h'));
    battab1.push_back(new Destroyer(0,0,3,'h'));
    battab1.push_back(new Sousmarin(0,0,1,'h'));
    battab1.push_back(new Sousmarin(0,0,1,'h'));
    battab1.push_back(new Sousmarin(0,0,1,'h'));
    battab1.push_back(new Sousmarin(0,0,1,'h'));

    battab2.push_back(new Cuirasse(0,0,7,'h'));
    battab2.push_back(new Croiseur(0,0,5,'h'));
    battab2.push_back(new Croiseur(0,0,5,'h'));
    battab2.push_back(new Destroyer(0,0,3,'h'));
    battab2.push_back(new Destroyer(0,0,3,'h'));
    battab2.push_back(new Destroyer(0,0,3,'h'));
    battab2.push_back(new Sousmarin(0,0,1,'h'));
    battab2.push_back(new Sousmarin(0,0,1,'h'));
    battab2.push_back(new Sousmarin(0,0,1,'h'));
    battab2.push_back(new Sousmarin(0,0,1,'h'));
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
    // affichage du tabeau numtab
    //(selon le fait qu'il soit le premier ou le second tableau et surtout qu'il soit celui que le joueur peut voir ou pas)

}
void Partie::changer_val_tableau(int numtab, int coordonees_x, int coordonees_y, char newval)
{
    //Changer la valeure d'un des deux tableau
}


/// Chargement
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
    ///BOUCLE DE JEU
    while (!key[KEY_ESC])
    {

    }
}

void Partie::setal(bool al)
{
    alleg_present=al;
}

void Partie::ConsPrint(int y, int x)
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

}
