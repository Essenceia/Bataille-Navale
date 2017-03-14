#include "Sousmarin.h"

Sousmarin::Sousmarin(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)
{
    for(int i=0;i<taille;i++) etat[i]=true;
    existe=true;
}

Sousmarin::~Sousmarin()
{

}


///Methodes
char Sousmarin::Symbole()
{
    return '♠';
}

void Sousmarin::Deplacement()
{

}
void Sousmarin::Tourner()
{

}
void Sousmarin::Tirer()
{

}
