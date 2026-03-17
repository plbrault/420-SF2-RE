#include <iostream>
#include <fstream>
#include <iomanip>
#include "CSVParser.h"

#define COL_WIDTH 16

int main() {
    std::ifstream file;
    file.open("../elements.csv");
    if (!file.is_open()) {
        std::cerr << "L'ouverture du fichier a échoué." << std::endl;
        return 1;
    }

    CSVParser parser(';', true);

    parser.parse(file);

    std::cout << "| ";
    for (size_t i = 0; i < parser.getNumColumns(); i++) {
        std::cout << std::left << std::setw(COL_WIDTH) << parser.getColumnNames()[i] << " | ";
    }

    std::cout << std::endl;
    for (size_t i = 0; i < parser.getNumColumns(); i++) {
        std::cout << "|" << std::string(COL_WIDTH + 2, '-');
    }
    std::cout << "|" << std::endl;

    for (size_t i = 0; i < parser.getNumRows(); i++) {
        // Nom de l'élément
        std::cout << "| " << std::left << std::setw(COL_WIDTH) << parser.getString(i, 0);
        // Numéro atomique
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << parser.getInt(i, 1);
        // Symbole
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << parser.getString(i, 2);
        // Masse atomique
        std::cout << " | " << std::right << std::setw(COL_WIDTH) << parser.getDouble(i, 3);

        std::cout << " | " << std::endl;
    }

    std::cout << std::string((COL_WIDTH + 3) * parser.getNumColumns() + 1, '-') << std::endl;

    return 0;
}