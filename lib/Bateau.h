#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <vector>

// classe abstraite Bateau
class Bateau
{
    protected :

        unsigned int pos_x;
        unsigned int pos_y;
        unsigned int taille; //Sert aussi de type, 7 pour cuirasse, 5 pour croiseur, 3 pour destroyer et 1 pour sous marin
        char orientation;
        bool existe; // va nous dire si le bateau est encore entier, sinon on ne va plus l'afficher 0=non 1=oui
        std::vector<bool> etat;

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
        virtual void Deplacement()=0;
        virtual void Tourner()=0;
        virtual void Tirer()=0;
        virtual char Symbole()=0;


};

#endif // BATEAU_H_INCLUDED
