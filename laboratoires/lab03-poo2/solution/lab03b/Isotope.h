#ifndef LAB03B_ISOTOPE_H
#define LAB03B_ISOTOPE_H

#include <iostream>
#include <limits>

class Isotope {
private:
    std::string _nom;
    int _nbNeutrons;
    double _occurence;
    double _demiVie;
    double _masse;

public:
    Isotope();
    Isotope(std::string nom, int nbNeutrons, double occurence, double masse);
    Isotope(std::string nom, int nbNeutrons, double occurence, double demiVie, double masse);

    std::string getNom() const;
    int getNbNeutrons() const;
    double getOccurence() const;
    double getDemiVie() const;
    double getMasse() const;

    void setNom(std::string nom);
    void setNbNeutrons(int nbNeutrons);
    void setOccurence(double occurence);
    void setDemiVie(double demiVie);
    void setMasse(double masse);

    bool estStable() const;
};

#endif //LAB03B_ISOTOPE_H
