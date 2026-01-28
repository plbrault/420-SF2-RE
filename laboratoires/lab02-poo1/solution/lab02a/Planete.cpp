//
// Created by plbrault on 2026-01-28.
//

#include "Planete.h"

const double CONSTANTE_GRAVITATIONNELLE = 6.67430e-11;

Planete::Planete() {
    this->_nom = "(Planète inconnue)";
    this->_rayon = 0;
    this->_masse = 0;
    this->_distanceSoleil = 0;
}

Planete::Planete(std::string nom, double rayon, double masse, double distanceSoleil) {
    this->_nom = nom;
    this->_rayon = rayon;
    this->_masse = masse;
    this->_distanceSoleil = distanceSoleil;
}

void Planete::afficher(std::ostream &sortie) {
    sortie << "Planète " << this->_nom << ":" << std::endl
        << " - Rayon: " << this->_rayon << " m" << std::endl
        << " - Masse: " << this->_masse << " kg" << std::endl
        << " - Distance du soleil: " << this->_distanceSoleil << std::endl
        << " - Gravité de surface: " << this->calculerGraviteSurface() << " m/s^2" << std::endl;
}

void Planete::afficher() {
    this->afficher(std::cout);
}

double Planete::calculerGraviteSurface() {
    double graviteSurface = CONSTANTE_GRAVITATIONNELLE * this->_masse / (this->_rayon * this->_rayon);
    return graviteSurface;
}
