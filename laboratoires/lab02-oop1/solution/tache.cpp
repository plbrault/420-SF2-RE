#include "tache.h"

#include <sstream>

Tache::Tache(void) {
    std::string empty = std::string("");
    this->donnerDescription(empty);
    this->marquerNonFait();
}

Tache::Tache(std::string &description) {
    this->donnerDescription(description);
    this->marquerNonFait();
}

Tache::Tache(std::string &description, bool estFait) {
    this->donnerDescription(description);
    this->fait = estFait;
}

std::string Tache::obtenirDescription(void) {
    return this->description;
}

void Tache::donnerDescription(const std::string &description) {
    this->description = description;
}

bool Tache::estFait(void) {
    return this->fait;
}

void Tache::marquerFait(void) {
    this->fait = true;
}

void Tache::marquerNonFait(void) {
    this->fait = false;
}

std::string Tache::obtenirChaine(int index) {
    std::ostringstream flux;
    flux << index << " [" << (this->fait ? 'x' : ' ') << "] " << description;
    return flux.str();
}