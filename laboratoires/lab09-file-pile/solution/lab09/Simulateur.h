//
// Created by plbrault on 2026-04-12.
//

#ifndef LAB09_SIMULATEUR_H
#define LAB09_SIMULATEUR_H

#include <set>
#include "GlissadeEau.h"

class Simulateur
{
private:
    GlissadeEau _glissade;
    std::set<Visiteur*> _visiteurs;

    double calculerTauxArrivee(unsigned long temps);
public:
    Simulateur();
    ~Simulateur();
    void simuler();
};


#endif //LAB09_SIMULATEUR_H