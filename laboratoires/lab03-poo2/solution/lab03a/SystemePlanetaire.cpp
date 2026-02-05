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
    this->setNom(nom);
}

SystemePlanetaire::SystemePlanetaire(const SystemePlanetaire &autreSysteme) {
    this->_nom = autreSysteme._nom;
    this->_capacitePlanetes = autreSysteme._capacitePlanetes;
    this->_nombrePlanetes = autreSysteme._nombrePlanetes;

    this->_planetes = new Planete[this->_capacitePlanetes];
    for (size_t i = 0; i < this->_nombrePlanetes; i++) {
        this->_planetes[i] = autreSysteme._planetes[i];
    }
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

std::string SystemePlanetaire::getNom() const {
    return this->_nom;
}

size_t SystemePlanetaire::getNombrePlanetes() const {
    return this->_nombrePlanetes;
}

Planete* SystemePlanetaire::getPlanete(size_t indice) const {
    if (indice < this->_nombrePlanetes) {
        return this->_planetes + indice;
    }
    return nullptr;
}

Planete* SystemePlanetaire::getPlanete(std::string nom) const {
    for (size_t i = 0; i < this->_nombrePlanetes; i++) {
        if (this->_planetes[i].getNom() == nom) {
            return this->_planetes + i;
        }
    }
    return nullptr;
}

void SystemePlanetaire::setNom(std::string nom) {
    this->_nom = nom;
}
