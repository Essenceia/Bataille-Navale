#include "../lib/Casetouche.h"

Casetouche::Casetouche(int x, int y)
        : Objet(x,y), NombreTouche(0)
{
}

Casetouche::~Casetouche()
{

}


///Methodes
char Casetouche::Symbole()
{
    return NombreTouche;
}
