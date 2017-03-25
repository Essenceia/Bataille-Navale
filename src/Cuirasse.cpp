#include "../lib/Cuirasse.h"
Cuirasse::Cuirasse(unsigned int x,unsigned  int y, unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), cooldown(false)
{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
    arme = new Tire(SYMBOL_CUIRASSER);

}

Cuirasse::~Cuirasse()
{

}


///Methodes
char Cuirasse::Symbole()
{
    return (char)SYMBOL_CUIRASSER;

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
