#include "../lib/Sousmarin.h"

Sousmarin::Sousmarin(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation)
{

}

Sousmarin::~Sousmarin()
{

}


///Methodes
char Sousmarin::Symbole()
{
    return 's';
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
