//
// Created by braultpi on 2026-04-08.
//

#include "GlissadeEau.h"
#include <iomanip>

#define LARGEUR_LIBELLE 47
#define LARGEUR_VALEUR 8
#define LARGEUR_LIGNE (LARGEUR_LIBELLE + LARGEUR_VALEUR + 2)

GlissadeEau::GlissadeEau() {
    _temps.setTotalSeconds(0);
}

void GlissadeEau::ajouterVisiteur(Visiteur* visiteur) {
    _fileEntree.push(visiteur);
}

void GlissadeEau::mettreAJour(const Duration& incrementTemps) {
    _temps += incrementTemps;
}

void GlissadeEau::afficher(std::ostream& sortie) const {
    sortie << std::string(LARGEUR_LIGNE, '*') << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Temps: " << std::setw(LARGEUR_VALEUR) << std::right << this->_temps << " *" << std::endl;
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
