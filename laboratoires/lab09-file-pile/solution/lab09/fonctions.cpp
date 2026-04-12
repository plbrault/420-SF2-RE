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

const unsigned long TEMPS_PIC_MATIN = 5400;
const unsigned long TEMPS_PIC_APRES_MIDI = 18000;
const double SIGMA_MATIN = 2700.0;
const double SIGMA_APRES_MIDI = 3600.0;
const double TAUX_PIC_MATIN = 8.0;
const double TAUX_PIC_APRES_MIDI = 10.0;

double calculerTauxArrivee(unsigned long temps) {
    double t = static_cast<double>(temps);
    double tauxMatin = TAUX_PIC_MATIN * std::exp(-(std::pow(t - TEMPS_PIC_MATIN, 2)) / (2 * std::pow(SIGMA_MATIN, 2)));
    double tauxApresMidi = TAUX_PIC_APRES_MIDI * std::exp(-(std::pow(t - TEMPS_PIC_APRES_MIDI, 2)) / (2 * std::pow(SIGMA_APRES_MIDI, 2)));
    return tauxMatin + tauxApresMidi;
}
