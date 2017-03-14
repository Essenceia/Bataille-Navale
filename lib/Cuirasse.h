#ifndef CUIRASSE_H_INCLUDED
#define CUIRASSE_H_INCLUDED

#include "Bateau.h"

class Cuirasse:public Bateau
{
    private :

    bool cooldown; //tour d'attente lors du mouvement d'un cuirassé

    public :

    Cuirasse(int x, int y, int _taille, char _orientation);
    ~Cuirasse();

    //methodes
    void Deplacement();
    void Tourner();
    void Tirer();
    char Symbole();

};

#endif // CUIRASSE_H_INCLUDED
