#include "Element.h"

Element::Element() {
    this->_symbole = "";
    this->_nom = "(Élément sans nom)";
    this->_numeroAtomique = 0;
    this->_groupe = 0;
    this->_capaciteIsotopes = 2;
    this->_nombreIsotopes = 0;
    this->_isotopes = new Isotope[this->_capaciteIsotopes];
}

Element::Element(std::string symbole, std::string nom, int numeroAtomique, int groupe) : Element() {
    this->setSymbole(symbole);
    this->setNom(nom);
    this->setNumeroAtomique(numeroAtomique);
    this->setGroupe(groupe);
}

Element::Element(const Element& autreElement) {
    this->_symbole = autreElement._symbole;
    this->_nom = autreElement._nom;
    this->_numeroAtomique = autreElement._numeroAtomique;
    this->_groupe = autreElement._groupe;
    this->_capaciteIsotopes = autreElement._capaciteIsotopes;
    this->_nombreIsotopes = autreElement._nombreIsotopes;

    this->_isotopes = new Isotope[this->_capaciteIsotopes];
    for (size_t i = 0; i < this->_nombreIsotopes; i++) {
        this->_isotopes[i] = autreElement._isotopes[i];
    }
}

Element::~Element() {
    delete[] this->_isotopes;
}

void Element::ajouterIsotope(Isotope isotope) {
    if (this->_nombreIsotopes == this->_capaciteIsotopes) {
        Isotope* nouveauTableau = new Isotope[2 * this->_capaciteIsotopes];
        for (size_t i = 0; i < this->_capaciteIsotopes; i++) {
            nouveauTableau[i] = this->_isotopes[i];
        }
        delete[] this->_isotopes;
        this->_isotopes = nouveauTableau;
        this->_capaciteIsotopes *= 2;
    }
    this->_isotopes[this->_nombreIsotopes] = isotope;
    this->_nombreIsotopes++;
}

std::string Element::getSymbole() const {
    return this->_symbole;
}

std::string Element::getNom() const {
    return this->_nom;
}

int Element::getNumeroAtomique() const {
    return this->_numeroAtomique;
}

int Element::getGroupe() const {
    return this->_groupe;
}

size_t Element::getNombreIsotopes() const {
    return this->_nombreIsotopes;
}

Isotope* Element::getIsotope(size_t indice) const {
    if (indice < this->_nombreIsotopes) {
        return this->_isotopes + indice;
    }
    return nullptr;
}

void Element::setSymbole(std::string symbole) {
    this->_symbole = symbole;
}

void Element::setNom(std::string nom) {
    this->_nom = nom;
}

void Element::setNumeroAtomique(int numeroAtomique) {
    this->_numeroAtomique = numeroAtomique;
}

void Element::setGroupe(int groupe) {
    this->_groupe = groupe;
}

bool Element::aIsotopeStable() const {
    for (size_t i = 0; i < this->_nombreIsotopes; i++) {
        if (this->_isotopes[i].estStable()) {
            return true;
        }
    }
    return false;
}
