#include "tache.h"

#include <sstream>

Tache::Tache(std::string description, bool fait) {
    this->_description = description;
    this->_estCompletee = fait;
}

void Tache::marquerCompletee() {
    this->_estCompletee = true;
}

void Tache::marquerNonCompletee() {
    this->_estCompletee = false;
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

std::string Tache::obtenirChaine(int indiceTache) {
    std::ostringstream flux;

    flux << indiceTache << " [" << (this->_estCompletee ? 'X' : ' ') << "] " << this->_description;

    return flux.str();
}

bool Tache::estFait() {
    return this->_estCompletee;
}
