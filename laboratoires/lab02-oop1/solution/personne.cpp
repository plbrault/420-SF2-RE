#include "personne.h"

#include <sstream>

Personne::Personne() : Personne::Personne("", "") { }

Personne::Personne(const std::string &prenom, const std::string &nom) {
    this->_prenom = prenom;
    this->_nom = nom;

    this->_quantite = 0;
    this->_taille = TAILLE_LISTE_TACHE_INC;
    this->_taches = new Tache[this->_taille];
}

Personne::~Personne() {
    if (this->_taches != nullptr) {
        delete [] this->_taches;
    }
}

void Personne::ajouterTache(Tache &tache) {
    this->_taches[this->_quantite] = tache;
    
    this->_quantite++;

    if (this->_quantite == this->_taille) {
        this->_agrandirTableauTache();
    }
}

Tache *Personne::obtenirTache(size_t index) {
    index--;

    if (index < this->_quantite) {
        return &(this->_taches[index]);
    } else {
        return nullptr;
    }
}

void Personne::changerPrenom(const std::string &prenom) {
    this->_prenom = prenom;
}

void Personne::changerNom(const std::string &nom) {
    this->_nom = nom;
}

std::string Personne::obtenirNomComplet() {
    std::ostringstream flux;

    flux << this->_prenom << " " << this->_nom << std::endl;

    for (size_t i = 0; i < this->_quantite; i++) {
        flux << this->_taches[i].obtenirChaine(i + 1) << std::endl;
    }
    
    return flux.str();
}

std::string Personne::obtenirChaine() {
    std::ostringstream flux;

    flux << "Liste de tâches de " << this->obtenirNomComplet() << " : " << std::endl;

    for (size_t i = 0; i < this->_quantite; i++) {
        flux << this->_taches[i].obtenirChaine(i + 1) << std::endl;
    }
    
    return flux.str();
}

size_t Personne::obtenirNombreTache() {
    return this->_quantite;
}

void Personne::echangerTache(size_t premier, size_t seconde) {
    premier--;
    seconde--;

    Tache temp = this->_taches[premier];
    this->_taches[premier] = this->_taches[seconde];
    this->_taches[seconde] = temp;
}

void Personne::supprimerTache(size_t index) {
    index--;

    if (index < this->_quantite) {
        for (size_t i = index; i < this->_quantite - 1; i++) {
            this->_taches[i] = this->_taches[i + 1];
        }
    }

    this->_quantite--;
}

void Personne::_agrandirTableauTache() {
    if (this->_taches != nullptr) {
        this->_taille += TAILLE_LISTE_TACHE_INC;
        Tache *tampon = new Tache[this->_taille];

        for (size_t i = 0; i < this->_quantite; i++) {
            tampon[i] = this->_taches[i];
        }

        this->_taches = tampon;
        tampon = nullptr;
    }
}