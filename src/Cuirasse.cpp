#include "../lib/Cuirasse.h"

Cuirasse::Cuirasse(int x, int y, int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), cooldown(false)
{
    for(int i=0;i<taille;i++) etat[i]=true;
    existe=true;
}

Cuirasse::~Cuirasse()
{

}


///Methodes
char Cuirasse::Symbole()
{
    return '♣';
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
