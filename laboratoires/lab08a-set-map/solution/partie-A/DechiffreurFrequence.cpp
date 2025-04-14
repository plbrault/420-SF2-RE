#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

void DechiffreurFrequence::_genererSubstitutions() {
    for (size_t i = 0; i < _analyseur.getLettresTriees().size(); i++) {
        _substitutions[_analyseur.getLettresTriees()[i]] = _langue->getLettresTriees()[i];
    }
}

void DechiffreurFrequence::_substituer() {
    stringstream fluxTexteDechiffre;
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            fluxTexteDechiffre << _substitutions[tolower(caractere)];
        } else {
            fluxTexteDechiffre << caractere;
        }
    }
    _texteDechiffre.clear();
    _texteDechiffre = fluxTexteDechiffre.str();
}

void DechiffreurFrequence::dechiffrer() {
    _analyseur.analyser(_texteChiffre);
    _genererSubstitutions();
    _substituer();
}

void DechiffreurFrequence::changerSubstitution(char ancien, char nouveau) {
    char subsChangee = '\0';
    for (auto it = _substitutions.begin(); it != _substitutions.end(); ++it) {
        if (it->second == ancien) {
            subsChangee = it->first;
            it->second = nouveau;
            break;
        }
    }
    for (auto it = _substitutions.begin(); it != _substitutions.end(); ++it) {
        if (it->first != subsChangee && it->second == nouveau) {
            it->second = ancien;
            break;
        }
    }
    _substituer();
}

