#include <iostream>
#include <fstream>
#include "fonctions.h"

#define CAPACITE_TEMPERATURES 100

int main() {
    int temperatures[CAPACITE_TEMPERATURES];
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

    afficherMenu();

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}