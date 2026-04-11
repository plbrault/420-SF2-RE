#include "fonctions.h"
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#endif

void effacerEcran()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

bool touchePressee()
{
    #ifdef _WIN32
        return _kbhit() != 0;
    #else
        struct termios ancienTermios, nouveauTermios;
        tcgetattr(STDIN_FILENO, &ancienTermios);
        nouveauTermios = ancienTermios;
        nouveauTermios.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &nouveauTermios);

        struct timeval timeout = {0, 0};
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        int resultat = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout);

        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return resultat > 0;
    #endif
}
