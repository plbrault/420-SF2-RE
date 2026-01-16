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