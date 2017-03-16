#ifndef DESTROYER_H_INCLUDED
#define DESTROYER_H_INCLUDED

#include "Bateau.h"

class Destroyer:public Bateau
{

    private :

    bool munition_fusee;

    public :

    Destroyer(unsigned int x,unsigned int y,unsigned int _taille, char _orientation);
    ~Destroyer();

    //methodes
    void Deplacement();
    void Tourner();
    void Tirer();
    char Symbole();

};

#endif // DESTROYER_H_INCLUDED
