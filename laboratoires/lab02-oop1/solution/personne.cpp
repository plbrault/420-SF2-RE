#include "personne.h"

#include <sstream>

Personne::Personne(const std::string &prenom, const std::string &nom) {
    this->_prenom = prenom;
    this->_nom = nom;

    this->_quantiteTaches = 0;
    this->_capaciteTableauTaches = TAILLE_LISTE_TACHE_INC;
    this->_taches = new Tache[this->_capaciteTableauTaches];
}

Personne::~Personne() {
    if (this->_taches != nullptr) {
        delete [] this->_taches;
    }
}

void Personne::ajouterTache(const Tache &tache) {
    this->_taches[this->_quantiteTaches] = tache;
    
    this->_quantiteTaches++;

    if (this->_quantiteTaches == this->_capaciteTableauTaches) {
        this->_agrandirTableauTache();
    }
}

Tache *Personne::obtenirTache(size_t index) {
    index--;

    if (index < this->_quantiteTaches) {
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

    flux << this->_prenom << " " << this->_nom;
    
    return flux.str();
}

std::string Personne::obtenirChaine() {
    std::ostringstream flux;

    flux << "Liste de tâches de " << this->obtenirNomComplet() << " : " << std::endl;

    for (size_t i = 0; i < this->_quantiteTaches; i++) {
        flux << this->_taches[i].obtenirChaine(i + 1) << std::endl;
    }
    
    return flux.str();
}

size_t Personne::obtenirNombreTaches() {
    return this->_quantiteTaches;
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

    if (index < this->_quantiteTaches) {
        for (size_t i = index; i < this->_quantiteTaches - 1; i++) {
            this->_taches[i] = this->_taches[i + 1];
        }
    }

    this->_quantiteTaches--;
}

void Personne::_agrandirTableauTache() {
    if (this->_taches != nullptr) {
        this->_capaciteTableauTaches += TAILLE_LISTE_TACHE_INC;
        Tache *tampon = new Tache[this->_capaciteTableauTaches];

        for (size_t i = 0; i < this->_quantiteTaches; i++) {
            tampon[i] = this->_taches[i];
        }

        this->_taches = tampon;
        tampon = nullptr;
    }
}