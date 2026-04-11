//
// Created by plbrault on 2026-04-11.
//

#ifndef LAB09_TOBOGGAN_H
#define LAB09_TOBOGGAN_H

#include <queue>
#include <map>
#include "Visiteur.h"
#include "Duration.h"

class Toboggan
{
private:
    std::queue<Visiteur*> _glisseurs;
    std::map<Visiteur*, Duration> _tempsEntree;
public:
    bool accepteGlisseur() const;
    void ajouterGlisseur(Visiteur* visiteur, const Duration& temps);
    Visiteur* verifierSortie(const Duration& temps);
    size_t getNombreGlisseurs() const;
};


#endif //LAB09_TOBOGGAN_H