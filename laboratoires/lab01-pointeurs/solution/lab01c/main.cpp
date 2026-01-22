#include <iostream>
#include <fstream>
#include "fonctions.h"

int main() {
    double* temperatures = nullptr;
    size_t nbTemperatures = 0;

    if (!chargerTemperatures(temperatures, nbTemperatures, CAPACITE_TEMPERATURES, "temperatures.txt")) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }
    int optionChoisie;
    do {
        afficherMenu();
        optionChoisie = demanderChoix(1, 6);

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
                ajouterTemperature(temperatures, nbTemperatures, CAPACITE_TEMPERATURES);
                break;
            case 5:
                exporterTemperatures(temperatures, nbTemperatures);
                break;
        }
    } while (optionChoisie != 6);

    std::cout << "Au revoir!";

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}