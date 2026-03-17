#include "Element.h"

Element::Element(const std::string& nom, int numeroAtomique, const std::string& symbole, double masseAtomique) {
    this->_nom = nom;
    this->_numeroAtomique = numeroAtomique;
    this->_symbole = symbole;
    this->_masseAtomique = masseAtomique;
}

const std::string& Element::getNom() const {
    return this->_nom;
}

int Element::getNumeroAtomique() const {
    return this->_numeroAtomique;
}

const std::string& Element::getSymbole() const {
    return this->_symbole;
}

double Element::getMasseAtomique() const {
    return this->_masseAtomique;
}

void Element::setNom(const std::string& nom) {
    this->_nom = nom;
}

void Element::setNumeroAtomique(int numeroAtomique) {
    this->_numeroAtomique = numeroAtomique;
}

void Element::setSymbole(const std::string& symbole) {
    this->_symbole = symbole;
}

void Element::setMasseAtomique(double masseAtomique) {
    this->_masseAtomique = masseAtomique;
}
