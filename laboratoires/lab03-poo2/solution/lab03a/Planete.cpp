//
// Created by plbrault on 2026-01-28.
//

#include "Planete.h"

const double CONSTANTE_GRAVITATIONNELLE = 6.67430e-11;

Planete::Planete() {
    this->_nom = "(Planète sans nom)";
    this->_rayon = 0;
    this->_masse = 0;
    this->_distanceEtoile = 0;
}

Planete::Planete(std::string nom, double rayon, double masse, double distanceEtoile) {
    this->_nom = nom;
    this->_rayon = rayon;
    this->_masse = masse;
    this->_distanceEtoile = distanceEtoile;
}

std::string Planete::getNom() const {
    return this->_nom;
}

double Planete::getRayon() const {
    return this->_rayon;
}

double Planete::getMasse() const {
    return this->_masse;
}

double Planete::getDistanceEtoile() const {
    return this->_distanceEtoile;
}

void Planete::setNom(std::string nom) {
    _nom = nom;
}

void Planete::setRayon(double rayon) {
    _rayon = rayon;
}

void Planete::setMasse(double masse) {
    _masse = masse;
}

void Planete::setDistanceEtoile(double distanceEtoile) {
    _distanceEtoile = distanceEtoile;
}

void Planete::afficher(std::ostream &sortie) {
    sortie << "Planète " << this->_nom << ":" << std::endl
        << " - Rayon: " << this->_rayon << " m" << std::endl
        << " - Masse: " << this->_masse << " kg" << std::endl
        << " - Distance de l'étoile: " << this->_distanceEtoile << std::endl
        << " - Gravité de surface: " << this->getGraviteSurface() << " m/s^2" << std::endl;
}

void Planete::afficher() {
    this->afficher(std::cout);
}

double Planete::getGraviteSurface() {
    double graviteSurface = CONSTANTE_GRAVITATIONNELLE * this->_masse / (this->_rayon * this->_rayon);
    return graviteSurface;
}
