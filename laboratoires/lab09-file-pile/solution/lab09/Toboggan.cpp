//
// Created by plbrault on 2026-04-11.
//

#include "Toboggan.h"

void Toboggan::ajouterGlisseur(Visiteur* visiteur, const Duration& temps) {
    _glisseurs.push(visiteur);
    _tempsEntree[visiteur] = temps;
}

Visiteur* Toboggan::verifierSortie(const Duration& temps) {
    return nullptr;
}

size_t Toboggan::getNombreGlisseurs() const {
    return _glisseurs.size();
}
