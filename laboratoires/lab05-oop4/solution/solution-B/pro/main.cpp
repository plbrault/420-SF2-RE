#include <iostream>
#include <iomanip>
#include "goaltender.h"
#include "player.h"

int main () {
    Goaltender price("Carey", "Price");
    price.plays(true, false, 1, 26);
    price.plays(true, false, 0, 22);
    price.plays(true, true, 2, 19);
    price.plays(false, false, 4, 25);
    price.plays(true, false, 0, 27);
    price.plays(true, false, 3, 26);
    price.plays(false, true, 3, 41);
    price.plays(true, false, 1, 16);
    price.plays(true, false, 2, 31);
    price.plays(true, false, 4, 32);


    std::cout << std::setw(24) << "Nom"
    << std::setw(8) << std::right << "Partie"
    << std::setw(8) << std::right << "Vict."
    << std::setw(8) << std::right << "Déf."
    << std::setw(8) << std::right << "Pro."
    << std::setw(8) << std::right << "V/P"
    << std::setw(8) << std::right << "BC"
    << std::setw(8) << std::right << "TC"
    << std::setw(8) << std::right << "B/T"
    << std::setw(8) << std::right << "Scores" << std::endl;
    std::cout << price << std::endl;


    Player crosby("Center", "Sydney", "Crosby");
    crosby.plays(1, 0, 6, 1);
    crosby.plays(0, 3, 4, 0);
    crosby.plays(1, 1, 3, 0);
    crosby.plays(0, 1, 7, 0);
    crosby.plays(0, 0, 4, 2);
    crosby.plays(3, 0, 8, 0);
    crosby.plays(0, 0, 1, 0);
    crosby.plays(0, 2, 2, 0);
    crosby.plays(1, 1, 4, 0);
    crosby.plays(0, 0, 1, 0);
    std::cout << std::setw(24) << "Nom"
    << std::setw(8) << std::right << "Partie"
    << std::setw(8) << std::right << "But"
    << std::setw(8) << std::right << "Passe"
    << std::setw(8) << std::right << "Pts"
    << std::setw(8) << std::right << "Tir"
    << std::setw(8) << std::right << "Pré."
    << std::setw(8) << std::right << "Échap."
    << std::setw(8) << std::right << "Scores" << std::endl;
    std::cout << crosby << std::endl;

    return 0;
}