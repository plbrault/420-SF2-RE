//
// Created by braultpi on 2026-04-08.
//

#include "GlissadeEau.h"
#include <iomanip>

#define LARGEUR_LIBELLE 47
#define LARGEUR_VALEUR 8
#define LARGEUR_LIGNE (LARGEUR_LIBELLE + LARGEUR_VALEUR + 2)

GlissadeEau::GlissadeEau() {
    _tempsActuel.setTotalSeconds(0);

    // Création des tubes
    for (int i = 0; i < 30; i++)
    {
        _tubes.emplace_back(); // Crée un tube et l'ajoute à la liste des tubes
        _tubesDisponibles.push(&_tubes.back()); // Ajoute l'adresse du tube dans la pile des tubes disponibles
    }
}

void GlissadeEau::mettreAJour() {
    // Si le toboggan accepte un nouveau glisseur et qu'il y a au moins un visiteur dans la file de montée,
    // ajouter le visiteur au toboggan et le retirer de la file de montée.
    if (_toboggan.accepteGlisseur(_tempsActuel) && !_fileMontee.empty()) {
        Visiteur* visiteur = _fileMontee.front();
        _fileMontee.pop();
        _toboggan.ajouterGlisseur(visiteur, _tempsActuel);
    }

    // Si un tube est disponible et que la file d'entrée n'est pas vide, le premier visiteur de la file d'entrée
    // prend un tube et est déplacé vers la file de montée.
    // Ne pas oublier de retirer le tube de la pile des tubes disponibles.
    if (!_tubesDisponibles.empty() && !_fileEntree.empty()) {
        Visiteur* visiteur = _fileEntree.front();
        _fileEntree.pop();
        Tube* tube = _tubesDisponibles.top();
        _tubesDisponibles.pop();
        visiteur->prendreTube(tube);
        _fileMontee.push(visiteur);
    }

    // Si un visiteur est sorti du toboggan, le placer dans la zone d'arrivée avec son temps de sortie
    // (soit le temps actuel).
    Visiteur* visiteurSorti = _toboggan.verifierSortie(_tempsActuel);
    if (visiteurSorti != nullptr) {
        _zoneArrivee[visiteurSorti] = _tempsActuel;
    }

    // S'il n'y a plus de tubes disponibles, déplacer deux tubes du dépôt vers la pile des tubes disponibles
    // (puisqu'un employé peut transporter deux tubes à la fois). Attention au cas où il y a moins
    // de deux tubes dans le dépôt.
    if (_tubesDisponibles.empty()) {
        for (int i = 0; i < 2 && !_depotTubes.empty(); i++) {
            Tube* tube = _depotTubes.top();
            _depotTubes.pop();
            _tubesDisponibles.push(tube);
        }
    }

    // Faire avancer le temps d'une seconde.
    _tempsActuel += 1;
}

void GlissadeEau::ajouterVisiteur(Visiteur* visiteur) {
    _fileEntree.push(visiteur);
}

void GlissadeEau::afficher(std::ostream& sortie) const {
    sortie << std::string(LARGEUR_LIGNE, '*') << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Temps: " << std::setw(LARGEUR_VALEUR) << std::right << this->_tempsActuel << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE)
        << std::left << "* Nombre de visiteurs dans la file d'entree: "
        << std::setw(LARGEUR_VALEUR) << std::right << this->_fileEntree.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de tubes disponibles: " << std::setw(LARGEUR_VALEUR) << std::right << this->_tubesDisponibles.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la file de montee: " << std::setw(LARGEUR_VALEUR) << std::right << this->_fileMontee.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans le toboggan: " << std::setw(LARGEUR_VALEUR) << std::right << this->_toboggan.getNombreGlisseurs() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la zone d'arrivee: " << std::setw(LARGEUR_VALEUR) << std::right << this->_zoneArrivee.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de tubes dans le depot: " << std::setw(LARGEUR_VALEUR) << std::right << this->_depotTubes.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la file de sortie: " << std::setw(LARGEUR_VALEUR) << std::right << this->_fileSortie.size() << " *" << std::endl;
    sortie << std::string(LARGEUR_LIGNE, '*') << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade) {
    glissade.afficher(os);
    return os;
}
