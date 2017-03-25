//
// Created by root on 3/24/17.
//

#ifndef BATAILLENAVALE_MYHELPERS_H
#define BATAILLENAVALE_MYHELPERS_H

#include "Bateau.h"
#include "Tire.h"
//Bateau select
class B_sel{
public :
    B_sel(Bateau *b, unsigned int x, unsigned int y);
    ~B_sel();

private:
    unsigned  int x,y;
    Bateau * attaquant;
};


#endif //BATAILLENAVALE_MYHELPERS_H
