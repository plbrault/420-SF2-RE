#include "Element.h"

#include <iomanip>
#include <sstream>

Element::Element(const std::string &nom, const std::string &symbole, uint8_t nbParticule, uint8_t nbTrou, const std::string &groupe) {
    this->_nom = nom;
    this->_symbole = symbole;
    this->_nbParticuleChargee = nbParticule;
    this->_nbTrou = nbTrou;
    this->_groupe = groupe;

    this->_capaciteIsotopes = ISOTOPE_CAPACITE_INCREMENT;
    this->_qtIsotopes = 0;
    this->_isotopes = new Isotope[this->_capaciteIsotopes];
}

Element::Element(const Element &element) {
    this->_nom = element._nom;
    this->_symbole = element._symbole;
    this->_nbParticuleChargee = element._nbParticuleChargee;
    this->_nbTrou = element._nbTrou;
    this->_groupe = element._groupe;

    this->_capaciteIsotopes = element._capaciteIsotopes;
    this->_isotopes = new Isotope[this->_capaciteIsotopes];
    this->_qtIsotopes = element._qtIsotopes;
    for (size_t i = 0; i < this->_capaciteIsotopes; i++) {
        this->_isotopes[i] = element._isotopes[i];
    }
}

Element::~Element() {
    if (this->_isotopes != nullptr) {
        delete [] this->_isotopes;
    }
}

Element &Element::operator=(const Element &element) {
    if (this == &element) {
        return *this;
    }

    this->_nom = element._nom;
    this->_groupe = element._groupe;
    this->_nbParticuleChargee = element._nbParticuleChargee;
    this->_nbTrou = element._nbTrou;
    this->_symbole = element._symbole;
    this->_qtIsotopes = element._qtIsotopes;
    this->_capaciteIsotopes = element._capaciteIsotopes;
    delete[] this->_isotopes;
    this->_isotopes = new Isotope[this->_capaciteIsotopes];
    for (size_t i = 0; i < this->_qtIsotopes; i++) {
        this->_isotopes[i] = element._isotopes[i];
    }

    return *this;
}

void Element::ajouterIsotope(const Isotope &isotope) {
    this->_isotopes[this->_qtIsotopes] = isotope;
    this->_qtIsotopes++;
    if (this->_qtIsotopes == this->_capaciteIsotopes) {
        this->_agrandirTableauIsotope();
    }
}

bool Element::aIsotopeStable() const {
    bool found = false;
    size_t count = 0;

    while (!found && count < this->_qtIsotopes) {
        if (this->_isotopes[count].isStable()) {
            found = true;
        } else {
            count++;
        }
    }

    return found;
}

size_t Element::nbIsotope() const {
    return this->_qtIsotopes;
}

std::string Element::toString() const {
    std::ostringstream flux;

    // Prepare the symbol and group text
    std::string sym = this->_symbole.substr(0, 2);
    std::string grp = this->_groupe.substr(0, 4);

    // Prepare the name (fits within 11 characters)
    std::string name = this->_nom.substr(0, 11);

    // Print the formatted box
    flux << "---------------\n";
    flux << "| " << std::setw(2) << std::left << sym << "     "
           << std::setw(4) << std::right << grp << " |\n";
    flux << "| " << std::setw(11) << std::left << name << " |\n";
    flux << "|             |\n";
    flux << "| " << std::setw(2) << std::left << (int)_qtIsotopes
           << "        " << std::setw(2) << std::right << (int)_nbParticuleChargee << " |\n";
    flux << "---------------\n";

    return flux.str();
}

void Element::_agrandirTableauIsotope() {
    if (this->_qtIsotopes == this->_capaciteIsotopes) {
        this->_capaciteIsotopes += ISOTOPE_CAPACITE_INCREMENT;
        Isotope *temp = new Isotope[this->_capaciteIsotopes];
        for (size_t i = 0; i < this->_qtIsotopes; i++) {
            temp[i] = this->_isotopes[i];
        }
        delete [] this->_isotopes;
        this->_isotopes = temp;
        temp = nullptr;
    }
}

std::ostream &operator<<(std::ostream &flux, const Element &element) {
    flux << element.toString();
    return flux;
}

const std::string& Element::getNom() const {
    return this->_nom;
}

uint8_t Element::getNombreParticulesChargees() const {
    return this->_nbParticuleChargee;
}
