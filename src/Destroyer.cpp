#include "../lib/Destroyer.h"

Destroyer::Destroyer(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation), munition_fusee(true)
{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
    arme = new Tire(SYMBOL_DESTROYER);

}

Destroyer::~Destroyer()
{

}


///Methodes
char Destroyer::Symbole()
{
    return (char)SYMBOL_DESTROYER;

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
