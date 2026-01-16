#include <iostream>
#include <fstream>
#include "fonctions.h"

const size_t CAPACITE_TEMPERATURES = 100;

int main() {
    double temperatures[CAPACITE_TEMPERATURES];
    size_t nbTemperatures = 0;

    chargerTemperatures(temperatures, nbTemperatures, CAPACITE_TEMPERATURES, "temperatures.txt");

    return 0;
}