//
// Created by root on 3/24/17.
//
#include "myhelpers.h"

Bateau::Bateau(Bateau *bat, unsigned int posx, unsigned int posy):x(posx),y(posy),b(bat)
{//TODO : To string
    std::cout<< " Nous venons de cree un Bateau de type : "+ bat->symbole +" attacquant les coordones "+x+" "+y<<std::endl;
}
Bateau::~Bateau() {
    //Attention , il ne fait pas free bat 
}
