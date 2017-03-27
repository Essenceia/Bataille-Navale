#include "../lib/Allegro.h"

//Constructeur par d�fault
Allegro::Allegro()
{

}

//Destructeur
Allegro::~Allegro()
{

}

void Allegro::clearbmp()
{
    clear_bitmap(page);
}

void Allegro::ChargerImages()
{

    // Cr�ation du buffer d'affichage
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    tampon=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(tampon);

    tampon2=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(tampon2);


    // charger les images
    fond=load_bitmap("../Bitmap/fond.bmp",NULL);
    if (!fond)
    {
        allegro_message("pas pu trouver Bitmap/fond.bmp");
        exit(EXIT_FAILURE);
    }
    victoire=load_bitmap("../Bitmap/victoire.bmp",NULL);
    if (!victoire)
    {
        allegro_message("pas pu trouver Bitmap/victoire.bmp");
        exit(EXIT_FAILURE);
    }
    defaite=load_bitmap("../Bitmap/defaite.bmp",NULL);
    if (!defaite)
    {
        allegro_message("pas pu trouver Bitmap/defaite.bmp");
        exit(EXIT_FAILURE);
    }
    selun=load_bitmap("../Bitmap/select1x1.bmp",NULL);
    if (!selun)
    {
        allegro_message("pas pu trouver Bitmap/select1x1.bmp");
        exit(EXIT_FAILURE);
    }
    seldeux=load_bitmap("../Bitmap/select2x2.bmp",NULL);
    if (!seldeux)
    {
        allegro_message("pas pu trouver Bitmap/select2x2.bmp");
        exit(EXIT_FAILURE);
    }
    seltrois=load_bitmap("../Bitmap/select3x3.bmp",NULL);
    if (!seltrois)
    {
        allegro_message("pas pu trouver Bitmap/select3x3.bmp");
        exit(EXIT_FAILURE);
    }
    selquatre=load_bitmap("../Bitmap/select4x4.bmp",NULL);
    if (!selquatre)
    {
        allegro_message("pas pu trouver Bitmap/select4x4.bmp");
        exit(EXIT_FAILURE);
    }
    bout=load_bitmap("../Bitmap/bout.bmp",NULL);
    if (!bout)
    {
        allegro_message("pas pu trouver Bitmap/bout.bmp");
        exit(EXIT_FAILURE);
    }
    corps=load_bitmap("../Bitmap/corps.bmp",NULL);
    if (!corps)
    {
        allegro_message("pas pu trouver Bitmap/corps.bmp");
        exit(EXIT_FAILURE);
    }
    sousmarin=load_bitmap("../Bitmap/sousmarin.bmp",NULL);
    if (!sousmarin)
    {
        allegro_message("pas pu trouver Bitmap/sousmarin.bmp");
        exit(EXIT_FAILURE);
    }
    boum=load_bitmap("../Bitmap/boum.bmp",NULL);
    if (!boum)
    {
        allegro_message("pas pu trouver Bitmap/boum.bmp");
        exit(EXIT_FAILURE);
    }
    epave=load_bitmap("../Bitmap/epave.bmp",NULL);
    if (!epave)
    {
        allegro_message("pas pu trouver Bitmap/epave.bmp");
        exit(EXIT_FAILURE);
    }
    repere=load_bitmap("../Bitmap/repere.bmp",NULL);
    if (!repere)
    {
        allegro_message("pas pu trouver Bitmap/repere.bmp");
        exit(EXIT_FAILURE);
    }
    choixaction=load_bitmap("../Bitmap/choixaction.bmp",NULL);
    if (!choixaction)
    {
        allegro_message("pas pu trouver Bitmap/choixaction.bmp");
        exit(EXIT_FAILURE);
    }
    mauvais=load_bitmap("../Bitmap/mauvais.bmp",NULL);
    if (!mauvais)
    {
        allegro_message("pas pu trouver Bitmap/mauvais.bmp");
        exit(EXIT_FAILURE);
    }
    nopivot=load_bitmap("../Bitmap/nopivot.bmp",NULL);
    if (!nopivot)
    {
        allegro_message("pas pu trouver Bitmap/nopivot.bmp");
        exit(EXIT_FAILURE);
    }
    chgmnt=load_bitmap("../Bitmap/chgmnt.bmp",NULL);
    if (!chgmnt)
    {
        allegro_message("pas pu trouver Bitmap/chgmnt.bmp");
        exit(EXIT_FAILURE);
    }
    cache=load_bitmap("../Bitmap/cache.bmp",NULL);
    if (!cache)
    {
        allegro_message("pas pu trouver Bitmap/cache.bmp");
        exit(EXIT_FAILURE);
    }
}

void Allegro::DestroyImages()
{
    destroy_bitmap(page);
    destroy_bitmap(fond);
    destroy_bitmap(tampon);
    destroy_bitmap(tampon2);
    destroy_bitmap(victoire);
    destroy_bitmap(defaite);
    destroy_bitmap(selun);
    destroy_bitmap(seldeux);
    destroy_bitmap(seltrois);
    destroy_bitmap(selquatre);
    destroy_bitmap(bout);
    destroy_bitmap(corps);
    destroy_bitmap(sousmarin);
    destroy_bitmap(boum);
    destroy_bitmap(epave);
    destroy_bitmap(repere);
    destroy_bitmap(choixaction);
    destroy_bitmap(mauvais);
    destroy_bitmap(nopivot);
    destroy_bitmap(chgmnt);
    destroy_bitmap(cache);
}


BITMAP* Allegro::getImage(int i)
{

    //choix de la bitmap � charger
    switch(i)
    {
        case 0 :    return page;
        case 1 :    return fond;
        case 2 :    return tampon;
        case 3 :    return tampon2;
        case 4 :    return cache;

        case 10 :    return choixaction;
        case 11 :    return mauvais;
        case 12 :    return nopivot;

        case 51 :    return selun;
        case 52 :    return seldeux;
        case 53 :    return seltrois;
        case 54 :    return selquatre;

        case 60 :   return bout;
        case 61 :   return corps;
        case 62 :   return sousmarin;
        case 63 :   return epave;

        case 70 :   return boum;
        case 71 :   return repere;

        case 90 :    return chgmnt;
        case 91 :    return victoire;
        case 92 :    return defaite;

        default :   allegro_exit();
                    exit(EXIT_FAILURE);

    }

}
