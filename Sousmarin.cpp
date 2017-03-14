#include "Sousmarin.h"

Sousmarin::Sousmarin(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), existe(1)
{
    for(i=0;i<taille;i++) etat[i]=true;
}

Sousmarin::~Sousmarin()
{

}


///Methodes
char Croiseur::Symbole()
{
    return '♠'
}
