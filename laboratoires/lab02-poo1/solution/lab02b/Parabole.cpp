#include "Parabole.h"

Parabole::Parabole() {
    this->_valA = 1;
    this->_valB = 0;
    this->_valC = 0;
}

Parabole::Parabole(double valA, double valB, double valC) {
    this->_valA = valA;
    this->_valB = valB;
    this->_valC = valC;
}

double Parabole::evaluerY(double x) {
    return _valA * x * x + _valB * x + _valC;
}

std::string Parabole::obtenirEquation() {
    return std::to_string(this->_valA) + "x^2 + "
        + std::to_string(this->_valB) + "x + "
        + std::to_string(this->_valC);
}

void Parabole::afficher(std::ostream& sortie) {
    sortie << this->obtenirEquation();
}

void Parabole::afficher() {
    this->afficher(std::cout);
}
