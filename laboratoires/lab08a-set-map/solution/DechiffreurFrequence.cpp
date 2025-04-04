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
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            _occurencesLettres[tolower(caractere)]++;
        }
        if (caractere != '\n') {
            _nombreLettres++;
        }
    }
}

void DechiffreurFrequence::dechiffrer() {
    stringstream fluxTexteDechiffre;
    _compterLettres();
    for (auto caractere : _texteChiffre) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            int occ = _occurencesLettres[tolower(caractere)];
            float frequence = (float)occ / (float)_nombreLettres;
            //float frequence = (float)_occurencesLettres[caractere] / (float)_nombreLettres;

            auto itPlusProche = _lettresParFrequenceLangue->begin();
            auto itLowerBound = _lettresParFrequenceLangue->lower_bound(frequence);
            auto itPrecedent = std::prev(itLowerBound);
            if (itLowerBound == _lettresParFrequenceLangue->end()) {
                itPlusProche = itPrecedent;
            } else if (itLowerBound == _lettresParFrequenceLangue->begin()) {
                itPlusProche = itLowerBound;
            } else {
                float diff1 = abs(itLowerBound->first - frequence);
                float diff2 = abs(itPrecedent->first - frequence);
                itPlusProche = (diff1 < diff2) ? itLowerBound : itPrecedent;
            }
            fluxTexteDechiffre << itPlusProche->second[0];
        } else {
            fluxTexteDechiffre << caractere;
        }
    }
    _texteDechiffre.clear();
    _texteDechiffre = fluxTexteDechiffre.str();
}

