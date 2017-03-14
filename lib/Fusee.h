#ifndef FUSEE_H_INCLUDED
#define FUSEE_H_INCLUDED

#include "Objet.h"

class Fusee:public Objet
{

    private :

    bool existe;

    public :

    Fusee(int x, int y);
    ~Fusee();

};

#endif // FUSEE_H_INCLUDED
