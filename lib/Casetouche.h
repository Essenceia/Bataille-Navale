#ifndef CASETOUCHE_H_INCLUDED
#define CASETOUCHE_H_INCLUDED

#include "Objet.h"

class Casetouche:public Objet
{

    private :

    int NombreTouche;

    public :

    Casetouche(int x, int y)__attribute__((depricated));
    ~Casetouche();

    char Symbole()__attribute__((depricated));

};

#endif // CASETOUCHE_H_INCLUDED
