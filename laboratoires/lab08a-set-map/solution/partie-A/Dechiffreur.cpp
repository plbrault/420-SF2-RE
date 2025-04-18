#include "Dechiffreur.h"
#include <sstream>

using namespace std;

Dechiffreur::Dechiffreur(const Langue *langue) {
    _langue = langue;
}

void Dechiffreur::lireTexteChiffre(std::istream& entree) {
    stringstream contenu;
    string ligne;
    while (getline(entree, ligne)) {
        contenu << ligne << endl;
    }
    _texteChiffre = contenu.str();
    _texteDechiffre.clear();
}

const string& Dechiffreur::getTexteChiffre() const {
    return _texteChiffre;
}

const string& Dechiffreur::getTexteDechiffre() const {
    return _texteDechiffre;
}
