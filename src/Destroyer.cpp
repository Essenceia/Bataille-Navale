#include "../lib/Destroyer.h"

Destroyer::Destroyer(unsigned int x,unsigned int y,unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), munition_fusee(true)
{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
}

Destroyer::~Destroyer()
{

}


///Methodes
char Destroyer::Symbole()
{
    return '♦';
}

void Destroyer::Deplacement()
{

}
void Destroyer::Tourner()
{

}
void Destroyer::Tirer()
{

}
