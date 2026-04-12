#include "fonctions.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

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

const unsigned long TEMPS_PIC_MATIN = 5400;
const unsigned long TEMPS_PIC_APRES_MIDI = 18000;
const double SIGMA_MATIN = 2700.0;
const double SIGMA_APRES_MIDI = 3600.0;
const double TAUX_PIC_MATIN = 0.31;
const double TAUX_PIC_APRES_MIDI = 0.34;

double calculerTauxArrivee(unsigned long temps) {
    double t = static_cast<double>(temps);
    double tauxMatin = TAUX_PIC_MATIN * std::exp(-(std::pow(t - TEMPS_PIC_MATIN, 2)) / (2 * std::pow(SIGMA_MATIN, 2)));
    double tauxApresMidi = TAUX_PIC_APRES_MIDI * std::exp(-(std::pow(t - TEMPS_PIC_APRES_MIDI, 2)) / (2 * std::pow(SIGMA_APRES_MIDI, 2)));
    return tauxMatin + tauxApresMidi;
}
