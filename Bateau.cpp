#include "Bateau.h"

//Constructeur
Bateau::Bateau(int x, int y, int _taille, char _orientation)
      :pos_x(x), pos_y(y), taille(_taille), orientation(_orientation)
{

}

//Destructeur
Bateau::~Bateau()
{

}

//getters
int Bateau::get_px()
{
    return pos_x;
}
int Bateau::get_py()
{
    return pos_y;
}
bool Bateau::get_existe()
{
    return existe;
}
int Bateau::get_taille()
{
    return taille;
}
char Bateau::get_orientation()
{
    return orientation;
}
bool Bateau::get_etat(int pos)
{
    return etat[pos];
}
