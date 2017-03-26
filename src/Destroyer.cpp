#include "../lib/Destroyer.h"

Destroyer::Destroyer(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation), munition_fusee(true)
{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;

}

Destroyer::~Destroyer()
{

}


///Methodes

bool Destroyer::get_fusee()
{
    return munition_fusee;
}

bool Destroyer::get_cd()
{
    return false;
}


void Destroyer::set_fusee()
{
    munition_fusee=false;
}

void Destroyer::set_cd()
{

}
