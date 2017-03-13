#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include <iostream>
#include "Allegro.h"

class Partie
{

    private :

       Allegro alleg;
       bool alleg_present;

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
