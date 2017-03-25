#include "../lib/Croiseur.h"

Croiseur::Croiseur(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation)
{

    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
}

Croiseur::~Croiseur()
{

}


///Methodes

char Croiseur::Symbole() {
    return 'c';
}

bool Croiseur::get_fusee()
{
    return false;
}

bool Croiseur::get_cd()
{
    return false;
}

void Croiseur::set_fusee()
{

}

void Croiseur::set_cd()
{

}

