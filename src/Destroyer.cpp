#include "../lib/Destroyer.h"

Destroyer::Destroyer(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation), munition_fusee(true)
{

}

Destroyer::~Destroyer()
{

}


///Methodes
char Destroyer::Symbole()
{
    return 'd';
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
