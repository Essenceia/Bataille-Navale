#include "../lib/Menu.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h>

// contructeur par default
Menu::Menu()
    : m_exit(false), allegro_present(0)
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
    bool ok=false;

    //Sur console
    system("cls"); // nettoie la console
    int int_allegro_present = 0;

    partie.ConsPrint(1,13);
    std::cout << "Bataille Navale";
    partie.ConsPrint(3,0);
    std::cout << "Voulez vous jouer avec ou sans Allegro?" <<std::endl
              << "0. sans" <<std::endl
              << "1. avec" <<std::endl
              << "2. MAIS C QUOA HALAYGREAU?" <<std::endl;

    while(!ok){
            partie.ConsPrint(10,5);
            std::cout << "Choix :     ";
            partie.ConsPrint(10,13);
            std::cin >> int_allegro_present;
            if (std::cin.fail()){
                partie.ConsPrint(13,5);
                std::cout << "Ah ben bravo t'as fais plante le programme !";
                partie.ConsPrint(24,0);
                system("pause");
                exit(0);
            }


            if(int_allegro_present==1||int_allegro_present==2||int_allegro_present==0) ok=true;
    }

    if(int_allegro_present==0)  allegro_present=0;
    else  allegro_present=1;

    partie.setal(allegro_present);

    allegro_present=int_allegro_present;

}

void Menu::halaygreau()
{

    Al = load_sample("../Bitmap/Menu/Al.wav");

    rest(200);

    play_sample(Al, 127, 127, 1000, 1);

    unsigned int compteur_surprise=0;

    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);

        if(compteur_surprise==0) draw_sprite(buffer, Al1, 0, 0);
        if(compteur_surprise==1) draw_sprite(buffer, Al2, 0, 0);

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H); // Affichage général

        if(compteur_surprise==1) compteur_surprise=0;
        else compteur_surprise=1;
        rest(100);
    }
}

unsigned int Menu::getallegro_present()
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
    menu_regles=load_bitmap("../Bitmap/Menu/menu_regles.bmp",NULL);
    if (!menu_regles)
    {
        allegro_message("pas pu trouver Bitmap/Menu/menu_regles.bmp");
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
    Al1=load_bitmap("../Bitmap/Menu/Al1.bmp",NULL);
    if (!Al1)
    {
        allegro_message("pas pu trouver Bitmap/Menu/Al1.bmp");
        exit(EXIT_FAILURE);
    }
    Al2=load_bitmap("../Bitmap/Menu/Al2.bmp",NULL);
    if (!Al2)
    {
        allegro_message("pas pu trouver Bitmap/Menu/Al2.bmp");
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
    int choix = 1;
    system("cls");

    while( m_exit == false )
    {

        //Sur console
        if(!getallegro_present())
        {

            system("cls");
            partie.ConsPrint(1,13);
            std::cout << "Bataille Navale";
            partie.ConsPrint(3,0);
            std::cout << "[1 JOUEUR] " <<std::endl
                      << " 2 JOUEURS " <<std::endl
                      << " CHARGER " <<std::endl
                      << " REGLES " <<std::endl
                      << " QUITTER " <<std::endl<<std::endl<<std::endl<<std::endl<<std::endl
                      << "Naviguez dans le menu à l'aide des touches Z et S, faites votre choix en pressant ENTRER";
            do   //Loop until 'Enter' is pressed
                {
                c = getch();
                switch(c)
                {
                    switch(key)
                    {
                    case 'z' :
                        switch (choix)
                        {
                        case 1 :
                            choix = 5;
                            partie.ConsPrint(3,0);
                            std::cout << " ";
                            partie.ConsPrint(3,9);
                            std::cout << " ";
                            partie.ConsPrint(7,0);
                            std::cout << "[";
                            partie.ConsPrint(7,8);
                            std::cout << "]";
                            break;
                        case 2 :
                            choix = 1;
                            partie.ConsPrint(4,0);
                            std::cout << " ";
                            partie.ConsPrint(4,10);
                            std::cout << " ";
                            partie.ConsPrint(3,0);
                            std::cout << "[";
                            partie.ConsPrint(3,9);
                            std::cout << "]";
                            break;
                        case 3 :
                            choix = 2;
                            partie.ConsPrint(5,0);
                            std::cout << " ";
                            partie.ConsPrint(5,8);
                            std::cout << " ";
                            partie.ConsPrint(4,0);
                            std::cout << "[";
                            partie.ConsPrint(4,10);
                            std::cout << "]";
                            break;
                        case 4 :
                            choix = 3;
                            partie.ConsPrint(6,0);
                            std::cout << " ";
                            partie.ConsPrint(6,7);
                            std::cout << " ";
                            partie.ConsPrint(5,0);
                            std::cout << "[";
                            partie.ConsPrint(5,8);
                            std::cout << "]";
                            break;
                        case 5 :
                            choix = 5;
                            partie.ConsPrint(7,0);
                            std::cout << " ";
                            partie.ConsPrint(7,8);
                            std::cout << " ";
                            partie.ConsPrint(6,0);
                            std::cout << "[";
                            partie.ConsPrint(6,7);
                            std::cout << "]";
                            break;
                        }
                        break;
                    case 's' :
                        switch (choix)
                        {
                        case 1 :
                            choix = 2;
                            partie.ConsPrint(3,0);
                            std::cout << " ";
                            partie.ConsPrint(3,9);
                            std::cout << " ";
                            partie.ConsPrint(4,0);
                            std::cout << "[";
                            partie.ConsPrint(4,10);
                            std::cout << "]";
                            break;
                        case 2 :
                            choix = 3;
                            partie.ConsPrint(4,0);
                            std::cout << " ";
                            partie.ConsPrint(4,10);
                            std::cout << " ";
                            partie.ConsPrint(5,0);
                            std::cout << "[";
                            partie.ConsPrint(5,8);
                            std::cout << "]";
                            break;
                        case 3 :
                            choix = 4;
                            partie.ConsPrint(5,0);
                            std::cout << " ";
                            partie.ConsPrint(5,8);
                            std::cout << " ";
                            partie.ConsPrint(6,0);
                            std::cout << "[";
                            partie.ConsPrint(6,7);
                            std::cout << "]";
                            break;
                        case 4 :
                            choix = 5;
                            partie.ConsPrint(6,0);
                            std::cout << " ";
                            partie.ConsPrint(6,7);
                            std::cout << " ";
                            partie.ConsPrint(7,0);
                            std::cout << "[";
                            partie.ConsPrint(7,8);
                            std::cout << "]";
                            break;
                        case 5 :
                            choix = 1;
                            partie.ConsPrint(7,0);
                            std::cout << " ";
                            partie.ConsPrint(7,8);
                            std::cout << " ";
                            partie.ConsPrint(3,0);
                            std::cout << "[";
                            partie.ConsPrint(3,9);
                            std::cout << "]";
                            break;
                        }
                        break;
                    default :
                        break;
                    }
                }
            while(c != '\r');
            system("cls");
            switch(choix){

                case 1 : partie.LancerPartie(true,false);
                    break;
                case 2 : partie.LancerPartie(false,false);
                    break;
                case 3 : partie.LancerPartie(false,true);
                    break;
                case 4 : regles();
                    break;
                case 5 : m_exit = true;
                    break;
                default :
                    break;
            }

        }

        //Sur Allegro
        else{

            x= mouse_x;
            y= mouse_y;

            // Affichage du menu_principal
            clear_bitmap(buffer);
            blit(menu_principal, buffer, 0,0,0,0,SCREEN_W,SCREEN_H);
            blit(txt_un_joueur,buffer,0,0,50,50,SCREEN_W,SCREEN_H);
            blit(txt_deux_joueur,buffer,0,0,50,120,SCREEN_W,SCREEN_H);
            blit(txt_charger,buffer,0,0,50,190,SCREEN_W,SCREEN_H);
            blit(txt_regles,buffer,0,0,50,260,SCREEN_W,SCREEN_H);
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
                    partie.LancerPartie(true,false);
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
                    partie.LancerPartie(false,false);
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
                    partie.LancerPartie(false,true);
                }
            }

            /// "REGLE"
            //si la souris se trouve sur "REGLE"
            if( x>=50 && x<=200 && y>=260 && y<=310 )
            {
                blit(txt_hover_regles,buffer,0,0,50,260,SCREEN_W,SCREEN_H);
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

// Menu r�gles
void Menu::regles()
{
    // R�initialisation du bool�en m_exit
    m_exit = false;
    int x= 0;
    int y= 0;
    system("cls");

    while( m_exit == false )
    {
         //Sur console
        if(!getallegro_present()){

            partie.ConsPrint(1,13);
            std::cout << "Bataille Navale";
            partie.ConsPrint(3,3);
            std::cout << "REGLES";
            partie.ConsPrint(5,0);
            std::cout << "Chaque joueur dispose de 10 bateaux : ";
            partie.ConsPrint(6,2);
            std::cout << "1 Cuirasse : 7 cases, Puissance de tir 3x3 mais saut de tour si on le pivote";
            partie.ConsPrint(7,2);
            std::cout << "2 Croiseurs : 5 cases, Puissance de tir 2x2";
            partie.ConsPrint(8,2);
            std::cout << "3 Destroyer : 3 cases, Puissance de tir 1x1 sauf 1ere munition qui est une    fusee 4x4 montrant les ennemis un court instant";
            partie.ConsPrint(10,2);
            std::cout << "4 Sous-marins : 1 case, Puissance de tir 1x1 et ne pouvant couler que des sous-marins";
            partie.ConsPrint(12,3);
            std::cout << "VOTRE MISSION EST DE COULER LA FLOTTE ADVERSE !";
            partie.ConsPrint(14,0);
            std::cout << "Touches";
            partie.ConsPrint(16,0);
            std::cout << "Pour selectionner un bateau ou une cible de tir : entrer les coordonnees";
            partie.ConsPrint(17,0);
            std::cout << "Pour deplacer un bateau selectionne : "<<std::endl<<" 'h' pour aller vers le haut, 'b' pour bas, 'g' pour gauche et 'd' pour droite";
            partie.ConsPrint(19,0);
            std::cout << "Pour sauvegarder : 's' lors de la selection de bateau";



            partie.ConsPrint(24,25);

            std::cout << "R : Retour";
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
    destroy_bitmap(menu_regles);
    destroy_bitmap(txt_un_joueur);
    destroy_bitmap(txt_deux_joueur);
    destroy_bitmap(txt_regles);
    destroy_bitmap(txt_quitter);
    destroy_bitmap(txt_retour);
    destroy_bitmap(txt_hover_un_joueur);
    destroy_bitmap(txt_hover_deux_joueur);
    destroy_bitmap(txt_hover_regles);
    destroy_bitmap(txt_hover_quitter);
    destroy_bitmap(txt_hover_retour);
    destroy_bitmap(Al1);
    destroy_bitmap(Al2);

}

void Menu::destroy_wav()
{
    destroy_sample(Al);
}
