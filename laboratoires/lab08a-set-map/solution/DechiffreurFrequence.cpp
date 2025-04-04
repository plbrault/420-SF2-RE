#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

DechiffreurFrequence::DechiffreurFrequence(const std::map<float, std::vector<char>> lettresParFrequenceLangue) {
    _lettresParFrequenceLangue = lettresParFrequenceLangue;
    _trierLettresLangue();
}

void DechiffreurFrequence::_trierLettresLangue() {
    
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

}

void DechiffreurFrequence::_genererSubstitutitons() {

}

void DechiffreurFrequence::dechiffrer() {
    // Plutôt que de matcher la fréquence la plus proche, y aller par ordre de la plus fréquente à la moins fréquente

    _compterLettresTexte();
    _trierLettresLangue();
    _genererSubstitutitons();

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

