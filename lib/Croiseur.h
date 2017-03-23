#ifndef CROISEUR_H_INCLUDED
#define CROISEUR_H_INCLUDED

#include "Bateau.h"

class Croiseur:public Bateau
{

    public :

    Croiseur(unsigned int _x,unsigned  int _y, unsigned int _taille, char _orientation);
    ~Croiseur();

    //methodes
    void Deplacement();
    void Tourner();
    void Tirer();
    char Symbole();

};

#endif // CROISEUR_H_INCLUDED
