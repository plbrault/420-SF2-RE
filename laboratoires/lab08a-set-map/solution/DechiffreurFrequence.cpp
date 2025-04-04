#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

DechiffreurFrequence::DechiffreurFrequence(const std::map<float, std::vector<char>> lettresParFrequenceLangue) {
    _lettresParFrequenceLangue = lettresParFrequenceLangue;
    _trierLettresLangue();
}

void DechiffreurFrequence::_trierLettresLangue() {
    for (auto it = _lettresParFrequenceLangue.begin(); it != _lettresParFrequenceLangue.end(); it++) {
        for (auto lettre : it->second) {
            _lettresTrieesLangue.push_back(lettre);
        }
    }
}

void DechiffreurFrequence::_compterLettresTexte() {
    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        _occurencesLettres[lettre] = 0;
    }
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            _occurencesLettres[tolower(caractere)]++;
        }
    }
}

void DechiffreurFrequence::_trierLettresTexte() {
    map<unsigned int, vector<char>> lettresParOccurences;
    for (auto it = _occurencesLettres.begin(); it != _occurencesLettres.end(); it++) {
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
        _substitutitons[_lettresTrieesTexte[i]] = _lettresTrieesLangue[i];
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
            fluxTexteDechiffre << _substitutitons[tolower(caractere)];
        } else {
            fluxTexteDechiffre << caractere;
        }
    }
    _texteDechiffre.clear();
    _texteDechiffre = fluxTexteDechiffre.str();
}

