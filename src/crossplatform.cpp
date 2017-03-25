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
#ifndef WINDOWS

static struct termios old, nv;

/* Initialize nv terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    nv = old; /* make nv settings same as old settings */
    nv.c_lflag &= ~ICANON; /* disable buffered i/o */
    nv.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &nv); /* use these nv terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}
#endif

/* Read 1 character without echo */
char getcharacter(void)
{
#ifndef WINDOWS
    return getch_(0);
#else
    return getch();
#endif
}