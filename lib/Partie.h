#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <iostream>
#ifdef USINGALLEGRO
#include "Allegro.h"
#endif //USINGALLEGRO
#include "Bateau.h"
#include "Cuirasse.h"
#include "Croiseur.h"
#include "Destroyer.h"
#include "Sousmarin.h"
#include "Objet.h"

class Partie
{

    private :
#ifdef USINGALLEGRO
       Allegro alleg;
       #endif //USINGALLEGRO
       bool alleg_present;

       /*Les deux tableaux
       Chaque tableau est un 15*15 sur deux couches, une visible par son propri�taire et l'autre par l'adversaire.
       Deux plans de 15*15 se superposent, sur celui en dessous on a le placement des bateaux
       mais sur celui au dessus on a les impacts et l� o� la fus�e a fait un "trou" lorsque son tir est effectu�.
       */
       std::vector< std::vector< std::vector<char> > > tabj1;
       std::vector< std::vector< std::vector<char> > > tabj2;

       std::vector<Bateau*> battab1;
       std::vector<Bateau*> battab2;

       std::vector<Objet*> objtab1;
       std::vector<Objet*> objtab2;


    public :

        // constructeur
        Partie();

        //destructeur
        ~Partie();


        // Les gets

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
        void changer_val_tableau(int numtab, int coordonees_x, int coordonees_y, char newval);// modification du tableau

        //gestion allegro et autre affichage
        void setal(bool al);
        void ConsPrint(int y, int x);
        void ChargerImages();
        void DestroyImages();



};


#endif
