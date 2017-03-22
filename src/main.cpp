#define USINGALLEGRO
#define WINDOWS
#define DEBUG //activer le debug
#ifdef WINDOWS
#include <conio.h>
#endif

#ifdef USINGALLEGRO
#include <allegro.h>
#include <winalleg.h>
#include "../lib/Allegro.h"
#endif // USINGALLEGRO
#include "../lib/Menu.h"

int main()
{
    Menu menu;
    menu.Allegro_present();
#ifdef USINGALLEGRO
    if(menu.getallegro_present())
    {
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

        // Montrer la souris � l'�cran
        show_mouse(screen);


        //Initialisation Menu
        menu.load_bitmaps(); //chargement des bitmaps du menu
    }
    #endif


    menu.principal();
#ifdef USINGALLEGRO
    if(menu.getallegro_present())   menu.destroy_bitmaps();
#endif // USINGALLEGRO
    return 0;
}
#ifdef USINGALLEGRO
END_OF_MAIN();
#endif //USINGALLEGRO
