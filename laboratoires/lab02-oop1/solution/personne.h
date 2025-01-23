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

public:
    Personne();
    Personne(const std::string &, const std::string &);

};

#endif