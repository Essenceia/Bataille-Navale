#include "../lib/Sousmarin.h"
#include "../lib/Tire.h"
Sousmarin::Sousmarin(unsigned int x, unsigned int y,unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation)

{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
    arme = new Tire(SYMBOL_SOUSMARIN);
}

Sousmarin::~Sousmarin()
{

}


///Methodes
char Sousmarin::Symbole()
{
    return (char)SYMBOL_SOUSMARIN;
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
