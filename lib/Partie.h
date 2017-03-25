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


class Partie
{

    private :

       Allegro alleg;

       bool alleg_present;

       std::vector<std::vector<Bateau* > > battab;


       //nbr bateau restant par type et par joueur
       unsigned int Tot1;
       unsigned int Tot2;

       unsigned int Cui1;
       unsigned int Cro1;
       unsigned int Des1;
       unsigned int Sou1;
       unsigned int Cui2;
       unsigned int Cro2;
       unsigned int Des2;
       unsigned int Sou2;


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
        void LancerPartie(bool ia);
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
        void affichageAlleg(int i);
        void affichageCons();


        //gestion bateaux
        void TournerBateau(unsigned int currentplayer, unsigned int numbatselected);
        void Tirer(unsigned int currentplayer, unsigned int otherplayer, unsigned int numbatselected);
        void DeplacerBateau(unsigned int currentplayer, unsigned int numbatselected);

        void VerifRestant();

        //Gestion Toucher-Couler
        //char Tirer(unsigned int pn ,unsigned int x, unsigned int y,char typetire,Bateau* tireur);
        //char Tirer(char player_number, unsigned int x, unsigned int y,char typetire,Bateau* tireur)__attribute__((depricated));

};


#endif
