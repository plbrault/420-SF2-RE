//
// Created by braultpi on 2026-04-08.
//

#include "GlissadeEau.h"
#include <iomanip>
#include <sstream>

#define AFFICHAGE_LARGEUR_INTERNE 50
#define AFFICHAGE_LARGEUR_GAUCHE 22
#define AFFICHAGE_LARGEUR_DROITE 27
#define AFFICHAGE_LIBELLE_GAUCHE 14
#define AFFICHAGE_VALEUR_GAUCHE 6
#define AFFICHAGE_LIBELLE_DROITE 16
#define AFFICHAGE_VALEUR_DROITE 6

GlissadeEau::GlissadeEau(size_t nombreToboggans, size_t nombreTubes) {
    _heureActuelle = Time(9, 0, 0);
    _totalVisiteursJournee = 0;

    // Création des toboggans
    for (int i = 0; i < nombreToboggans; i++) {
        _toboggans.emplace_back();
    }

    // Création des tubes
    for (int i = 0; i < nombreTubes; i++)
    {
        _tubes.emplace_back(); // Crée un tube et l'ajoute à la liste des tubes
        _tubesDisponibles.push(&_tubes.back()); // Ajoute l'adresse du tube dans la pile des tubes disponibles
    }
}

const Time& GlissadeEau::getHeureActuelle() const {
    return _heureActuelle;
}

void GlissadeEau::ajouterVisiteur(Visiteur* visiteur) {
    _fileEntree.push(visiteur);
    _totalVisiteursJournee++;
}

void GlissadeEau::mettreAJour() {
    /*** À COMPLÉTER ***/

    // Pour chaque toboggan, vérifier si le toboggan accepte un nouveau glisseur.
    // Si c'est le cas, retirer le premier visiteur de la file de montée et le faire entrer dans le toboggan.
    // Ne pas oublier de gérer le cas où la file de montée est vide.


    // Si un tube est disponible et que la file d'entrée n'est pas vide, le premier visiteur de la file d'entrée
    // prend un tube et est déplacé vers la file de montée.
    // Ne pas oublier de retirer le tube de la pile des tubes disponibles.


    // Pour chaque toboggan, vérifier si un visiteur vient de sortir du toboggan.
    // Si c'est le cas, placer le visiteur dans la zone d'arrivée avec
    // l'heure actuelle.


    // Si la pile des tubes disponibles est vide, déplacer tous les tubes de la zone de dépôt vers
    // la pile des tubes disponibles.


    // Faire avancer l'heure d'une seconde.
    _heureActuelle += Duration(0, 0, 1);
}

Visiteur* GlissadeEau::traiterSortie() {
    /*** À COMPLÉTER ***/

    // Si la zone d'arrivée est non-vide, trouver le plus ancien
    // visiteur qui s'y trouve depuis au moins 15 secondes.
    // Remettre le tube du visiteur dans la zone de dépôt, puis retirer
    // le visiteur de la zone d'arrivée et retourner son adresse.
    // Si la zone d'arrivée est vide ou si aucun visiteur n'y est depuis au moins 15 secondes, retourner nullptr.

    return nullptr;
}

void GlissadeEau::afficher(std::ostream& sortie) const {
    sortie << "|" << std::string(AFFICHAGE_LARGEUR_INTERNE, '-') << "|" << std::endl;

    std::ostringstream ligneTemps;
    ligneTemps << "Heure: " << this->_heureActuelle;
    sortie << "| " << std::left << std::setw(AFFICHAGE_LARGEUR_INTERNE - 2) << ligneTemps.str() << " |" << std::endl;

    sortie << "|" << std::string(AFFICHAGE_LARGEUR_INTERNE, '-') << "|" << std::endl;

    sortie << "| " << std::left << std::setw(AFFICHAGE_LARGEUR_GAUCHE - 2) << "TUBES" << " |"
           << "    " << std::left << std::setw(AFFICHAGE_LARGEUR_DROITE - 5) << "VISITEURS" << " |" << std::endl;

    sortie << "| " << std::string(AFFICHAGE_LARGEUR_GAUCHE - 2, '-') << " |"
           << std::string(AFFICHAGE_LARGEUR_DROITE, '-') << "|" << std::endl;

    sortie << "| " << std::left << std::setw(AFFICHAGE_LIBELLE_GAUCHE) << "Disponibles:"
           << std::right << std::setw(AFFICHAGE_VALEUR_GAUCHE) << this->_tubesDisponibles.size() << " |"
           << "    " << std::left << std::setw(AFFICHAGE_LIBELLE_DROITE) << "File d'entree:"
           << std::right << std::setw(AFFICHAGE_VALEUR_DROITE) << this->_fileEntree.size() << " |" << std::endl;

    sortie << "| " << std::left << std::setw(AFFICHAGE_LIBELLE_GAUCHE) << "Zone de depot:"
           << std::right << std::setw(AFFICHAGE_VALEUR_GAUCHE) << this->_depotTubes.size() << " |"
           << "    " << std::left << std::setw(AFFICHAGE_LIBELLE_DROITE) << "File de montee:"
           << std::right << std::setw(AFFICHAGE_VALEUR_DROITE) << this->_fileMontee.size() << " |" << std::endl;

    for (size_t i = 0; i < _toboggans.size(); i++) {
        std::string libelle = "Toboggan " + std::to_string(i + 1) + ":";
        sortie << "| " << std::string(AFFICHAGE_LARGEUR_GAUCHE - 2, ' ') << " |"
               << "    " << std::left << std::setw(AFFICHAGE_LIBELLE_DROITE) << libelle
               << std::right << std::setw(AFFICHAGE_VALEUR_DROITE) << _toboggans[i].getNombreGlisseurs()
               << " |" << std::endl;
    }

    sortie << "| " << std::string(AFFICHAGE_LARGEUR_GAUCHE - 2, ' ') << " |"
           << "    " << std::left << std::setw(AFFICHAGE_LIBELLE_DROITE) << "Zone d'arrivee:"
           << std::right << std::setw(AFFICHAGE_VALEUR_DROITE) << this->_zoneArrivee.size() << " |" << std::endl;

    sortie << "|" << std::string(AFFICHAGE_LARGEUR_INTERNE, '-') << "|" << std::endl;

    std::ostringstream ligneTotalVisiteurs;
    ligneTotalVisiteurs << "Total des visiteurs pour la journee: " << this->_totalVisiteursJournee;
    sortie << "| " << std::left << std::setw(AFFICHAGE_LARGEUR_INTERNE - 2) << ligneTotalVisiteurs.str() << " |" << std::endl;

    sortie << "|" << std::string(AFFICHAGE_LARGEUR_INTERNE, '-') << "|" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade) {
    glissade.afficher(os);
    return os;
}
