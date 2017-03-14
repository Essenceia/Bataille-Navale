#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>

// classe abstraite Objet
class Objet
{
    protected :

        int pos_x;
        int pos_y;
        int taille;

    public :

        Objet(int x, int y);// constructeur par surcharge
        virtual ~Objet(); // destructeur


        //getters
        int get_px();
        int get_py();
        int get_taille();


};

#endif // OBJET_H_INCLUDED
