#include "Isotope.h"

Isotope::Isotope() {
    this->setNom("");
    this->setNbNeutron(0);
    this->setStable(false);
    this->setOccurence(0.0);
    this->setDemiVie(0.0);
    this->setMasse(0.0);
}

Isotope::Isotope(const std::string &nom, uint8_t nbNeutron, double occurence, double masse) {
    this->setNom(nom);
    this->setNbNeutron(nbNeutron);
    this->setStable(true);
    this->setOccurence(occurence);
    this->setMasse(masse);
}

Isotope::Isotope(const std::string &nom, uint8_t nbNeutron, double occurence, double demiVie, double masse) {
    this->setNom(nom);
    this->setNbNeutron(nbNeutron);
    this->setStable(false);
    this->setOccurence(occurence);
    this->setDemiVie(demiVie);
    this->setMasse(masse);
}

std::string Isotope::getNom() const {
    return this->_nom;
}

uint8_t Isotope::getNbNeutron() const {
    return this->_nbNeutron;
}

double Isotope::getOccurence() const {
    return this->_occurence;
}

bool Isotope::isStable() const {
    return this->_stable;
}

double Isotope::getDemiVie() const {
    return this->_demiVie;
}

double Isotope::getMasse() const {
    return this->_masse;
}

void Isotope::setNom(const std::string &nom) {
    this->_nom = nom;
}

void Isotope::setNbNeutron(uint8_t nbNeutron) {
    this->_nbNeutron = nbNeutron;
}

void Isotope::setOccurence(double occurence) {
    this->_occurence = occurence;
}

void Isotope::setStable(bool stable) {
    this->_stable = stable;
}

void Isotope::setDemiVie(double demiVie) {
    this->_demiVie = demiVie;
}

void Isotope::setMasse(double masse) {
    this->_masse = masse;
}
