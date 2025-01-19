#include "personne.h"

#include <sstream>

/** ===========================================================================
 * Constructeur(s) et destructeur
 * ========================================================================= */

Personne::Personne(std::string &prenom, std::string &nom) {
    this->prenom = prenom;
    this->nom = nom;
    this->quantite = 0;
    this->taille = TAILLE_LISTE_TACHE_INCREMENT;
    this->listeDeTaches = new Tache[this->taille];
}

Personne::~Personne(void) {
    delete[] this->listeDeTaches;
}

/** ===========================================================================
 * Accesseur et mutateur
 * ========================================================================= */

std::string Personne::obtenirNomComplet(void) {
    std::ostringstream flux;
    flux << this->prenom << " " << this->nom;
    for (uint8_t i = 0; i < this->quantite; i++) {
        flux << this->listeDeTaches[i].obtenirChaine(i + 1) << std::endl;
    }
    return flux.str();
}

std::string Personne::obtenirChaine(void) {
    std::ostringstream flux;
    flux << "Liste des tâches à " << this->obtenirNomComplet() << std::endl;
    for (uint8_t i = 0; i < this->quantite; i++) {
        flux << this->listeDeTaches[i].obtenirChaine(i + 1) << std::endl;
    }
    return flux.str();
}

Tache *Personne::obtenirTache(int index) {
    Tache *resultat = nullptr;

    if (index < this->quantite) {
        resultat = &(this->listeDeTaches[index]);
    }

    return resultat;
}

bool Personne::completeTache(int index) {
    bool resultat = false;

    index--;
    if (index < this->quantite) {
        this->listeDeTaches[index].marquerFait();
    }

    return resultat;
}

bool Personne::annuleTacheCompletee(int index) {
    bool resultat = false;

    index--;
    if (index < this->quantite) {
        this->listeDeTaches[index].marquerNonFait();
    }

    return resultat;
}

/** ===========================================================================
 * Autres fonctions publiques
 * ========================================================================= */

bool Personne::ajouterTache(std::string &description) {
    bool resultat = true;
    this->listeDeTaches[this->quantite].donnerDescription(description);
    this->quantite++;

    if (this->quantite == taille) {
        resultat = this->aggrandirListeTaches();
    }

    return resultat;
}

bool Personne::supprimerTache(int index) {
    bool resultat = false;

    index--;
    if (index < this->quantite) {
        for (uint8_t i = index; i < quantite - 1; i++) {
            this->listeDeTaches[i] = this->listeDeTaches[i + 1];
        }
        this->quantite--;
        resultat = true;
    }

    return resultat;
}

/** ===========================================================================
 * Méthodes privées
 * ========================================================================= */

bool Personne::aggrandirListeTaches(void) {
    bool resultat = false;

    if (this->taille < TAILLE_LISTE_TACHE_MAXIMAL) {
        this->taille += TAILLE_LISTE_TACHE_INCREMENT;
        Tache *listeTachesTampon = new Tache[this->taille];
        for (uint8_t i = 0; i < this->quantite; i++) {
            listeTachesTampon[i] = this->listeDeTaches[i];
        }
        delete[] this->listeDeTaches;
        this->listeDeTaches = listeTachesTampon;
        resultat = true;
    }

    return resultat;
}
