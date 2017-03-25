#include "../lib/Sousmarin.h"
#include "../lib/Tire.h"
Sousmarin::Sousmarin(unsigned int x, unsigned int y,unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)

{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
}

Sousmarin::~Sousmarin()
{

}


///Methodes
char Sousmarin::Symbole()
{
    return 's';

}

bool Sousmarin::get_fusee()
{
    return false;
}

bool Sousmarin::get_cd()
{
    return false;
}


void Sousmarin::set_fusee()
{

}

void Sousmarin::set_cd()
{

}
