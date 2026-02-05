#include <iostream>
#include <iomanip>
#include "fonctions.h"

void afficherElement(const Element& element) {
    std::cout << "----------------" << std::endl;
    std::cout << "| " << std::left << std::setw(5) << element.getSymbole()
              << std::right << std::setw(6) << element.getGroupe() << "  |" << std::endl;
    std::cout << "| " << std::left << std::setw(12) << element.getNom() << " |" << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "| " << std::left << std::setw(5) << element.getNombreIsotopes()
              << std::right << std::setw(6) << element.getNumeroAtomique() << "  |" << std::endl;
    std::cout << "----------------" << std::endl;
}
