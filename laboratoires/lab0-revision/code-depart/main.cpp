#include <iostream>
#include <fstream>
#include "fonctions.h"

const size_t CAPACITE_TEMPERATURES = 100;

int main() {
    double temperatures[CAPACITE_TEMPERATURES];
    size_t nbTemperatures = 0;

    if (!chargerTemperatures(temperatures, nbTemperatures, CAPACITE_TEMPERATURES, "temperatures.txt")) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    return 0;
}