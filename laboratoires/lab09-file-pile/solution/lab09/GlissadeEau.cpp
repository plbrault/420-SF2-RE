//
// Created by braultpi on 2026-04-08.
//

#include "GlissadeEau.h"
#include <iomanip>

#define LARGEUR_LIBELLE 50
#define LARGEUR_VALEUR 9

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
    sortie << std::string(20, '*') << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Temps: " <<  this->_temps << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE)
        << std::left << "* Nombre de visiteurs dans la file d'entrée: "
        << std::setw(LARGEUR_VALEUR) << std::right << this->_fileEntree.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de tubes disponibles:" << std::setw(LARGEUR_VALEUR) << std::right << this->_tubesDisponibles.size() << "*" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la file de montée:" << std::setw(LARGEUR_VALEUR) << std::right << this->_fileMontee.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans le toboggan:" << std::setw(LARGEUR_VALEUR) << std::right << this->_toboggan.getNombreGlisseurs() << "*" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la zone d'arrivée:" << std::setw(LARGEUR_VALEUR) << std::right << this->_zoneArrivee.size() << " *" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de tubes dans le dépôt:" << std::setw(LARGEUR_VALEUR) << std::right << this->_depotTubes.size() << "*" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << "* Nombre de visiteurs dans la file de sortie:" << std::setw(LARGEUR_VALEUR) << std::right << this->_fileSortie.size() << "*" << std::endl;
    sortie << std::setw(LARGEUR_LIBELLE) << std::left << std::string(20, '*') << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade) {
    glissade.afficher(os);
    return os;
}
