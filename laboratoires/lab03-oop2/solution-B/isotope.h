#ifndef __ISOTOPE_H
#define __ISOTOPE_H

#include <string>

class Isotope {
private:
    std::string _nom;
    uint8_t _nbNeutron;
    double _occurence;
    bool _stable;
    double _demiVie;
    double _masse;

public:
    Isotope();
    Isotope(const std::string &, uint8_t, double, double);
    Isotope(const std::string &, uint8_t, double, double, double);

    std::string getNom() const;
    uint8_t getNbNeutron() const;
    double getOccurence() const;
    bool isStable() const;
    double getDemiVie() const;
    double getMasse() const;

    void setNom(const std::string &);
    void setNbNeutron(uint8_t);
    void setOccurence(double);
    void setStable(bool);
    void setDemiVie(double);
    void setMasse(double);
};

#endif