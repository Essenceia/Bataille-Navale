#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <vector>

struct Case{
    unsigned int x;
    unsigned int y;
    bool touche;
};

// classe abstraite Bateau
class Bateau
{
    protected :

        unsigned int pos_x;
        unsigned int pos_y;
        unsigned int taille; //Définie par le constructeur des différents bateaux
        char orientation;
        std::vector<Case*> etat;
        char symbole; //Symbole représentant le type de bateau

    public :

        Bateau(unsigned int x, unsigned int y,unsigned int _taille, char _orientation);// constructeur par surcharge
        virtual ~Bateau(); // destructeur
        //getters
        unsigned int get_px();
        unsigned int get_py();
        bool get_existe();
        unsigned int get_taille();
        char get_orientation(); //'h' pour horizontal droite ou 'v' pour vertical
        bool get_etat(unsigned int pos); //Vecteur pour voir les parties endommag�es d'un bateau
        unsigned int get_etatx(unsigned int pos);
        unsigned int get_etaty(unsigned int pos);
        bool get_etattouche(unsigned int pos);
        //setters
        void set_etat(unsigned int pos, bool newetat);
        void set_orientation(char newori);
        void set_etatx(unsigned int pos, unsigned int newpos);
        void set_etaty(unsigned int pos, unsigned int newpos);


        virtual bool get_fusee()=0;
        virtual bool get_cd()=0;
        virtual void set_fusee()=0;
        virtual void set_cd()=0;


        unsigned int touche(unsigned int x, unsigned int y);    //Réaction à un tir de missile retour 0=case déjà touchée, 1=case touchée, 2=bateau coulé
                                                                //touche() transforme le bateau en épave si besoin

        bool is_dead();
};

#endif // BATEAU_H_INCLUDED
