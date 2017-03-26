#ifndef DESTROYER_H_INCLUDED
#define DESTROYER_H_INCLUDED

#include "Bateau.h"

class Destroyer:public Bateau
{

    private :

    bool munition_fusee;

    public :

    Destroyer(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation);
    ~Destroyer();

    //methodes
    bool get_fusee();
    bool get_cd();

    void set_fusee();
    void set_cd();
};

#endif // DESTROYER_H_INCLUDED
