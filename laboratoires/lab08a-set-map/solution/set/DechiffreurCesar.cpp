#pragma once

#include "DechiffreurCesar.h"
#include "fonctions.h"

using namespace std;

DechiffreurCesar::DechiffreurCesar(const std::set<std::string> *langue) {
    _langue = langue;

    for (char c = 'a'; c <= 'z'; ++c) {
        _lettresMinuscules.push_back(c);
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        _lettresMajuscules.push_back(c);
    }
}

char DechiffreurCesar::_decalerLettre(char lettre, int decalage) const {
    if ('a' <= lettre && lettre <= 'z') {
        return _lettresMinuscules[(lettre - 'a' + decalage) % 26];
    }
    if ('A' <= lettre && lettre <= 'Z') {
        return _lettresMajuscules[(lettre - 'A' + decalage) % 26];
    }
    return lettre;
}

bool DechiffreurCesar::_essayerDecalage(const std::string& mot, int decalage) const {
    std::string essai;
    for (int i  = 0; i < mot.size(); i++) {
        essai += _decalerLettre(mot[i], decalage);
    }
    return _langue->find(essai) != _langue->end();
}

void DechiffreurCesar::dechiffrer() {
    vector<string> motsChiffres = split(_texteChiffre, ' ');
    int motsValides;
    int maxMotsValides = 0;
    int meilleurDecalage = 0;

    for (int i = 0; i < 26; i++) {
        motsValides = 0;
        for (const auto& mot : motsChiffres) {
            if (_essayerDecalage(mot, i)) {
                motsValides++;
            }
        }
        if (motsValides > maxMotsValides) {
            maxMotsValides = motsValides;
            meilleurDecalage = i;
        }
    }

    _texteDechiffre.clear();
    for (const char& c : _texteChiffre) {
        _texteDechiffre += _decalerLettre(c, meilleurDecalage);
    }
}
