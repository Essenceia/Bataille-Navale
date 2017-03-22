#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H
#define WINDOWS
#ifdef WINDOWS
#include <conio.h>
#else
#include <curses.h>
#endif
void clear_window();


#endif
