#include "../lib/Bateau.h"
#include <iostream>
//Constructeur
Bateau::Bateau(unsigned int x, unsigned int y, unsigned int _taille, char _orientation)
      :pos_x(x), pos_y(y), taille(_taille), orientation(_orientation)
{

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
bool Bateau::get_existe()
{
    return existe;
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
//position par rapport a l'origine
void Bateau::set_etat(unsigned int pos){
  if(pos < get_taille()){
     etat[pos]=false;
  }
}
/*bool Bateau::is_dead(){
  bool f=false;
  for(unsigned int i =0 ; i < get_taille(); i++){
    f|=get_etat(i);
  }
  return f;
}*/
