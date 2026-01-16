#include <iostream>
#include <fstream>
#include "fonctions.h"

#define CAPACITE_TEMPERATURES 100

int main() {
    double temperatures[CAPACITE_TEMPERATURES];
    int nbTemperatures = 0;
    std::ifstream fichierTemperatures;

    fichierTemperatures.open("temperatures.txt");
    if (!fichierTemperatures) {
        std::cout << "Erreur: le fichier n'existe pas." << std::endl;
        exit(1);
    }

    while (!fichierTemperatures.eof() && nbTemperatures < CAPACITE_TEMPERATURES) {
        fichierTemperatures >> temperatures[nbTemperatures];
        nbTemperatures++;
    }

    int optionChoisie;
    do {
        afficherMenu();
        int optionChoisie = demanderChoix(1, 6);

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
        }
    } while (optionChoisie != 6);

    std::cout << "Au revoir!";

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}