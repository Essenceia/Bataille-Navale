#ifndef CROISEUR_H_INCLUDED
#define CROISEUR_H_INCLUDED

#include "Bateau.h"

class Croiseur:public Bateau
{

    public :

    Croiseur(int x, int y, int _taille, char _orientation);
    ~Croiseur();

    //methodes
    void Deplacement();
    void Tourner();
    void Tirer();
    char Symbole();

};

#endif // CROISEUR_H_INCLUDED
