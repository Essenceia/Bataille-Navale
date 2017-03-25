#include "../lib/Tire.h"

BITMAP* Tire::get_geule_tire()
{

}
std::vector<BITMAP*> Tire::get_annimation_blowup()
{
}

/*
 * Tire::modif_type(char newtype, bool first)
 * char - on lui donne le type du vaiseau , voire defines de Tire.h
 * bool - true si c'est a l'initialisation , false sinon , permet de mettre a jour dynamiquement le type
 */
void Tire::modif_type(char newtype, bool first) {
    if (first) {
        switch (newtype) {
            case SYMBOL_CROISEUR:
                taille_x = 2;
                taille_y = 2;
                typetire = TIRE_CROISEUR;
                break;
            case SYMBOL_CUIRASSER:
                taille_x = 3;
                taille_y = 3;
                typetire = TIRE_CUIRASSER;
                break;
            case SYMBOL_SOUSMARIN:
                taille_x = 1;
                taille_y = 1;
                typetire = TIRE_SOUSMARIN;
                break;
            case SYMBOL_DESTROYER:
                taille_x = 3;
                taille_y = 3;
                typetire = TIRE_DESTROYER_FUSER;
                break;

            default :
                std::cerr << "Tire::modif_type type inderfini :" + newtype << std::endl;
                taille_x = 1;
                taille_x = 1;
                typetire = TIRE_CROISEUR;
                break;
                        }
    } else { // nous allons mettre a jour un tire
        switch (newtype) {
            case SYMBOL_CROISEUR:
                taille_x = 2;
                taille_y = 2;
                typetire = TIRE_CROISEUR;
                break;
            case SYMBOL_CUIRASSER:
                taille_x = 3;
                taille_y = 3;
                typetire = TIRE_CUIRASSER;
                break;
            case SYMBOL_SOUSMARIN:
                taille_x = 1;
                taille_y = 1;
                typetire = TIRE_SOUSMARIN;
                break;
            case SYMBOL_DESTROYER:
                taille_x = 2;
                taille_y = 2;
                typetire = TIRE_DESTROYER_DEMERDE;
                break;

            default :
                std::cerr << "Tire::modif_type type inderfini :" + newtype << std::endl;
                taille_x = 1;
                taille_x = 1;
                typetire = TIRE_CROISEUR;
                break;
        }
    }
}


Tire::Tire(char typevaiseau) {
#ifdef USINGALLEGRO
    //TODO : creation des BITMAP

#endif
    modif_type(typevaiseau,true);
#ifdef USINGALLEGRO
    init_BITMAP();
#endif
}

Tire::~Tire() {
} // destructeur


//getters
unsigned int Tire::get_taille_x()
{
    return taille_x;
}
unsigned int Tire::get_taille_y(){
    return taille_y;
}
char Tire::get_typetire(){
   return typetire;
}
bool Tire::can_hit(char symbolebateau){
    if(typetire == TIRE_SOUSMARIN ){if(symbolebateau == SYMBOL_SOUSMARIN) return true;
    else return false; }
    else return true;

}
//setter
void Tire::new_type(char typevaiseau){
    modif_type(typevaiseau,false);
}