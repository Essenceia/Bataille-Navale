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

        Bateau(unsigned int x, unsigned int y,unsigned int _taille, char _orientation);// constructeur par surcharge
        virtual ~Bateau(); // destructeur
        //getters
        unsigned int get_px();
        unsigned int get_py();
        bool get_existe();
        unsigned int get_taille();
        char get_orientation(); //'h' pour horizontal droite ou 'v' pour vertical vers le haut 'g' horizontal gauche 'c' vertical bas
        bool get_etat(unsigned int pos); //Vecteur pour voir les parties endommag�es d'un bateau
        void set_etat(unsigned int pos);

        //methodes
        void Deplacement();     //Déplacement du bateau
        virtual void Tourner()=0;   //Rotation du bateau, virtuelle pour gérer le cuirassé
        virtual void Tirer()=0;     //Tir

        unsigned int touche(unsigned int x, unsigned int y);    //Réaction à un tir de missile retour 0=case déjà touchée, 1=case touchée, 2=bateau coulé
                                                                //touche() transforme le bateau en épave si besoin
};

#endif // BATEAU_H_INCLUDED
