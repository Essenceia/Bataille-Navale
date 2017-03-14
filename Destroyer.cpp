#include "Destroyer.h"

Destroyer::Destroyer(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), existe(1), munition_fusee(true)
{
    for(i=0;i<taille;i++) etat[i]=true;
}

Destroyer::~Destroyer()
{

}


///Methodes
char Croiseur::Symbole()
{
    return '♦'
}
