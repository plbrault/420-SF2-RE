#pragma once

#include "Dechiffreur.h"
#include <sstream>

using namespace std;

void Dechiffreur::lireTexteChiffre(std::istream& entree) {
    stringstream contenu;
    string ligne;
    while (getline(entree, ligne)) {
        contenu << ligne << endl;
    }
    _texteChiffre = contenu.str();
}

const string& Dechiffreur::getTexteChiffre() const {
    return _texteChiffre;
}

const string& Dechiffreur::getTexteDechiffre() const {
    return _texteDechiffre;
}
