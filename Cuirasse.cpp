#include "Cuirasse.h"

Cuirasse::Cuirasse(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), existe(1), cooldown(false)
{
    for(i=0;i<taille;i++) etat[i]=true;
}

Cuirasse::~Cuirasse()
{

}


///Methodes
char Croiseur::Symbole()
{
    return '♣'
}
