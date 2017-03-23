#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED
#include <iostream>
#include "Allegro.h"
#include "Bateau.h"
#include "Cuirasse.h"
#include "Croiseur.h"
#include "Destroyer.h"
#include "Sousmarin.h"
#include <utility>

//TODO : enlever

class Partie
{

    private :

       Allegro alleg;

       bool alleg_present;

       /*Les deux tableaux
       Chaque tableau est un 15*15 sur deux couches, une visible par son propri�taire et l'autre par l'adversaire.
       Deux plans de 15*15 se superposent, sur celui en dessous on a le placement des bateaux
       mais sur celui au dessus on a les impacts et l� o� la fus�e a fait un "trou" lorsque son tir est effectu�.
       */
       std::vector< std::vector< std::vector< std::vector<char > > > > tabj;


       std::vector<std::vector<Bateau* > > battab;

       //std::vector<std::vector<Objet* > > objtab;

       //std::vector<std::vector<std::vector<case* > > > corps;


    public :

        // constructeur
        Partie();
        //destructeur
        ~Partie();
        // Les gets
        Bateau* get_Bateau(unsigned int x, unsigned int y,unsigned int playerid);
        // les sets

        ///Methodes
        //gestion partie
        void LancerPartie();
        void initPartie();
        void resetpartie();

        // gestion sauvergarde
        void sauvegarder_partie(std::string num);
        void chargement_partie(std::string num);

        // gestion tableau
        void AfficherTab(int numtab, bool visible); // affichage du tableau
        //void changer_val_tableau(int numtab, int coordonees_x, int coordonees_y, char newval);// modification du tableau
        void changer_val_tableau(int numtab, unsigned int coordonees_x,unsigned int coordonees_y, char newval);
        //gestion allegro et autre affichage
        void setal(bool al);
        void ConsPrint(unsigned int x,unsigned int y);
        void ChargerImages();
        void DestroyImages();
        void affichageAlleg();
        void affichageCons();

        //Gestion Toucher-Couler
        char Tirer(unsigned int pn ,unsigned int x, unsigned int y,char typetire,Bateau* tireur);
        //char Tirer(char player_number, unsigned int x, unsigned int y,char typetire,Bateau* tireur)__attribute__((depricated));

};


#endif
