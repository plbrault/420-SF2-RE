//
// Created by plbrault on 2026-02-04.
//

#include "SystemePlanetaire.h"

SystemePlanetaire::SystemePlanetaire() {
    this->_capacitePlanetes = 2;
    this->_nombrePlanetes = 0;
    this->_planetes = new Planete[this->_capacitePlanetes];
}

SystemePlanetaire::SystemePlanetaire(std::string nom) : SystemePlanetaire() {
    this->_nom = nom;
}

SystemePlanetaire::~SystemePlanetaire() {
    delete[] this->_planetes;
}

void SystemePlanetaire::ajouterPlanete(Planete planete) {
    if (this->_nombrePlanetes == this->_capacitePlanetes) {
        Planete* nouveauTableau = new Planete[2 * this->_capacitePlanetes];
        for (size_t i = 0; i < this->_capacitePlanetes; i++) {
            nouveauTableau[i] = this->_planetes[i];
        }
        delete[] this->_planetes;
        this->_planetes = nouveauTableau;
        this->_capacitePlanetes *= 2;
    }
    this->_planetes[this->_nombrePlanetes] = planete;
    this->_nombrePlanetes++;
}

void SystemePlanetaire::afficher(std::ostream& sortie) const {
    sortie << this->_nom << ":" << std::endl << std::endl;
    for (size_t i = 0; i < this->_nombrePlanetes; i++) {
        this->_planetes[i].afficher();
        sortie << std::endl;
    }
}

void SystemePlanetaire::afficher() const {
    this->afficher(std::cout);
}
