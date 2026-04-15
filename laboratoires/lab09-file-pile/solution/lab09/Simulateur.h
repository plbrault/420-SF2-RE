//
// Created by plbrault on 2026-04-12.
//

#ifndef LAB09_SIMULATEUR_H
#define LAB09_SIMULATEUR_H

#include <set>
#include <random>
#include <iostream>
#include "GlissadeEau.h"

class Simulateur
{
private:
    GlissadeEau _glissade;
    std::set<Visiteur*> _visiteurs;
    int _facteurVitesse;
    int _arriveesMinuteCourante;

    double calculerTauxArrivee(unsigned long secondesEcoulees);
    void simulerArrivees(std::mt19937& gen);
    void afficher() const;
public:
    explicit Simulateur(std::istream& fichierConfig);
    ~Simulateur();
    void simuler();
};


#endif //LAB09_SIMULATEUR_H