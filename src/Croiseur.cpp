#include "../lib/Croiseur.h"

Croiseur::Croiseur(unsigned int x,unsigned int y,unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)
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
