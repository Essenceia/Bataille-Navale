#include "../lib/Cuirasse.h"

Cuirasse::Cuirasse(unsigned int x,unsigned  int y, unsigned int _taille, char _orientation)
        : Bateau(x,y,_taille,_orientation), cooldown(false)
{
    for(unsigned int i=0;i<taille;i++) etat[i]->touche=false;
}

Cuirasse::~Cuirasse()
{

}


///Methodes
char Cuirasse::Symbole()
{
    return 'C';

}

bool Cuirasse::get_cd()
{
    return cooldown;
}

bool Cuirasse::get_fusee()
{
    return false;
}


void Cuirasse::set_fusee()
{

}

void Cuirasse::set_cd()
{
    if(cooldown) cooldown=false;
    else cooldown=true;
}
