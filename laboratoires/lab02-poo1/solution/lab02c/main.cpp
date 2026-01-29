#include <iostream>
#include <fstream>
#include "fonctions.h"
#include "Menu.h"

int main() {
    double* temperatures = nullptr;
    size_t nbTemperatures = 0;
    Menu menu(true);

    menu.ajouterOption("Afficher les températures en degrés Celsius");
    menu.ajouterOption("Afficher les températures en Kelvin");
    menu.ajouterOption("Calculer la température moyenne");
    menu.ajouterOption("Ajouter une température");
    menu.ajouterOption("Exporter les températures");

    temperatures = chargerTemperatures(nbTemperatures, "temperatures.txt");
    if (temperatures == nullptr) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }
    int optionChoisie;
    do {
        afficherMenu(menu);
        optionChoisie = menu.demanderChoix();

        switch (optionChoisie) {
            case 1:
                afficherTemperaturesCelsius(temperatures, nbTemperatures);
                break;
            case 2:
                afficherTemperaturesKelvin(temperatures, nbTemperatures);
                break;
            case 3:
                std::cout << "La température moyenne est de "
                    << calculerTemperatureMoyenne(temperatures, nbTemperatures)
                    << '\370' << "C"
                    << std::endl;
                break;
            case 4:
                temperatures = ajouterTemperature(temperatures, nbTemperatures);
                break;
            case 5:
                exporterTemperatures(temperatures, nbTemperatures);
                break;
        }
    } while (!menu.estQuitter(optionChoisie));

    std::cout << "Au revoir!";

    delete[] temperatures;

    return 0;
}