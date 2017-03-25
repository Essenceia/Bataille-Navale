#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H
//#define WINDOWS
#ifdef WINDOWS
#include <conio.h>
#else
#include <termios.h>
#include <stdio.h>
#endif
void clear_window();
char getcharacter(void);

#endif
