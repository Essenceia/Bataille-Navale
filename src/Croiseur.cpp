#include "../lib/Croiseur.h"

Croiseur::Croiseur(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation)
        : Bateau(_x,_y,_taille,_orientation)
{

    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
    arme = new Tire(SYMBOL_CROISEUR);
}

Croiseur::~Croiseur()
{

}


///Methodes

char Croiseur::Symbole() {
    return (char)SYMBOL_CROISEUR;
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
