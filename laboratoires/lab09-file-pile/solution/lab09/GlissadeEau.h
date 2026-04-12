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

    std::list<Tube> _tubes;
    std::stack<Tube*> _tubesDisponibles;
    std::stack<Tube*> _depotTubes;
    std::vector<Toboggan> _toboggans;

    std::queue<Visiteur*> _fileEntree;
    std::queue<Visiteur*> _fileMontee;
    std::queue<Visiteur*> _zoneArrivee;
    std::queue<Visiteur*> _fileSortie;
public:
    GlissadeEau();

    const Time& getHeure() const;

    void mettreAJour();
    void ajouterVisiteur(Visiteur* visiteur);
    Visiteur* traiterSortie();
    void afficher(std::ostream& sortie) const;
};

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade);

#endif //LAB09_GLISSADEEAU_H