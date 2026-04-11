//
// Created by plbrault on 2026-04-11.
//

#include "Toboggan.h"

bool Toboggan::accepteGlisseur() const {
    // Retourner vrai si le toboggan est vide ou que le dernier glisseur est entré il y a au moins 10 secondes.
    if (_glisseurs.empty()) {
        return true;
    }
    Visiteur* dernierGlisseur = _glisseurs.back();
    Duration tempsDepuisEntree = _tempsEntree.at(dernierGlisseur);
    return tempsDepuisEntree.getTotalSeconds() >= 10;
}

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
