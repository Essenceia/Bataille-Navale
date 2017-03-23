#include "../lib/Bateau.h"
#include <iostream>
//Constructeur
Bateau::Bateau(unsigned int _x, unsigned int _y, unsigned int _taille, char _orientation)
      :pos_x(_x), pos_y(_y), taille(_taille), orientation(_orientation)
{
    etat.push_back(new Case);
    etat[0]->x=_x;
    etat[0]->y=_y;
    etat[0]->touche=false;

    unsigned int h=0, v=0, plac=1;

    if(_orientation=='h') h=1;
    else v=1;

    for(unsigned int i=1;i<(taille-1);i=i+2) {
        etat.push_back(new Case);
        etat[i]->x=_x-plac*h;
        etat[i]->y=_y-plac*v;
        etat[i]->touche=false;

        etat.push_back(new Case);
        etat[i+1]->x=_x+plac*h;
        etat[i+1]->y=_y+plac*v;
        etat[i+1]->touche=false;

        plac++;
    }

    for(unsigned int i=0;i<taille;i++)
        std::cout << etat[i]->x << " "
                << etat[i]->y  << std::endl;
}

//Destructeur
Bateau::~Bateau()
{

}

//getters
unsigned int Bateau::get_px()
{
    return pos_x;
}
unsigned int Bateau::get_py()
{
    return pos_y;
}
unsigned int Bateau::get_taille()
{
    return taille;
}
char Bateau::get_orientation()
{
    return orientation;
}
bool Bateau::get_etat(unsigned int pos)
{
    if(pos < get_taille()){
    return etat[pos];
  }
  std::cerr << "Bateau::get_etat out of bounds" << '\n';
  return false;
}
unsigned int Bateau::get_etatx(unsigned int pos)
{
    if(pos < get_taille()){
    return etat[pos]->x;
  }
  std::cerr << "Bateau::get_etat out of bounds" << '\n';
  return false;
}
unsigned int Bateau::get_etaty(unsigned int pos)
{
    if(pos < get_taille()){
    return etat[pos]->y;
  }
  std::cerr << "Bateau::get_etat out of bounds" << '\n';
  return false;
}
bool Bateau::get_etattouche(unsigned int pos)
{
    if(pos < get_taille()){
    return etat[pos]->touche;
  }
  std::cerr << "Bateau::get_etat out of bounds" << '\n';
  return false;
}
//position par rapport a l'origine
void Bateau::set_etat(unsigned int pos){
  if(pos < get_taille()){
     etat[pos]=false;
  }
}
bool Bateau::is_dead(){
  /*bool f=false;
  for(unsigned int i =0 ; i < get_taille(); i++){
    f|=get_etat(i);
  }
  return f;*/
}
