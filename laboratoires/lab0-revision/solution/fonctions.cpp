#include "fonctions.h"
#include <fstream>
#include <iostream>

void afficherMenu() {
    std::cout   << "MENU" << std::endl << "====================" << std::endl
                << "1. Afficher les températures en Celsius" << std::endl
                << "2. Afficher les températures en Kelvin" << std::endl
                << "3. Calculer la température moyenne" << std::endl
                << "4. Ajouter une température" << std::endl
                << "5. Enregistrer les températures" << std::endl;
}

int demanderChoix(int min, int max) {
    int choix;
    do {
        std::cout << "Entrez un choix entre " << min << " et " << max << ": ";
        std::cin >> choix;

        if (choix < min || choix > max) {
            std::cout << "Votre choix est invalide." << std::endl;
        }
    } while (choix < min || choix > max);
    return choix;
}

void afficherTemperaturesCelsius(int temperatures[], int nbTemperatures) {
    for (int i = 0; i < nbTemperatures; i++) {
        std::cout << (i + 1) << ". " << temperatures[i] << '\370' << "C" << std::endl;
    }
}