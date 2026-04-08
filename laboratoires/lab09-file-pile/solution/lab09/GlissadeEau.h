//
// Created by braultpi on 2026-04-08.
//

#ifndef LAB09_GLISSADEEAU_H
#define LAB09_GLISSADEEAU_H

#include <queue>
#include <stack>
#include <list>
#include "Visiteur.h"
#include "Bouee.h"

class GlissadeEau {
private:
    std::queue<Visiteur*> _fileEntree;
    std::vector<std::stack<Bouee>> _pilesPriseBouee;
    std::queue<Visiteur*> _fileMontee;
    std::queue<Visiteur*> _toboggan;
    std::list<Visiteur*> _zoneArrivee;
    std::vector<std::stack<Bouee>> _pilesDepotBouee;
    std::queue<Visiteur*> _fileSortie;
public:
    GlissadeEau();
    
};


#endif //LAB09_GLISSADEEAU_H