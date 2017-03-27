#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include "Allegro.h"
#include "Partie.h"

class Menu
{
    private :
        //Attributs
        bool m_exit;
        unsigned int allegro_present;

        Partie partie;
        // Bitmaps
        BITMAP* buffer;
        BITMAP* menu_principal;
        BITMAP* menu_regles;
        BITMAP* txt_un_joueur;
        BITMAP* txt_deux_joueur;
        BITMAP* txt_charger;
        BITMAP* txt_regles;
        BITMAP* txt_quitter;
        BITMAP* txt_retour;
        BITMAP* txt_hover_un_joueur;
        BITMAP* txt_hover_deux_joueur;
        BITMAP* txt_hover_regles;
        BITMAP* txt_hover_charger;
        BITMAP* txt_hover_quitter;
        BITMAP* txt_hover_retour;
        BITMAP* Al1;
        BITMAP* Al2;

        SAMPLE * Al;

    public :
        //Constructeur
        Menu();

        //Destructeur
        ~Menu();

        //Methodes
        void halaygreau();
        void Allegro_present();
        unsigned int getallegro_present();

        void load_bitmaps();
        void principal();
        void regles();
        void destroy_bitmaps();
        void destroy_wav();
};


#endif
