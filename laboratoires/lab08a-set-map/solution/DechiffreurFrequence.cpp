#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

void DechiffreurFrequence::_compterLettresTexte() {
    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        _occurencesLettresTexte[lettre] = 0;
    }
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            _occurencesLettresTexte[tolower(caractere)]++;
        }
    }
}

void DechiffreurFrequence::_trierLettresTexte() {
    map<unsigned int, vector<char>> lettresParOccurences;
    for (auto it = _occurencesLettresTexte.begin(); it != _occurencesLettresTexte.end(); it++) {
        lettresParOccurences[it->second].push_back(it->first);
    }
    for (auto it = lettresParOccurences.begin(); it != lettresParOccurences.end(); it++) {
        for (auto lettre : it->second) {
            _lettresTrieesTexte.push_back(lettre);
        }
    }
}

void DechiffreurFrequence::_genererSubstitutions() {
    for (int i = 0; i < _lettresTrieesTexte.size(); i++) {
        _substitutions[_lettresTrieesTexte[i]] = _langue->getLettresTriees()[i];
    }
}

void DechiffreurFrequence::dechiffrer() {
    // Plutôt que de matcher la fréquence la plus proche, y aller par ordre de la plus fréquente à la moins fréquente

    _compterLettresTexte();
    _trierLettresTexte();
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

