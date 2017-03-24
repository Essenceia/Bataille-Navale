#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H
//#define WINDOWS
#define FLEMME
#ifdef WINDOWS
#include <conio.h>
#else
#ifndef  FLEMME
#include <curses.h>
#endif
#endif
void clear_window();


#endif
