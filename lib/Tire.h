#define TIRE_H_INCLUDED
#ifdef TIRE_H_INCLUDED
#define SYMBOL_DESTROYER ((char)'o')
#define SYMBOL_SOUSMARIN ((char)'s')
#define SYMBOL_CUIRASSER ((char)'c')
#define SYMBOL_CROISEUR ((char)'k')
#define TIRE_CROISEUR ((char)'k')
#define TIRE_DESTROYER_FUSER ((char)'f')
#define TIRE_DESTROYER_DEMERDE ((char)'m')
#define TIRE_SOUSMARIN ((char)'s')
#define TIRE_CUIRASSER ((char)'c')
#include <iostream>
#include <stdio.h>
#include <vector>

// classe abstraite Objet
class Tire
{
    protected :
        unsigned int taille_y;
        unsigned int taille_x;
        char typetire;
        #ifdef USINGALLEGRO
        std::vector<bitmap*> annimation_blowup;
        bitmap* geule_tire;
        bitmap* get_geule_tire();
        std::vector<bitmap*> get_annimation_blowup();
        void init_bitmap();
        #endif
        void modif_type(char newtype, bool first);


    public :

        Tire(char typevaiseau);
        virtual ~Tire(); // destructeur


        //getters
        unsigned int get_taille_x();
        unsigned int get_taille_y();
        char get_typetire();
        bool can_hit(char symbolebateau);
        void new_type(char typevaiseau);


};
#endif // OBJET_H_INCLUDED
