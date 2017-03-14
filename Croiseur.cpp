#include "Croiseur.h"

Croiseur::Croiseur(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), existe(1)
{
    for(i=0;i<taille;i++) etat[i]=true;
}

Croiseur::~Croiseur()
{

}


///Methodes
char Croiseur::Symbole()
{
    return '♥'
}
