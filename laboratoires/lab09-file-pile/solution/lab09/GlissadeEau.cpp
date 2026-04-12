//
// Created by braultpi on 2026-04-08.
//

#include "GlissadeEau.h"
#include <iomanip>
#include <sstream>

#define LARGEUR_INTERNE 50
#define LARGEUR_GAUCHE 22
#define LARGEUR_DROITE 27
#define LABEL_G 14
#define VAL_G 6
#define LABEL_D 16
#define VAL_D 6

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

    // Si un visiteur est sorti du toboggan, le placer dans la zone d'arrivée.
    Visiteur* visiteurSorti = _toboggan.traiterSortie(_tempsActuel);
    if (visiteurSorti != nullptr) {
        _zoneArrivee.push(visiteurSorti);
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
    sortie << "|" << std::string(LARGEUR_INTERNE, '-') << "|" << std::endl;

    std::ostringstream ligneTemps;
    ligneTemps << "Temps: " << this->_tempsActuel;
    sortie << "| " << std::left << std::setw(LARGEUR_INTERNE - 2) << ligneTemps.str() << " |" << std::endl;

    sortie << "|" << std::string(LARGEUR_INTERNE, '-') << "|" << std::endl;

    sortie << "| " << std::left << std::setw(LARGEUR_GAUCHE - 2) << "TUBES" << " |"
           << "    " << std::left << std::setw(LARGEUR_DROITE - 5) << "VISITEURS" << " |" << std::endl;

    sortie << "| " << std::string(LARGEUR_GAUCHE - 2, '-') << " |"
           << std::string(LARGEUR_DROITE, '-') << "|" << std::endl;

    sortie << "| " << std::left << std::setw(LABEL_G) << "Disponibles:" << std::right << std::setw(VAL_G) << this->_tubesDisponibles.size() << " |"
           << "    " << std::left << std::setw(LABEL_D) << "File d'entree:" << std::right << std::setw(VAL_D) << this->_fileEntree.size() << " |" << std::endl;

    sortie << "| " << std::left << std::setw(LABEL_G) << "Zone de depot:" << std::right << std::setw(VAL_G) << this->_depotTubes.size() << " |"
           << "    " << std::left << std::setw(LABEL_D) << "File de montee:" << std::right << std::setw(VAL_D) << this->_fileMontee.size() << " |" << std::endl;

    sortie << "| " << std::string(LARGEUR_GAUCHE - 2, ' ') << " |"
           << "    " << std::left << std::setw(LABEL_D) << "Toboggan:" << std::right << std::setw(VAL_D) << this->_toboggan.getNombreGlisseurs() << " |" << std::endl;

    sortie << "| " << std::string(LARGEUR_GAUCHE - 2, ' ') << " |"
           << "    " << std::left << std::setw(LABEL_D) << "Zone d'arrivee:" << std::right << std::setw(VAL_D) << this->_zoneArrivee.size() << " |" << std::endl;

    sortie << "|" << std::string(LARGEUR_INTERNE, '-') << "|" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade) {
    glissade.afficher(os);
    return os;
}
