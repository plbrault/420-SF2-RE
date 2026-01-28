#include "fonctions.h"
#include <fstream>
#include <iostream>

const double ZERO_ABSOLU = -273.15;
const double TEMPERATURE_DE_PLANCK = 1.416808e32;

double* chargerTemperatures(size_t &nbTemperatures, std::string nomFichier) {
    double* temperatures = nullptr;
    nbTemperatures = 0;

    std::ifstream fichierTemperatures;
    fichierTemperatures.open(nomFichier);
    if (!fichierTemperatures) {
        return temperatures;
    }

    while (!fichierTemperatures.eof()) {
        double temperatureLue;
        fichierTemperatures >> temperatureLue;

        double* temporaire = temperatures;
        temperatures = new double[nbTemperatures + 1];
        for (size_t i = 0; i < nbTemperatures; i++) {
            *(temperatures + i) = *(temporaire + i);
        }
        *(temperatures + nbTemperatures) = temperatureLue;
        delete[] temporaire;
        nbTemperatures++;
    }
    fichierTemperatures.close();
    return temperatures;
}

void afficherMenu() {
    std::cout   << std::endl << "MENU" << std::endl << "====================" << std::endl
                << "1. Afficher les températures en degrés Celsius" << std::endl
                << "2. Afficher les températures en Kelvin" << std::endl
                << "3. Calculer la température moyenne" << std::endl
                << "4. Ajouter une température" << std::endl
                << "5. Exporter les températures" << std::endl
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
    std::cout << std::endl;
    return choix;
}

void afficherTemperaturesCelsius(double temperatures[], size_t nbTemperatures) {
    for (size_t i = 0; i < nbTemperatures; i++) {
        std::cout << (i + 1) << ". " << temperatures[i] << '\370' << "C" << std::endl;
    }
}

void afficherTemperaturesKelvin(double temperatures[], size_t nbTemperatures) {
    for (size_t i = 0 ; i < nbTemperatures; i++) {
        double kelvin = temperatures[i] - ZERO_ABSOLU;
        std::cout << (i + 1) << ". " << kelvin << " K" << std::endl;
    }
}

double calculerTemperatureMoyenne(double temperatures[], size_t nbTemperatures) {
    double somme = 0;
    for (size_t i = 0; i < nbTemperatures; i++) {
        somme += temperatures[i];
    }
    return somme / nbTemperatures;
}

double* ajouterTemperature(double* temperatures, size_t &nbTemperatures) {
    double nouvelleTemperature;

    std::cout << "Entrez une nouvelle température en Celsius: ";
    std::cin >> nouvelleTemperature;

    if (nouvelleTemperature < ZERO_ABSOLU) {
        std::cout << "La température est trop petite." << std::endl;
        return temperatures;
    }
    if (nouvelleTemperature > TEMPERATURE_DE_PLANCK) {
        std::cout << "La température est trop grande." << std::endl;
        return temperatures;
    }

    double* temporaire = temperatures;
    temperatures = new double[nbTemperatures + 1];
    for (size_t i = 0; i < nbTemperatures; i++) {
        temperatures[i] = temporaire[i];
    }
    temperatures[nbTemperatures] = nouvelleTemperature;
    nbTemperatures++;
    delete[] temporaire;
    std::cout << "La température a été ajoutée." << std::endl;

    return temperatures;
}

void exporterTemperatures(double temperatures[], size_t nbTemperatures) {
    std::string nomFichier;
    std::cout << "Entrer le nom du fichier dans lequel enregistrer les températures: ";
    std::cin >> nomFichier;

    std::ofstream fichier(nomFichier);
    if (!fichier) {
        std::cout << "Erreur d'ouverture du fichier." << std::endl;
        return;
    }
    for (size_t i = 0; i < nbTemperatures; i++) {
        fichier << temperatures[i] << std::endl;
    }
    fichier.close();

    std::cout << "Les données ont été enregistrées dans " << nomFichier << "." << std::endl;
}
