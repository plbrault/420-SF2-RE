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
        if (ch == 0 || ch == 0xE0) {
            if (_kbhit()) {
                int ch2 = _getch();
                if (ch2 == 77) return Touche::DROITE;
                if (ch2 == 75) return Touche::GAUCHE;
            }
            return Touche::QUITTER;
        }
        return Touche::QUITTER;
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

    if (ch == '\x1b') {
        char seq[2] = {0};
        ssize_t n1 = read(STDIN_FILENO, &seq[0], 1);
        if (n1 > 0 && seq[0] == '[') {
            usleep(1000);
            ssize_t n2 = read(STDIN_FILENO, &seq[1], 1);
            if (n2 > 0) {
                if (seq[1] == 'C') {
                    tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
                    return Touche::DROITE;
                }
                if (seq[1] == 'D') {
                    tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
                    return Touche::GAUCHE;
                }
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
        return Touche::QUITTER;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ancienTermios);
    return Touche::QUITTER;
#endif
}
