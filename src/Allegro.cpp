#ifdef USINGALLEGRO
#include "../lib/Allegro.h"

//Constructeur par d�fault
Allegro::Allegro()
{

}

//Destructeur
Allegro::~Allegro()
{

}

void Allegro::ChargerImages()
{

    // Cr�ation du buffer d'affichage
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);


    // charger les images
    fond=load_bitmap("Bitmap/fond.bmp",NULL);
    if (!fond)
    {
        allegro_message("pas pu trouver Bitmap/fond.bmp");
        exit(EXIT_FAILURE);
    }
    victoire=load_bitmap("Bitmap/victoire.bmp",NULL);
    if (!victoire)
    {
        allegro_message("pas pu trouver Bitmap/victoire.bmp");
        exit(EXIT_FAILURE);
    }
    defaite=load_bitmap("Bitmap/defaite.bmp",NULL);
    if (!defaite)
    {
        allegro_message("pas pu trouver Bitmap/defaite.bmp");
        exit(EXIT_FAILURE);
    }
}

void Allegro::DestroyImages()
{
    destroy_bitmap(page);
    destroy_bitmap(fond);
    destroy_bitmap(victoire);
    destroy_bitmap(defaite);
}


BITMAP* Allegro::getImage(int i)
{

    //choix de la bitmap � charger
    switch(i)
    {
        case 0 :    return page;
        case 1 :    return fond;
        case 98 :    return victoire;
        case 99 :    return defaite;
        default :   allegro_exit();
                    exit(EXIT_FAILURE);

    }

}
#endif //USINGALLEGRO
