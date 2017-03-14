#ifndef SOUSMARIN_H_INCLUDED
#define SOUSMARIN_H_INCLUDED

#include "Bateau.h"

class Sousmarin:public Bateau
{

    public :

    Sousmarin(int x, int y, int _taille, char _orientation);
    ~Sousmarin();

    //methodes
    void Deplacement();
    void Tourner();
    void Tirer();
    char Symbole();

};

#endif // SOUSMARIN_H_INCLUDED
