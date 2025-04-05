#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

void DechiffreurFrequence::_genererSubstitutions() {
    for (int i = 0; i < _analyseur.getLettresTriees().size(); i++) {
        _substitutions[_analyseur.getLettresTriees()[i]] = _langue->getLettresTriees()[i];
    }
}

void DechiffreurFrequence::dechiffrer() {
    _analyseur.analyser(_texteChiffre);
    _genererSubstitutions();

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

