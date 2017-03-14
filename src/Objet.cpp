#include "../lib/Objet.h"

//Constructeur
Objet::Objet(int x, int y)
      :pos_x(x), pos_y(y)
{

}

//Destructeur
Objet::~Objet()
{

}

//getters
int Objet::get_px()
{
    return pos_x;
}
int Objet::get_py()
{
    return pos_y;
}
int Objet::get_taille()
{
    return taille;
}
