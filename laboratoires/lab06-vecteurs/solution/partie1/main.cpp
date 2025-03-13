#include <iostream>
#include <fstream>
#include "CSVParser.h"

using namespace std;

int main() {
    CSVParser parser;

    ifstream elementsFile("elements.csv");
    if (!elementsFile.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return 1;
    }

    parser.parse(elementsFile);

    elementsFile.close();

    cout << "Nombre de lignes : " << parser.getNumRows() << endl;
    cout << parser.getCell(0, "Symbole") << endl;
}