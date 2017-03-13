#include <conio.h>
#include <allegro.h>
#include <winalleg.h>

#include "Allegro.h"
#include "Menu.h"

int main()
{

    Menu menu;

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_sound(DIGI_AUTODETECT , MIDI_AUTODETECT ,0);

    // Montrer la souris à l'écran
    show_mouse(screen);


    //Initialisation Menu
    menu.load_bitmaps(); //chargement des bitmaps du menu

    menu.principal();

    menu.destroy_bitmaps();

    return 0;
}
END_OF_MAIN();
