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

    void changerPrenom(const std::string &);
    void changerNom(const std::string &);
    std::string obtenirNomComplet();

    void ajouterTache(const Tache &);
    Tache *obtenirTache(size_t);
    
    size_t obtenirNombreTache();

    void echangerTache(size_t, size_t);
    void supprimerTache(size_t);
    
    std::string obtenirChaine();
};

#endif