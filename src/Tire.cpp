#include "../lib/Tire.h"
#ifdef USINGALLEGRO
bitmap* Tire::get_geule_tire()
{

}
std::vector<bitmap*> Tire::get_annimation_blowup()
{
}
#endif
void Tire::modif_type(char newtype){

}

Tire::Tire(char typevaiseau){
  #ifdef USINGALLEGRO
  //TODO : creation des bitmap

  #endif
  switch (typevaiseau) {
    case SYMBOL_CROISEUR: taille_x=2;
                          taille_y=2;
                          typetire = TIRE_CROISEUR;
                          break;
                          case SYMBOL_CUIRASSER: taille_x=3;
                                                taille_y=3;
                                                typetire = TIRE_CUIRASSER;
                                                break;
                                                case SYMBOL_SOUSMARIN: taille_x=1;
                                                                      taille_y=1;
                                                                      typetire = TIRE_SOUSMARIN;
                                                                      break;
                                                                      case SYMBOL_DESTROYER: taille_x=3;
                                                                                            taille_y=3;
                                                                                            typetire = TIRE_DESTROYER_FUSER;
                                                                                            break;


  }
  #ifdef USINGALLEGRO
  init_bitmap();
  #endif
}
Tire::~Tire(){

} // destructeur


//getters
/*unsigned int get_taille_x();
unsigned int get_taille_y();
unsigned int get_typetire();
bool can_hit(char symbolebateau);*/
