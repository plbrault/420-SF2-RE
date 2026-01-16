#include "fonctions.h"
#include <fstream>
#include <iostream>

void afficherMenu() {
    std::cout   << std::endl << "MENU" << std::endl << "====================" << std::endl
                << "1. Afficher les températures en Celsius" << std::endl
                << "2. Afficher les températures en Kelvin" << std::endl
                << "3. Calculer la température moyenne" << std::endl
                << "4. Ajouter une température" << std::endl
                << "5. Enregistrer les températures" << std::endl
                << "6. Quitter" << std::endl;
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

void afficherTemperaturesCelsius(double temperatures[], int nbTemperatures) {
    for (size_t i = 0; i < nbTemperatures; i++) {
        std::cout << (i + 1) << ". " << temperatures[i] << '\370' << "C" << std::endl;
    }
}

void afficherTemperaturesKelvin(double temperatures[], int nbTemperatures) {
    for (size_t i = 0 ; i < nbTemperatures; i++) {
        double kelvin = temperatures[i] + 273.15;
        std::cout << (i + 1) << ". " << kelvin << " K" << std::endl;
    }
}

double calculerTemperatureMoyenne(double temperatures[], int nbTemperatures) {
    double somme = 0;
    for (size_t i = 0; i < nbTemperatures; i++) {
        somme += temperatures[i];
    }
    return somme / nbTemperatures;
}
