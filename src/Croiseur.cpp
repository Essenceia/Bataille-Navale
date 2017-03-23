#include "../lib/Croiseur.h"

Croiseur::Croiseur(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation)
{

}

Croiseur::~Croiseur()
{

}


///Methodes
char Croiseur::Symbole()
{
    return 'c';
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
