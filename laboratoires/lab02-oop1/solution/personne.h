#ifndef __PERSONNE_H
#define __PERSONNE_H

#include <string>

#include "tache.h"

#define TAILLE_LISTE_TACHE_INC 10

class Personne {
private:
    std::string _prenom;
    std::string _nom;
    
    size_t _quantite;
    size_t _taille;
    Tache *_taches;

    void _agrandirTableauTache();
public:
    Personne();
    Personne(const std::string &, const std::string &);
    ~Personne();

    void ajouterTache(Tache &);
    Tache *obtenirTache(size_t);
    void changerPrenom(const std::string &);
    void changerNom(const std::string &);
    std::string obtenirNomComplet();
    std::string obtenirChaine();
};

#endif