#include "Isotope.h"

Isotope::Isotope() {
    this->_nom = "(Isotope sans nom)";
    this->_nbNeutrons = 0;
    this->_occurence = 0;
    this->_demiVie = std::numeric_limits<double>::infinity();
    this->_masse = 0;
}

Isotope::Isotope(std::string nom, int nbNeutrons, double occurence, double masse) {
    this->setNom(nom);
    this->setNbNeutrons(nbNeutrons);
    this->setOccurence(occurence);
    this->setDemiVie(std::numeric_limits<double>::infinity());
    this->setMasse(masse);
}

Isotope::Isotope(std::string nom, int nbNeutrons, double occurence, double demiVie, double masse) {
    this->setNom(nom);
    this->setNbNeutrons(nbNeutrons);
    this->setOccurence(occurence);
    this->setDemiVie(demiVie);
    this->setMasse(masse);
}

std::string Isotope::getNom() const {
    return this->_nom;
}

int Isotope::getNbNeutrons() const {
    return this->_nbNeutrons;
}

double Isotope::getOccurence() const {
    return this->_occurence;
}

double Isotope::getDemiVie() const {
    return this->_demiVie;
}

double Isotope::getMasse() const {
    return this->_masse;
}

void Isotope::setNom(std::string nom) {
    this->_nom = nom;
}

void Isotope::setNbNeutrons(int nbNeutrons) {
    this->_nbNeutrons = nbNeutrons;
}

void Isotope::setOccurence(double occurence) {
    this->_occurence = occurence;
}

void Isotope::setDemiVie(double demiVie) {
    this->_demiVie = demiVie;
}

void Isotope::setMasse(double masse) {
    this->_masse = masse;
}

bool Isotope::estStable() const {
    return this->_demiVie == std::numeric_limits<double>::infinity();
}
