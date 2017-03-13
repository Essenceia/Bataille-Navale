#include "Menu.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "Allegro.h"

// contructeur par default
Menu::Menu()
    : m_choix(0), m_principal(false), m_regles(false), m_option(false)
{

}

// Allegro.hteur
Menu::~Menu()
{

}

// getteurs et setteurs

/// Méthodes

void Menu::load_bitmaps() // Charger images
{
    buffer = create_bitmap(SCREEN_W, SCREEN_H); // Création buffer

    menu_principal=load_bitmap("Bitmap/Menu/menu_principal.bmp",NULL);
    if (!menu_principal)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_principal.bmp");
        exit(EXIT_FAILURE);
    }
    menu_option=load_bitmap("Bitmap/Menu/menu_option.bmp",NULL);
    if (!menu_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_option.bmp");
        exit(EXIT_FAILURE);
    }
    menu_regles=load_bitmap("Bitmap/Menu/menu_regles.bmp",NULL);
    if (!menu_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_regles.bmp");
        exit(EXIT_FAILURE);
    }
    txt_un_joueur=load_bitmap("Bitmap/Menu/txt_un_joueur.bmp",NULL);
    if (!txt_un_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_un_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_deux_joueur=load_bitmap("Bitmap/Menu/txt_deux_joueur.bmp",NULL);
    if (!txt_deux_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_deux_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_option=load_bitmap("Bitmap/Menu/txt_option.bmp",NULL);
    if (!txt_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_option.bmp");
        exit(EXIT_FAILURE);
    }
    txt_regles=load_bitmap("Bitmap/Menu/txt_regles.bmp",NULL);
    if (!txt_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_regles.bmp");
        exit(EXIT_FAILURE);
    }
    txt_quitter=load_bitmap("Bitmap/Menu/txt_quitter.bmp",NULL);
    if (!txt_quitter)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_quitter.bmp");
        exit(EXIT_FAILURE);
    }
    txt_retour=load_bitmap("Bitmap/Menu/txt_retour.bmp",NULL);
    if (!txt_retour)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_retour.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_un_joueur=load_bitmap("Bitmap/Menu/txt_hover_un_joueur.bmp",NULL);
    if (!txt_hover_un_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_un_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_deux_joueur=load_bitmap("Bitmap/Menu/txt_hover_deux_joueur.bmp",NULL);
    if (!txt_hover_deux_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_deux_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_option=load_bitmap("Bitmap/Menu/txt_hover_option.bmp",NULL);
    if (!txt_hover_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_option.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_regles=load_bitmap("Bitmap/Menu/txt_hover_regles.bmp",NULL);
    if (!txt_hover_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_regles.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_quitter=load_bitmap("Bitmap/Menu/txt_hover_quitter.bmp",NULL);
    if (!txt_hover_quitter)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_quitter.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_retour=load_bitmap("Bitmap/Menu/txt_hover_retour.bmp",NULL);
    if (!txt_hover_retour)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_retour.bmp");
        exit(EXIT_FAILURE);
    }
}

// Menu principal
void Menu::principal()
{
    // Réinitialisation du booléen m_principal
    m_principal = false;

    int x= mouse_x;
    int y= mouse_y;

    system("cls");

    while( m_principal == false )
    {
        // réinitilisation des coordonnées souris
        x= mouse_x;
        y= mouse_y;

        // Affichage du menu_principal
        clear_bitmap(buffer);
        blit(menu_principal, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
        blit(txt_un_joueur,buffer,0,0,50,50,SCREEN_W,SCREEN_H);
        blit(txt_deux_joueur,buffer,0,0,50,120,SCREEN_W,SCREEN_H);
        blit(txt_option,buffer,0,0,50,230,SCREEN_W,SCREEN_H);
        blit(txt_regles,buffer,0,0,50,300,SCREEN_W,SCREEN_H);
        blit(txt_quitter,buffer,0,0,600,500,SCREEN_W,SCREEN_H);

        /// "1J"
        //si la souris se trouve sur "RETOUR"
        if( x>=50 && x<=200 && y>=50 && y<=100 )
        {
            blit(txt_hover_un_joueur,buffer,0,0,50,50,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {

            }
        }

        /// "2J"
        //si la souris se trouve sur "RETOUR"
        if( x>=50 && x<=200 && y>=120 && y<=170 )
        {
            blit(txt_hover_deux_joueur,buffer,0,0,50,120,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {

            }
        }

        /// "OPTION"
        //si la souris se trouve sur "RETOUR"
        if( x>=50 && x<=200 && y>=230 && y<=280 )
        {
            blit(txt_hover_option,buffer,0,0,50,230,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {
                option();
            }
        }

        /// "REGLE"
        //si la souris se trouve sur "RETOUR"
        if( x>=50 && x<=200 && y>=300 && y<=350 )
        {
            blit(txt_hover_regles,buffer,0,0,50,300,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {
                regles();
            }
        }

        /// "QUITTER"
        //si la souris se trouve sur "RETOUR"
        if( x>=600 && x<=750 && y>=500 && y<=550 )
        {
            blit(txt_hover_quitter,buffer,0,0,600,500,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {
                // retour au menu principal
                m_principal = true;
            }
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100); //pause pour qu'il soit visible
    }


}

// Menu option
void Menu::option()
{
    // Réinitialisation du booléen m_option
    m_option = false;

    int x= mouse_x;
    int y= mouse_y;

    system("cls");

    while( m_option == false )
    {
        // réinitilisation des coordonnées souris
        x= mouse_x;
        y= mouse_y;

        // Affichage du menu_option
        clear_bitmap(buffer);
        blit(menu_option, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
        blit(txt_retour,buffer,0,0,600,500,SCREEN_W,SCREEN_H);

        /// "RETOUR"
        //si la souris se trouve sur "RETOUR"
        if( x>=600 && x<=750 && y>=500 && y<=550 )
        {
            blit(txt_hover_retour,buffer,0,0,600,500,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {
                // retour au menu principal
                m_option = true;
            }
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100); //pause pour qu'il soit visible
    }


}

// Menu règles
void Menu::regles()
{
    // Réinitialisation du booléen m_regles
    m_regles = false;

    int x= mouse_x;
    int y= mouse_y;

    system("cls");

    while( m_regles == false )
    {
        // réinitilisation des coordonnées souris
        x= mouse_x;
        y= mouse_y;

        // Affichage du menu_regles
        clear_bitmap(buffer);
        blit(menu_regles, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
        blit(txt_retour,buffer,0,0,600,500,SCREEN_W,SCREEN_H);

        /// "RETOUR"
        //si la souris se trouve sur "RETOUR"
        if( x>=600 && x<=750 && y>=500 && y<=550 )
        {
            blit(txt_hover_retour,buffer,0,0,600,500,SCREEN_W,SCREEN_H);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // si clique gauche
            if ( mouse_b & 1 )
            {
                // retour au menu principal
                m_regles = true;
            }
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100); //pause pour qu'il soit visible
    }


}

void Menu::destroy_bitmaps() //Détruit les bitmaps
{
    destroy_bitmap(buffer);
    destroy_bitmap(menu_principal);
    destroy_bitmap(menu_option);
    destroy_bitmap(menu_regles);
    destroy_bitmap(txt_un_joueur);
    destroy_bitmap(txt_deux_joueur);
    destroy_bitmap(txt_option);
    destroy_bitmap(txt_regles);
    destroy_bitmap(txt_quitter);
    destroy_bitmap(txt_retour);
    destroy_bitmap(txt_hover_un_joueur);
    destroy_bitmap(txt_hover_deux_joueur);
    destroy_bitmap(txt_hover_option);
    destroy_bitmap(txt_hover_regles);
    destroy_bitmap(txt_hover_quitter);
    destroy_bitmap(txt_hover_retour);
}
