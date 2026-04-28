//
// Created by braultpi on 2026-04-08.
//

#include "Visiteur.h"

void Visiteur::prendreTube(Tube* tube) {
    _tube = tube;
}

Tube* Visiteur::retournerTube() {
    Tube* tube = _tube;
    _tube = nullptr;
    return tube;
}

bool Visiteur::aUnTube() const {
    return _tube != nullptr;
}
