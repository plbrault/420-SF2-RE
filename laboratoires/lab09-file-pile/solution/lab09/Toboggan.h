//
// Created by plbrault on 2026-04-11.
//

#ifndef LAB09_TOBOGGAN_H
#define LAB09_TOBOGGAN_H

#include <queue>
#include <map>
#include "Visiteur.h"
#include "Time.h"

class Toboggan
{
private:
    std::queue<Visiteur*> _glisseurs;
    std::map<Visiteur*, Time> _heureEntree;
public:
    bool accepteGlisseur(const Time& heureActuelle) const;
    void ajouterGlisseur(Visiteur* visiteur, const Time& heure);
    Visiteur* traiterSortie(const Time& heureActuelle);
    size_t getNombreGlisseurs() const;
};


#endif //LAB09_TOBOGGAN_H