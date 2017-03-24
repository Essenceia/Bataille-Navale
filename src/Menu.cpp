#include "../lib/Menu.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "../lib/crossplatform.h"
// contructeur par default
Menu::Menu()
    : m_exit(false), allegro_present(false)
{

}

// Allegro.hteur
Menu::~Menu()
{

}

// getteurs et setteurs

/// M�thodes
void Menu::Allegro_present()
{
    //Sur console
    clear_window(); // nettoie la console
    int int_allegro_present = 0;
    partie.ConsPrint(1,13);
    std::cout << "Bataille Navale";
    partie.ConsPrint(3,0);
    std::cout << "Voulez vous jouer avec ou sans Allegro?" <<std::endl
              << "0. sans" <<std::endl
              << "1. avec" <<std::endl;
    partie.ConsPrint(10,5);
    std::cout << "Choix : ";

    std::cin>> int_allegro_present;

    if(int_allegro_present!=0&&int_allegro_present!=1)
    {
        std::cout << std::endl << "Bravo nous esperons que tu es content de faire n'importe quoi, pour la peine tu ne joueras pas!";
        exit(0);
    }

    if(int_allegro_present==0)  allegro_present=false;
    else  allegro_present=true;

    partie.setal(allegro_present);

}

bool Menu::getallegro_present()
{
    return allegro_present;
}

void Menu::load_bitmaps() // Charger images
{
    buffer = create_bitmap(SCREEN_W, SCREEN_H); // Cr�ation buffer

    menu_principal=load_bitmap("../Bitmap/Menu/menu_principal.bmp",NULL);
    if (!menu_principal)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_principal.bmp");
        exit(EXIT_FAILURE);
    }
    menu_option=load_bitmap("../Bitmap/Menu/menu_option.bmp",NULL);
    if (!menu_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_option.bmp");
        exit(EXIT_FAILURE);
    }
    menu_regles=load_bitmap("../Bitmap/Menu/menu_regles.bmp",NULL);
    if (!menu_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_regles.bmp");
        exit(EXIT_FAILURE);
    }
    menu_charger=load_bitmap("../Bitmap/Menu/menu_charger.bmp",NULL);
    if (!menu_charger)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_charger.bmp");
        exit(EXIT_FAILURE);
    }
    txt_un_joueur=load_bitmap("../Bitmap/Menu/txt_un_joueur.bmp",NULL);
    if (!txt_un_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_un_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_deux_joueur=load_bitmap("../Bitmap/Menu/txt_deux_joueur.bmp",NULL);
    if (!txt_deux_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_deux_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_option=load_bitmap("../Bitmap/Menu/txt_option.bmp",NULL);
    if (!txt_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_option.bmp");
        exit(EXIT_FAILURE);
    }
    txt_charger=load_bitmap("../Bitmap/Menu/txt_charger.bmp",NULL);
    if (!txt_charger)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_charger.bmp");
        exit(EXIT_FAILURE);
    }
    txt_regles=load_bitmap("../Bitmap/Menu/txt_regles.bmp",NULL);
    if (!txt_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_regles.bmp");
        exit(EXIT_FAILURE);
    }
    txt_quitter=load_bitmap("../Bitmap/Menu/txt_quitter.bmp",NULL);
    if (!txt_quitter)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_quitter.bmp");
        exit(EXIT_FAILURE);
    }
    txt_retour=load_bitmap("../Bitmap/Menu/txt_retour.bmp",NULL);
    if (!txt_retour)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_retour.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_un_joueur=load_bitmap("../Bitmap/Menu/txt_hover_un_joueur.bmp",NULL);
    if (!txt_hover_un_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_un_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_deux_joueur=load_bitmap("../Bitmap/Menu/txt_hover_deux_joueur.bmp",NULL);
    if (!txt_hover_deux_joueur)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_deux_joueur.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_option=load_bitmap("../Bitmap/Menu/txt_hover_option.bmp",NULL);
    if (!txt_hover_option)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_option.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_charger=load_bitmap("../Bitmap/Menu/txt_hover_charger.bmp",NULL);
    if (!txt_hover_charger)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_charger.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_regles=load_bitmap("../Bitmap/Menu/txt_hover_regles.bmp",NULL);
    if (!txt_hover_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_regles.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_quitter=load_bitmap("../Bitmap/Menu/txt_hover_quitter.bmp",NULL);
    if (!txt_hover_quitter)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_quitter.bmp");
        exit(EXIT_FAILURE);
    }
    txt_hover_retour=load_bitmap("../Bitmap/Menu/txt_hover_retour.bmp",NULL);
    if (!txt_hover_retour)
    {
        allegro_message("pas pu trouver Bitmap/Menu/txt_hover_retour.bmp");
        exit(EXIT_FAILURE);
    }

}

// Menu principal
void Menu::principal()
{
    // R�initialisation du bool�en m_exit
    m_exit = false;
    int x= 0;
    int y= 0;
    int choix;
    clear_window();

    while( m_exit == false )
    {

        //Sur console
        if(!getallegro_present())
        {

            clear_window(); // nettoie la console
            partie.ConsPrint(1,13);
            std::cout << "Bataille Navale";
            partie.ConsPrint(3,0);
            std::cout << "1. 1 JOUEUR" <<std::endl
                      << "2. 2 JOUEURS" <<std::endl
                      << "3. CHARGER" <<std::endl
                      << "4. OPTION" <<std::endl
                      << "5. REGLES" <<std::endl
                      << "6. QUITTER" <<std::endl;
            partie.ConsPrint(10,5);
            std::cout << "Choix : ";

            std::cin >> choix;

            clear_window();

            switch(choix){

                case 1 :
                        /*
                        clear
                        reset
                        lancer avec parametre 1 joueur
                        */
                    break;
                case 2 :
                        /*
                        clear
                        reset
                        lancer avec parametre 2 joueurs
                        */
                    break;
                case 3 : charger();
                    break;
                case 4 : option();
                    break;
                case 5 : regles();
                    break;
                case 6 : m_exit = true;
                    break;
                default :
                    break;
            }

        }

        //Sur Allegro
        else{
            // r�initilisation des coordonn�es souris
            x= mouse_x;
            y= mouse_y;

            // Affichage du menu_principal
            clear_bitmap(buffer);
            blit(menu_principal, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
            blit(txt_un_joueur,buffer,0,0,50,50,SCREEN_W,SCREEN_H);
            blit(txt_deux_joueur,buffer,0,0,50,120,SCREEN_W,SCREEN_H);
            blit(txt_charger,buffer,0,0,50,190,SCREEN_W,SCREEN_H);
            blit(txt_option,buffer,0,0,50,260,SCREEN_W,SCREEN_H);
            blit(txt_regles,buffer,0,0,50,330,SCREEN_W,SCREEN_H);
            blit(txt_quitter,buffer,0,0,600,500,SCREEN_W,SCREEN_H);

            /// "1J"
            //si la souris se trouve sur "1J"
            if( x>=50 && x<=200 && y>=50 && y<=100 )
            {
                blit(txt_hover_un_joueur,buffer,0,0,50,50,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    partie.LancerPartie(true);
                    /*
                    clear
                    reset
                    lancer avec parametre 1 joueur
                    */
                }
            }

            /// "2J"
            //si la souris se trouve sur "2J"
            if( x>=50 && x<=200 && y>=120 && y<=170 )
            {
                blit(txt_hover_deux_joueur,buffer,0,0,50,120,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    partie.LancerPartie(false);
                    /*
                    clear
                    reset
                    lancer avec parametre 2 joueur
                    */
                }
            }

            /// "CHARGER"
            //si la souris se trouve sur "CHARGER"
            if( x>=50 && x<=200 && y>=190 && y<=240 )
            {
                blit(txt_hover_charger,buffer,0,0,50,190,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    charger();
                }
            }

            /// "OPTION"
            //si la souris se trouve sur "OPTION"
            if( x>=50 && x<=200 && y>=260 && y<=310 )
            {
                blit(txt_hover_option,buffer,0,0,50,260,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    option();
                }
            }

            /// "REGLE"
            //si la souris se trouve sur "REGLE"
            if( x>=50 && x<=200 && y>=330 && y<=380 )
            {
                blit(txt_hover_regles,buffer,0,0,50,330,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    regles();
                }
            }

            /// "QUITTER"
            //si la souris se trouve sur "QUITTER"
            if( x>=600 && x<=750 && y>=500 && y<=550 )
            {
                blit(txt_hover_quitter,buffer,0,0,600,500,SCREEN_W,SCREEN_H);
                blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                // si clique gauche
                if ( mouse_b & 1 )
                {
                    // retour au menu principal
                    m_exit = true;
                }
            }
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(100); //pause pour qu'il soit visible
        }
    }


}

// Menu option
void Menu::option()
{
    // R�initialisation du bool�en m_exit
    m_exit = false;
    int x= 0;
    int y= 0;
    int choix;
    clear_window();

    while( m_exit == false )
    {

        //Sur console
        if(!getallegro_present()){

            partie.ConsPrint(1,13);
            std::cout << "SNOOPY";
            partie.ConsPrint(7,3);
            std::cout << "OPTION";


            partie.ConsPrint(20,25);
            std::cout << "R : Retour";



            while (getch()!='r');
            m_exit=true;
        }
        else{

            // r�initilisation des coordonn�es souris
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
                    m_exit = true;
                }
            }
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(100); //pause pour qu'il soit visible
        }

    }
    m_exit = false;
}

void Menu::charger()
{
    // R�initialisation du bool�en m_exit
    m_exit = false;
    int x= 0;
    int y= 0;
    int choix;
    clear_window();

    while( m_exit == false )
    {
        //Sur console
        if(!getallegro_present()){

            partie.ConsPrint(1,13);
            std::cout << "Bataille Navale";
            partie.ConsPrint(7,3);
            std::cout << "CHARGER";


            partie.ConsPrint(20,25);
            std::cout << "R : Retour";



            while (getch()!='r');
            m_exit=true;
        }
        else{

            // r�initilisation des coordonn�es souris
            x= mouse_x;
            y= mouse_y;

            // Affichage du menu_option
            clear_bitmap(buffer);
            blit(menu_charger, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
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
                    m_exit = true;
                }
            }
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(100); //pause pour qu'il soit visible

        }
    }
    m_exit = false;


}

// Menu r�gles
void Menu::regles()
{
    // R�initialisation du bool�en m_exit
    m_exit = false;
    int x= 0;
    int y= 0;
    int choix;
    //clear_window();

    while( m_exit == false )
    {
         //Sur console
        if(!getallegro_present()){

            partie.ConsPrint(1,13);
            std::cout << "Bataille Navale";
            partie.ConsPrint(7,3);
            std::cout << "REGLES";
            partie.ConsPrint(10,0);
            std::cout << "Lorem ipsum" << std::endl
                      <<"Lorem ipsum " <<std::endl
                      <<"Lorem ipsum" << std::endl
                      <<"Lorem ipsum" << std::endl
                      <<"Lorem ipsum" << std::endl
                      <<"Lorem ipsum" << std::endl
                      <<"Lorem ipsum" << std::endl;
            partie.ConsPrint(20,25);
            std::cout << "R : Retour";



            while (getch()!='r');
            m_exit=true;
        }
        else{

            // r�initilisation des coordonn�es souris
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
                    m_exit = true;
                }
            }
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(100); //pause pour qu'il soit visible

        }
    }
    m_exit = false;


}

void Menu::destroy_bitmaps()
{
    destroy_bitmap(buffer);
    destroy_bitmap(menu_principal);
    destroy_bitmap(menu_option);
    destroy_bitmap(menu_regles);
    destroy_bitmap(menu_charger);
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
