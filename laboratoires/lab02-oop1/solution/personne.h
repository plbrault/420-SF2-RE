#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <stdint.h>

#include "tache.h"

#define TAILLE_LISTE_TACHE_INCREMENT 10
#define TAILLE_LISTE_TACHE_MAXIMAL 100

class Personne {
private:

    std::string prenom;
    std::string nom;
    Tache *listeDeTaches;
    uint8_t taille;
    uint8_t quantite;

    bool aggrandirListeTaches(void);

public:

    Personne(std::string &, std::string &);

    ~Personne(void);

    std::string obtenirNomComplet(void);

    bool ajouterTache(std::string &);

    bool supprimerTache(int);

    std::string obtenirChaine(void);

    Tache *obtenirTache(int);

    bool completeTache(int);

    bool annuleTacheCompletee(int);

};


#endif