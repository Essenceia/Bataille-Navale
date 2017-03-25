#ifndef TIRE_H_INCLUDED
#define TIRE_H_INCLUDED

#define SYMBOL_DESTROYER ((char)'d')
#define SYMBOL_SOUSMARIN ((char)'s')
#define SYMBOL_CUIRASSER ((char)'p')
#define SYMBOL_CROISEUR ((char)'c')
#define TIRE_CROISEUR ((char)'c')
#define TIRE_DESTROYER_FUSER ((char)'f')
#define TIRE_DESTROYER_DEMERDE ((char)'d')
#define TIRE_SOUSMARIN ((char)'s')
#define TIRE_CUIRASSER ((char)'p')
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Allegro.h"
// classe abstraite Objet
class Tire
{
    protected :
        unsigned int taille_y;
        unsigned int taille_x;
        char typetire;

        std::vector<BITMAP*> annimation_blowup;
        BITMAP* geule_tire;
        BITMAP* get_geule_tire();
        std::vector<BITMAP*> get_annimation_blowup();
        void init_bitmap();


        void modif_type(char newtype, bool first);

    public :

        Tire(char typevaiseau);
        ~Tire(); // destructeur


        //getters
        unsigned int get_taille_x();
        unsigned int get_taille_y();
        char get_typetire();
        bool can_hit(char symbolebateau);
        void new_type(char typevaiseau);


};
#endif // OBJET_H_INCLUDED
