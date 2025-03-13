#include "TableauPeriodique.h"
#include <fstream>
#include <vector>

using namespace std;

void TableauPeriodique::charger(const std::string& nomFichier) {
    ifstream elementsFile(nomFichier);
    if (!elementsFile.is_open()) {
        throw invalid_argument("Le fichier n'a pas pu etre ouvert.");
    }
    _parser.parse(elementsFile);
    elementsFile.close();

    _elements.clear();
    for (size_t i = 0; i < _parser.getNumRows(); i++) {
        Element element(
            _parser.getCell(i, "Nom"),
            _parser.getCell(i, "Symbole"),
            stoi(_parser.getCell(i, "Nombre de particules chargees")),
            stoi(_parser.getCell(i, "Nombre de trous")),
            _parser.getCell(i, "Groupe")
        );
        _elements.push_back(element);
    }
}

void TableauPeriodique::afficher(std::ostream& sortie) {
    for (Element element : _elements) {
        sortie << element << endl;
    }
}

ostream& operator<<(ostream& sortie, TableauPeriodique& tableauPeriodique) {
    tableauPeriodique.afficher(sortie);
    return sortie;
}