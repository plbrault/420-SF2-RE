//
// Created by braultpi on 2026-04-08.
//

#include "Visiteur.h"

void Visiteur::prendreTube(Tube* tube) {
    _tube = tube;
}

Tube* Visiteur::retournerTube() {
    // Remet _tube à nullptr puis retourne l'adresse qui était auparavant dans _tube.
    Tube* tube = _tube;
    _tube = nullptr;
    return tube;
}
