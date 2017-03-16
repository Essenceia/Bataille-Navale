#include <cstdlib>
#include "../lib/crossplatform.h"
#include <iostream>
void clear_window()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
