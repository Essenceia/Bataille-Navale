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
        bool allegro_present;

        Partie partie;
        // Bitmaps
        BITMAP* buffer;
        BITMAP* menu_principal;
        BITMAP* menu_option;
        BITMAP* menu_regles;
        BITMAP* menu_charger;
        BITMAP* txt_un_joueur;
        BITMAP* txt_deux_joueur;
        BITMAP* txt_option;
        BITMAP* txt_charger;
        BITMAP* txt_regles;
        BITMAP* txt_quitter;
        BITMAP* txt_retour;
        BITMAP* txt_hover_un_joueur;
        BITMAP* txt_hover_deux_joueur;
        BITMAP* txt_hover_option;
        BITMAP* txt_hover_regles;
        BITMAP* txt_hover_charger;
        BITMAP* txt_hover_quitter;
        BITMAP* txt_hover_retour;
    public :
        //Constructeur
        Menu();

        //Destructeur
        ~Menu();

        //Methodes
        void Allegro_present();
        bool getallegro_present();

        void load_bitmaps();
        void principal();
        void regles();
        void option();
        void charger();
        void destroy_bitmaps();
};


#endif
