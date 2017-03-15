#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <vector>

struct case{
    int x;
    int y;
    bool touche;
    *Bateau Bateau;
    };


// classe abstraite Bateau
class Bateau
{
    protected :

        std::vector<case> corps; //Tableau de l'ensemble des cases occupée par le bateau, et leur état (touché, !touché)
        int taille; //Définie par le constructeur des différents bateaux
        char symbole; //Symbole représentant le type de bateau

    public :

        Bateau(int x, int y, int _taille, char _orientation);// constructeur par surcharge
        virtual ~Bateau(); // destructeur


        //getters
        unsigned int get_px();
        unsigned int get_py();
        bool get_existe();
        unsigned int get_taille();
        char get_orientation(); //'h' pour horizontal ou 'v' pour vertical
        bool get_etat(unsigned int pos); //Vecteur pour voir les parties endommag�es d'un bateau


        //methodes
        virtual void Deplacement()=0;
        virtual void Tourner()=0;
        virtual void Tirer()=0;
        virtual char Symbole()=0;


};

#endif // BATEAU_H_INCLUDED
