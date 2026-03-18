//
// Created by plbrault on 2026-03-17.
//

#include "Molecule.h"

Molecule::Molecule(const std::string& formule, const std::vector<Element>& elements, const std::vector<int>& nombreAtomes) {
    this->_formule = formule;
    for (size_t i = 0; i < elements.size(); ++i) {
        ElementMolecule elementMolecule;
        elementMolecule.element = elements[i];
        elementMolecule._nombreAtomes = nombreAtomes[i];
        this->_elements.push_back(elementMolecule);
    }
}

const std::string& Molecule::getFormule() const {
    return this->_formule;
}

size_t Molecule::getNombreElements() const {
    return this->_elements.size();
}

const Element& Molecule::getElement(size_t indice) const {
    return this->_elements[indice].element;
}

int Molecule::getNombreAtomes(size_t indice) const {
    return this->_elements[indice]._nombreAtomes;
}

int Molecule::getNombreAtomes(const std::string& symbole) const {
    for (const auto& elementMolecule : this->_elements) {
        if (elementMolecule.element.getSymbole() == symbole) {
            return elementMolecule._nombreAtomes;
        }
    }
    return 0;
}

int Molecule::getNombreAtomes(const Element& element) const {
    return this->getNombreAtomes(element.getSymbole());
}

std::ostream& operator<<(std::ostream& output, const Molecule& molecule) {
    output << molecule.getFormule();
    return output;
}
