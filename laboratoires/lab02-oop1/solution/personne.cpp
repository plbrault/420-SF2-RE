#include "personne.h"

Personne::Personne() : Personne::Personne("", "") { }

Personne::Personne(const std::string &prenom, const std::string &nom) {
    this->_prenom = prenom;
    this->_nom = nom;

    this->_quantite = 0;
    this->_taille = TAILLE_LISTE_TACHE_INC;
    this->_taches = new Tache[this->_taille];
}