#include "fonctions.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void effacerEcran()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

Touche lireTouche()
{
#ifdef _WIN32
    if (_kbhit()) {
        int ch = _getch();
        if (ch == '+' || ch == '=') return Touche::PLUS;
        if (ch == '-' || ch == '_') return Touche::MOINS;
        if (ch == 'q' || ch == 'Q') return Touche::QUITTER;
        return Touche::AUCUNE;
    }
    return Touche::AUCUNE;
#else
    struct termios ancienTermios, nouveauTermios;
    tcgetattr(STDIN_FILENO, &ancienTermios);
    nouveauTermios = ancienTermios;
    nouveauTermios.c_lflag &= ~(ICANON | ECHO);
    nouveauTermios.c_cc[VMIN] = 0;
    nouveauTermios.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &nouveauTermios);

    char ch = 0;
    ssize_t n = read(STDIN_FILENO, &ch, 1);
    if (n <= 0) {
        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return Touche::AUCUNE;
    }

    if (ch == '+') {
        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return Touche::PLUS;
    }
    if (ch == '-') {
        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return Touche::MOINS;
    }
    if (ch == 'q' || ch == 'Q') {
        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return Touche::QUITTER;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
    return Touche::AUCUNE;
#endif
}
