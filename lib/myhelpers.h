//
// Created by root on 3/24/17.
//

#ifndef BATAILLENAVALE_MYHELPERS_H_H
#define BATAILLENAVALE_MYHELPERS_H_H

#include "Bateau.h"
#include "Tire.h"
typedef struct {
    unsigned  int x,y;
    Bateau * attaquant;
    Tire * arme;
}Bateau_select;


#endif //BATAILLENAVALE_MYHELPERS_H_H
