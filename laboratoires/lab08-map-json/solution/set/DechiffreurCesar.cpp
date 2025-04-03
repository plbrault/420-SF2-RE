#pragma once

#include "DechiffreurCesar.h"
#include "fonctions.h"

using namespace std;

DechiffreurCesar::DechiffreurCesar(const std::set<std::string> *langue) {
    _langue = langue;
}

void DechiffreurCesar::dechiffrer() {
    vector<string> motsChiffres = split(_texteChiffre, ' ');
}