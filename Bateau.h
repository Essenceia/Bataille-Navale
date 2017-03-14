#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <vector>

// classe abstraite Bateau
class Bateau
{
    protected :

        int pos_x;
        int pos_y;
        int taille; //Sert aussi de type, 7 pour cuirasse, 5 pour croiseur, 3 pour destroyer et 1 pour sous marin
        char orientation;
        bool existe; // va nous dire si le bateau est encore entier, sinon on ne va plus l'afficher 0=non 1=oui
        std::vector<bool> etat;

    public :

        Bateau(int x, int y, int _taille, char _orientation);// constructeur par surcharge
        virtual ~Bateau(); // destructeur


        //getters
        int get_px();
        int get_py();
        bool get_existe();
        int get_taille();
        char get_orientation(); //'h' pour horizontal ou 'v' pour vertical
        bool get_etat(int pos); //Vecteur pour voir les parties endommagées d'un bateau


        //methodes
        virtual void Deplacement()=0;
        virtual void Tourner()=0;
        virtual void Tirer()=0;
        virtual char Symbole()=0;


};

#endif // BATEAU_H_INCLUDED
