#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

DechiffreurFrequence::DechiffreurFrequence(const std::map<float, std::vector<char>>* lettresParFrequenceLangue) {
    _lettresParFrequenceLangue = lettresParFrequenceLangue;
}

void DechiffreurFrequence::_compterLettres() {
    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        _occurencesLettres[lettre] = 0;
    }
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            _occurencesLettres[tolower(caractere)]++;
        }
    }
}

void DechiffreurFrequence::_trierLettres() {
    map<unsigned int, vector<char>> lettresParOccurences;
    for (auto& [lettre, occurence] : _occurencesLettres) {
        lettresParOccurences[occurence].push_back(lettre);
    }
    _lettresTrieesParOccurences.clear();
    for (auto& [occurence, lettres] : lettresParOccurences) {
        for (auto& lettre : lettres) {
            _lettresTrieesParOccurences.push_back(lettre);
        }
    }
}

void DechiffreurFrequence::dechiffrer() {
    // Plutôt que de matcher la fréquence la plus proche, y aller par ordre de la plus fréquente à la moins fréquente

    _compterLettres();
    _trierLettres();

    stringstream fluxTexteDechiffre;
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {

        } else {
            fluxTexteDechiffre << caractere;
        }
    }
    _texteDechiffre.clear();
    _texteDechiffre = fluxTexteDechiffre.str();
}

