#include "TableauPeriodique.h"
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#define COL_WIDTH 16

TableauPeriodique::TableauPeriodique() {
    _parser.setDelimiter(';');
    this->_estTrieParNom = false;
}

void TableauPeriodique::charger(const std::string& nomFichier) {
    ifstream elementsFile(nomFichier);
    if (!elementsFile.is_open()) {
        throw invalid_argument("Le fichier n'a pas pu être ouvert.");
    }
    _parser.parse(elementsFile);
    elementsFile.close();

    _elements.clear();
    for (size_t i = 0; i < _parser.getNumRows(); i++) {
        Element element(
            _parser.getString(i, "Nom de l'element"),
            _parser.getInt(i, "Numero atomique"),
            _parser.getString(i, "Symbole"),
            _parser.getDouble(i, "Masse atomique")
        );
        _elements.push_back(element);
    }
}

void TableauPeriodique::afficher(std::ostream& sortie) {
    for (Element element : this->_elements) {
        std::cout << "| " << std::left << std::setw(COL_WIDTH) << element.getNom();
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << element.getNumeroAtomique();
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << element.getSymbole();
        std::cout << " | " << std::right << std::setw(COL_WIDTH) << element.getMasseAtomique();

        std::cout << " | " << std::endl;
    }
}
//
// ostream& operator<<(ostream& sortie, TableauPeriodique& tableauPeriodique) {
//     tableauPeriodique.afficher(sortie);
//     return sortie;
// }
//
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
        while (j > 0 && _elements[j - 1].getNumeroAtomique() > element.getNumeroAtomique()) {
            _elements[j] = _elements[j - 1];
            j--;
        }
        _elements[j] = element;
    }
    _estTrieParNom = false;
}

const Element& TableauPeriodique::trouverElementParSymbole(const std::string& symbole) const
{
    for (const Element& element : _elements) {
        if (element.getSymbole() == symbole) {
            return element;
        }
    }
    throw invalid_argument("Aucun élément trouvé avec le symbole donné.");
}

// const Element* TableauPeriodique::getElementParNom(const std::string& nom) const {
//     if (_estTrieParNom) {
//         // Recherche dichotomique
//         size_t debut = 0;
//         size_t fin = _elements.size() - 1;
//         while (debut <= fin) {
//             size_t milieu = (debut + fin) / 2;
//             if (_elements[milieu].getNom() == nom) {
//                 return &_elements[milieu];
//             } else if (nom > _elements[milieu].getNom()) {
//                 debut = milieu + 1;
//             } else {
//                 fin = milieu - 1;
//             }
//         }
//     } else {
//         // Recherche séquentielle
//         for (const Element& element : _elements) {
//             if (element.getNom() == nom) {
//                 return &element;
//             }
//         }
//     }
//     return nullptr;
// }

Molecule TableauPeriodique::creerMolecule(const std::string& formule) const {
    vector<Element> elements;
    vector<int> nombreAtomes;

    size_t i = 0;
    while (i < formule.size())
    {
        if (isalpha(formule[i])) {
            string symbole(1, formule[i]);
            i++;
            if (i < formule.size() && isalpha(formule[i]) && islower(formule[i])) {
                symbole += formule[i];
                i++;
            }
            const Element& element = this->trouverElementParSymbole(symbole);
            elements.push_back(element);

            int nombre = 0;
            while (i < formule.size() && isdigit(formule[i])) {
                nombre = nombre * 10 + (formule[i] - '0');
                i++;
            }
            if (nombre == 0) {
                nombre = 1;
            }
            nombreAtomes.push_back(nombre);
        } else {
            throw invalid_argument("Formule chimique invalide.");
        }
    }

    return Molecule(formule, elements, nombreAtomes);
}

