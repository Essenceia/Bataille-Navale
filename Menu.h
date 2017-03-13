#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Allegro.h"

class Menu
{
    private :
        //Attributs
        int m_choix;
        bool m_principal;
        bool m_regles;
        bool m_option;

        // Bitmaps
        BITMAP* buffer;
        BITMAP* menu_principal;
        BITMAP* menu_option;
        BITMAP* menu_regles;
        BITMAP* txt_un_joueur;
        BITMAP* txt_deux_joueur;
        BITMAP* txt_option;
        BITMAP* txt_regles;
        BITMAP* txt_quitter;
        BITMAP* txt_retour;
        BITMAP* txt_hover_un_joueur;
        BITMAP* txt_hover_deux_joueur;
        BITMAP* txt_hover_option;
        BITMAP* txt_hover_regles;
        BITMAP* txt_hover_quitter;
        BITMAP* txt_hover_retour;

    public :
        //Constructeur
        Menu();

        //Destructeur
        ~Menu();

        //Methodes
        void load_bitmaps();
        void principal();
        void regles();
        void option();
        void destroy_bitmaps();
};

#endif // MENU_H_INCLUDED
