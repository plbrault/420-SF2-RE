//
// Created by plbrault on 2026-01-28.
//

#ifndef LAB02A_PLANETE_H
#define LAB02A_PLANETE_H

#include <iostream>

class Planete {
private:
    std::string _nom;
    double _rayon;
    double _masse;
    double _distanceEtoile;

public:
    Planete();
    Planete(std::string nom, double rayon, double masse, double distanceEtoile);

    std::string getNom() const;
    double getRayon() const;
    double getMasse() const;
    double getDistanceEtoile() const;

    void setNom(std::string nom);
    void setRayon(double rayon);
    void setMasse(double masse);
    void setDistanceEtoile(double distanceEtoile);

    double getGraviteSurface();

    void afficher(std::ostream &sortie);
    void afficher();
};


#endif //LAB02A_PLANETE_H