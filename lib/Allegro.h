#ifdef USINGALLEGRO
#ifndef ALLEGRO_H_INCLUDED
#define ALLEGRO_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <allegro.h>
#include <winalleg.h>

class Allegro
{
    private :

        // BITMAP buffer d'affichage
        BITMAP *page;

        // Images
        BITMAP *fond;
        BITMAP *victoire;
        BITMAP *defaite;

    public :

        //Constructors and destructors
        Allegro();
        ~Allegro();

        //methodes
        void ChargerImages();
        void DestroyImages();


        //Getters et Setters
        BITMAP* getImage(int i);


};


#endif // ALLEGRO_H_INCLUDED
#endif // USINGALLEGRO
