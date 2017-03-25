#ifndef SOUSMARIN_H_INCLUDED
#define SOUSMARIN_H_INCLUDED

#include "Bateau.h"

class Sousmarin:public Bateau
{

    public :

    Sousmarin(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation);
    ~Sousmarin();

    //methodes
    char Symbole();
    bool get_fusee();
    bool get_cd();
    void set_fusee();
    void set_cd();

};

#endif // SOUSMARIN_H_INCLUDED
