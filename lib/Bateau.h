#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <vector>

struct case{
    unsigned int x;
    unsigned int y;
    bool touche;
    *Bateau Bateau;
    };


// classe abstraite Bateau
class Bateau
{
    protected :

        std::vector<case> corps; //Tableau de l'ensemble des cases occupée par le bateau, et leur état (touché, !touché)
        unsigned int taille; //Définie par le constructeur des différents bateaux
        char symbole; //Symbole représentant le type de bateau

    public :

        Bateau(int x, int y, char _orientation, unsigned int taille);   //Constructeur par surcharge d'un bateau neuf
        Bateau(int x, int y, char _orientation, std::vector<bool> _etat);// constructeur par surcharge d'un bateau sauvegardé
        virtual ~Bateau(); // destructeur


        //getter
        unsigned int get_centre_x();// coordonnées du centre x
        unsigned int get_centre_y();// coordonnées du centre y
        unsigned int get_etat(); //Suite binaire de l'état des cases (sauvegarde)
        char get_orientation(); //'h' pour horizontal ou 'v' pour vertical
        char get_symbole();
        bool get_existe();      //1= au moins une case !touche, 0= toutes les cases touche



        //methodes
        void Deplacement();     //Déplacement du bateau
        virtual void Tourner()=0;   //Rotation du bateau, virtuelle pour gérer le cuirassé
        virtual void Tirer()=0;     //Tir

        unsigned int touche(unsigned int x, unsigned int y);    //Réaction à un tir de missile retour 0=case déjà touchée, 1=case touchée, 2=bateau coulé
                                                                //touche() transforme le bateau en épave si besoin
};

#endif // BATEAU_H_INCLUDED
