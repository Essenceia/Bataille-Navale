#include "../lib/Cuirasse.h"

Cuirasse::Cuirasse(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation), cooldown(false)
{

}

Cuirasse::~Cuirasse()
{

}


///Methodes
char Cuirasse::Symbole()
{
    return 'p';
}

void Cuirasse::Deplacement()
{

}
void Cuirasse::Tourner()
{

}
void Cuirasse::Tirer()
{

}
