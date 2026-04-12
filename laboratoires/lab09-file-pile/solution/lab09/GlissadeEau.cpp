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

const Time& GlissadeEau::getHeure() const {
    return _heureActuelle;
}

size_t GlissadeEau::getTailleFileEntree() const {
    return _fileEntree.size();
}

size_t GlissadeEau::getTailleFileMontee() const {
    return _fileMontee.size();
}

size_t GlissadeEau::getTailleZoneArrivee() const {
    return _zoneArrivee.size();
}

GlissadeEau::GlissadeEau() {
    _heureActuelle = Time(9, 0, 0);

    // Création des toboggans
    for (int i = 0; i < 3; i++) {
        _toboggans.emplace_back();
    }

    // Création des tubes
    for (int i = 0; i < 30; i++)
    {
        _tubes.emplace_back(); // Crée un tube et l'ajoute à la liste des tubes
        _tubesDisponibles.push(&_tubes.back()); // Ajoute l'adresse du tube dans la pile des tubes disponibles
    }
}

void GlissadeEau::mettreAJour() {
    // Pour chaque toboggan, vérifier si le toboggan accepte un nouveau glisseur.
    // Si c'est le cas, retirer le premier visiteur de la file de montée et le faire entrer dans le toboggan.
    // Ne pas oublier de gérer le cas où la file de montée est vide.
    for (Toboggan& toboggan : _toboggans) {
        if (toboggan.accepteGlisseur(_heureActuelle)) {
            if (!_fileMontee.empty()) {
                Visiteur* visiteur = _fileMontee.front();
                _fileMontee.pop();
                toboggan.ajouterGlisseur(visiteur, _heureActuelle);
            }
        }
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

    // Si la zone d'arrivée est non-vide, Vérifier si le premier visiteur qui s'y trouve a encore son tube.
    // Si c'est le cas, retirer le tube du visiteur et le placer dans la zone de dépôt.
    if (!_zoneArrivee.empty())
    {
        Visiteur* visiteurArrive = _zoneArrivee.front();
        if (visiteurArrive->aUnTube()) {
            Tube* tube = visiteurArrive->retournerTube();
            _depotTubes.push(tube);
        }
    }

    // Pour chaque toboggan, vérifier si un visiteur vient de sortir du toboggan.
    // Si c'est le cas, placer le visiteur dans la zone d'arrivée.
    for (Toboggan& toboggan : _toboggans) {
        Visiteur* visiteurSorti = toboggan.traiterSortie(_heureActuelle);
        if (visiteurSorti != nullptr) {
            _zoneArrivee.push(visiteurSorti);
        }
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

    // Faire avancer l'heure d'une seconde.
    _heureActuelle += Duration(0, 0, 1);
}

void GlissadeEau::ajouterVisiteur(Visiteur* visiteur) {
    _fileEntree.push(visiteur);
}

Visiteur* GlissadeEau::traiterSortie() {
    // Vérifier si le premier visiteur de la zone d'arrivée a remis son tube.
    // Si c'est le cas, le retirer de la zone d'arrivée et retourner son adresse.
    // Si la zone d'arrivée est vide ou que le premier visiteur n'a pas remis son tube, retourner nullptr.
    if (!_zoneArrivee.empty()) {
        Visiteur* visiteurArrive = _zoneArrivee.front();
        if (!visiteurArrive->aUnTube()) {
            _zoneArrivee.pop();
            return visiteurArrive;
        }
    }
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
}

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade) {
    glissade.afficher(os);
    return os;
}
