#include "tache.h"

#include <sstream>

Tache::Tache(std::string description, bool fait) {
    this->_description = description;
    this->_fait = fait;
}

void Tache::marquerFait() {
    this->_fait = true;
}

void Tache::demarquerFait() {
    this->_fait = false;
}


void Tache::changerDescription(const std::string &description) {
    if (description.length() < DESCRIPTION_CARACTERE_LIMITE) {
        this->_description = description;
    } else {
        this->_description = description.substr(0, DESCRIPTION_CARACTERE_LIMITE);
    }
}

std::string Tache::obtenirDescription() {
    return this->_description;
}

std::string Tache::obtenirChaine(int index) {
    std::ostringstream flux;

    flux << index << " [" << (this->_fait ? 'X' : ' ') << "] " << this->_description;

    return flux.str();
}

bool Tache::estFait() {
    return this->_fait;
}
