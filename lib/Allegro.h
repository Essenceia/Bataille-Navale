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
        BITMAP *tampon;
        BITMAP *tampon2;

        // Images
        BITMAP *fond;
        BITMAP *victoire;
        BITMAP *defaite;
        BITMAP *selun;
        BITMAP *seldeux;
        BITMAP *seltrois;
        BITMAP *selquatre;
        BITMAP *bout;
        BITMAP *corps;
        BITMAP *sousmarin;
        BITMAP *boum;
        BITMAP *epave;
        BITMAP *repere;
        BITMAP *choixaction;
        BITMAP *mauvais;
        BITMAP *nopivot;
        BITMAP *chgmnt;

    public :

        //Constructors and destructors
        Allegro();
        ~Allegro();

        //methodes
        void ChargerImages();
        void DestroyImages();

        void clearbmp();


        //Getters et Setters
        BITMAP* getImage(int i);


};


#endif // ALLEGRO_H_INCLUDED
