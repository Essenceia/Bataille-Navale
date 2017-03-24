#ifndef ALLEGRO_H_INCLUDED
#define ALLEGRO_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <allegro.h>
#ifdef WINDOWS
#include <winalleg.h>
#endif
class Allegro
{
    private :

        // BITMAP buffer d'affichage
        BITMAP *page;

        // Images
        BITMAP *fond;
        BITMAP *victoire;
        BITMAP *defaite;
        BITMAP *selun;
        BITMAP *seldeux;
        BITMAP *seltrois;
        BITMAP *bout;
        BITMAP *corps;
        BITMAP *sousmarin;
        BITMAP *boum;
        BITMAP *epave;
        BITMAP *repere;
        BITMAP *choixaction;
        BITMAP *mauvais;

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
