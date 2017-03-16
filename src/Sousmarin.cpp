#include "../lib/Sousmarin.h"

Sousmarin::Sousmarin(unsigned int x, unsigned int y,unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)
{
    for(unsigned int i=0;i<taille;i++) etat[i]=true;
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
