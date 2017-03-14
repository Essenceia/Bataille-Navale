#ifndef CASETOUCHE_H_INCLUDED
#define CASETOUCHE_H_INCLUDED

#include "Objet.h"

class Casetouche:public Objet
{

    private :

    int NombreTouche;

    public :

    Casetouche(int x, int y);
    ~Casetouche();

    char Symbole();

};

#endif // CASETOUCHE_H_INCLUDED
