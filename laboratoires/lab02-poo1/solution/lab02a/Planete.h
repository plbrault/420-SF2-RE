//
// Created by plbrault on 2026-01-28.
//

#ifndef LAB02A_PLANETE_H
#define LAB02A_PLANETE_H

#include <iostream>

class Planete {
private:
    std::string _nom;
    unsigned int _rayon;
    double _masse;
    double _distanceSoleil;

public:
    Planete();
    Planete(std::string nom, unsigned int rayon, double masse, double distanceSoleil);

    void afficher(std::ostream &sortie);
    void afficher();

    double calculerGraviteSurface();
};


#endif //LAB02A_PLANETE_H