//
// Created by plbrault on 2026-04-11.
//

#include "Toboggan.h"

bool Toboggan::accepteGlisseur(const Duration& tempsActuel) const {
    // Retourner vrai si le toboggan est vide ou que le dernier glisseur est entré il y a au moins 10 secondes.
    if (_glisseurs.empty()) {
        return true;
    }
    Visiteur* dernierGlisseur = _glisseurs.back();
    Duration tempsDepuisEntree = tempsActuel - _tempsEntree.at(dernierGlisseur);
    return tempsDepuisEntree.getTotalSeconds() >= 10;
}

void Toboggan::ajouterGlisseur(Visiteur* visiteur, const Duration& temps) {
    // Ajoute le visiteur dans _glisseurs et enregistre le temps d'entrée du visiteur dans _tempsEntree.
    _glisseurs.push(visiteur);
    _tempsEntree[visiteur] = temps;
}

Visiteur* Toboggan::traiterSortie(const Duration& tempsActuel) {
    // Si le premier glisseur est entré il y a au moins 30 secondes, le retirer de _glisseurs et retourner son adresse.
    // Sinon, retourner nullptr.
    // Ne pas oublier de retirer le glisseur de _tempsEntree lorsque vous le retirez de _glisseurs.
    if (!_glisseurs.empty()) {
        Visiteur* premierGlisseur = _glisseurs.front();
        Duration tempsDepuisEntree = tempsActuel - _tempsEntree.at(premierGlisseur);
        if (tempsDepuisEntree.getTotalSeconds() >= 30) {
            _glisseurs.pop();
            _tempsEntree.erase(premierGlisseur);
            return premierGlisseur;
        }
    }
    return nullptr;
}

size_t Toboggan::getNombreGlisseurs() const {
    return _glisseurs.size();
}
