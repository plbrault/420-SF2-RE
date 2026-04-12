//
// Created by plbrault on 2026-04-11.
//

#include "Toboggan.h"

bool Toboggan::accepteGlisseur(const Time& heureActuelle) const {
    if (_glisseurs.empty()) {
        return true;
    }
    Visiteur* dernierGlisseur = _glisseurs.back();
    Duration dureeDepuisEntree = heureActuelle - _heureEntree.at(dernierGlisseur);
    return dureeDepuisEntree.getTotalSeconds() >= 10;
}

void Toboggan::ajouterGlisseur(Visiteur* visiteur, const Time& heure) {
    // Ajoute le visiteur dans _glisseurs et enregistre l'heure d'entrée du visiteur dans _heureEntree.
    _glisseurs.push(visiteur);
    _heureEntree[visiteur] = heure;
}

Visiteur* Toboggan::traiterSortie(const Time& heureActuelle) {
    // Si le premier glisseur est entré il y a au moins 30 secondes, le retirer de _glisseurs et retourner son adresse.
    // Sinon, retourner nullptr.
    // Ne pas oublier de retirer le glisseur de _heureEntree lorsque vous le retirez de _glisseurs.
    if (!_glisseurs.empty()) {
        Visiteur* premierGlisseur = _glisseurs.front();
        Duration dureeDepuisEntree = heureActuelle - _heureEntree.at(premierGlisseur);
        if (dureeDepuisEntree.getTotalSeconds() >= 30) {
            _glisseurs.pop();
            _heureEntree.erase(premierGlisseur);
            return premierGlisseur;
        }
    }
    return nullptr;
}

size_t Toboggan::getNombreGlisseurs() const {
    return _glisseurs.size();
}
