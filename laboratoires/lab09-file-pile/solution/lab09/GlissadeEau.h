//
// Created by braultpi on 2026-04-08.
//

#ifndef LAB09_GLISSADEEAU_H
#define LAB09_GLISSADEEAU_H

#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include "Visiteur.h"
#include "Tube.h"
#include "Toboggan.h"
#include "Time.h"

class GlissadeEau {
private:
    Time _heureActuelle;
    int _totalVisiteursJournee;

    std::list<Tube> _tubes;
    std::stack<Tube*> _tubesDisponibles;
    std::stack<Tube*> _depotTubes;
    std::vector<Toboggan> _toboggans;

    std::queue<Visiteur*> _fileEntree;
    std::queue<Visiteur*> _fileMontee;
    std::map<Visiteur*, Time> _zoneArrivee;
public:
    GlissadeEau() : GlissadeEau(1, 30) {}
    GlissadeEau(size_t nombreToboggans, size_t nombreTubes);

    const Time& getHeureActuelle() const;

    void mettreAJour();
    void ajouterVisiteur(Visiteur* visiteur);
    Visiteur* traiterSortie();
    void afficher(std::ostream& sortie) const;
};

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade);

#endif //LAB09_GLISSADEEAU_H