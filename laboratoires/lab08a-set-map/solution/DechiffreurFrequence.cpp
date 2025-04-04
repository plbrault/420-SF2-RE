#include "DechiffreurFrequence.h"

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
    _compterLettres();
    ;
}

