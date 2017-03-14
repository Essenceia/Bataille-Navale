#include "Croiseur.h"

Croiseur::Croiseur(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)
{
    for(int i=0;i<taille;i++) etat[i]=true;
    existe=true;
}

Croiseur::~Croiseur()
{

}


///Methodes
char Croiseur::Symbole()
{
    return '♥';
}

void Croiseur::Deplacement()
{

}
void Croiseur::Tourner()
{

}
void Croiseur::Tirer()
{

}
