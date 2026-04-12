//
// Created by braultpi on 2026-04-08.
//

#ifndef LAB09_GLISSADEEAU_H
#define LAB09_GLISSADEEAU_H

#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include "Visiteur.h"
#include "Tube.h"
#include "Toboggan.h"

class GlissadeEau {
private:
    std::list<Tube> _tubes;
    std::queue<Visiteur*> _fileEntree;
    std::stack<Tube*> _tubesDisponibles;
    std::queue<Visiteur*> _fileMontee;
    Toboggan _toboggan;
    std::queue<Visiteur*> _zoneArrivee;
    std::stack<Tube*> _depotTubes;
    std::queue<Visiteur*> _fileSortie;

    Duration _tempsActuel;
public:
    GlissadeEau();

    const Duration& getTemps() const;

    void mettreAJour();
    void ajouterVisiteur(Visiteur* visiteur);
    Visiteur* traiterSortie();
    void afficher(std::ostream& sortie) const;
};

std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade);

#endif //LAB09_GLISSADEEAU_H