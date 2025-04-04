#include "DechiffreurFrequence.h"
#include <sstream>

using namespace std;

DechiffreurFrequence::DechiffreurFrequence(const std::map<float, std::vector<char>>* lettresParFrequenceLangue) {
    _lettresParFrequenceLangue = lettresParFrequenceLangue;

    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        _occurencesLettres[lettre] = 0;
    }
}

void DechiffreurFrequence::_compterLettres() {
    _nombreLettres = 0;
    for (char lettre : _texteChiffre) {
        if ('a' <= tolower(lettre) <= 'z') {
            _occurencesLettres[tolower(lettre)]++;
            _nombreLettres++;
        }
    }
}

void DechiffreurFrequence::dechiffrer() {
    stringstream fluxTexteDechiffre;
    _compterLettres();
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) <= 'z') {
            float frequence = (float)_occurencesLettres[caractere] / (float)_nombreLettres;
            auto itBas = _lettresParFrequenceLangue->lower_bound(frequence);
            auto itHaut = _lettresParFrequenceLangue->upper_bound(frequence);
            vector<char> plusProbable = min(
                    abs(itBas->first - frequence), abs(itHaut->first - frequence)
                ) == abs(itBas->first - frequence) ? itBas->second : itHaut->second;
            fluxTexteDechiffre << plusProbable[0];
        } else {
            fluxTexteDechiffre << caractere;
        }
    }
    _texteDechiffre.clear();
    _texteDechiffre = fluxTexteDechiffre.str();
}

