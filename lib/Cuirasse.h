#ifndef CUIRASSE_H_INCLUDED
#define CUIRASSE_H_INCLUDED

#include "Bateau.h"

class Cuirasse:public Bateau
{
    private :

    bool cooldown; //tour d'attente lors du mouvement d'un cuirass�

    public :

    Cuirasse(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation);
    ~Cuirasse();

    //methodes
    bool get_cd();
    char Symbole();
    bool get_fusee();
    void set_fusee();
    void set_cd();

};

#endif // CUIRASSE_H_INCLUDED
