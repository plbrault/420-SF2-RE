#include "TableauPeriodique.h"
#include <fstream>
#include <vector>

using namespace std;

TableauPeriodique::TableauPeriodique() {
    _parser.setDelimiter(';');
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
const Element& TableauPeriodique::trouverElementParSymbole(const std::string& symbole) const
{
    for (const Element& element : _elements) {
        if (element.getSymbole() == symbole) {
            return element;
        }
    }
    throw invalid_argument("Aucun élément trouvé avec le symbole donné.");
}

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

