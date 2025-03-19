#include "TableauPeriodique.h"
#include <fstream>
#include <vector>

using namespace std;

TableauPeriodique::TableauPeriodique() {
    _parser.setDelimiter(';');
    _estTrieParNom = false;
}

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
            _parser.getString(i, "Nom"),
            _parser.getString(i, "Symbole"),
            _parser.getInt(i, "Numero atomique"),
            _parser.getInt(i, "Nombre de trous"),
            _parser.getString(i, "Groupe")
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

void TableauPeriodique::trierParNom() {
    // Tri à bulles
    for (size_t i = _elements.size() - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (_elements[j + 1].getNom() < _elements[j].getNom()) {
                swap(_elements[j + 1], _elements[j]);
            }
        }
    }
    _estTrieParNom = true;
}

void TableauPeriodique::trierParNumeroAtomique() {
    // Tri par insertion
    for (size_t i = 1; i < _elements.size(); i++) {
        Element element = _elements[i];
        size_t j = i;
        while (j > 0 && _elements[j - 1].getNombreParticulesChargees() > element.getNombreParticulesChargees()) {
            _elements[j] = _elements[j - 1];
            j--;
        }
        _elements[j] = element;
    }
    _estTrieParNom = false;
}

const Element* TableauPeriodique::getElementParNom(const std::string& nom) const {
    if (_estTrieParNom) {
        // Recherche dichotomique
        size_t debut = 0;
        size_t fin = _elements.size() - 1;
        while (debut <= fin) {
            size_t milieu = (debut + fin) / 2;
            if (_elements[milieu].getNom() == nom) {
                return &_elements[milieu];
            } else if (nom > _elements[milieu].getNom()) {
                debut = milieu + 1;
            } else {
                fin = milieu - 1;
            }
        }
    } else {
        // Recherche séquentielle
        for (const Element& element : _elements) {
            if (element.getNom() == nom) {
                return &element;
            }
        }
    }
    return nullptr;
}