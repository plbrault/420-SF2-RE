#ifndef __ELEMENT_H
#define __ELEMENT_H

#include <string>
#include <cstdint>

#include "Isotope.h"

#define ISOTOPE_CAPACITE_INCREMENT 10

class Element {
private:
    std::string _nom;
    uint8_t _nbParticuleChargee;
    uint8_t _nbTrou;
    std::string _groupe;
    std::string _symbole;
    Isotope *_isotopes;
    size_t _qtIsotopes;
    size_t _capaciteIsotopes;

    void _agrandirTableauIsotope();
public:
    Element(const std::string &, const std::string &, uint8_t, uint8_t, const std::string &);
    Element(const Element &);
    ~Element();

    Element &operator=(const Element &);

    void ajouterIsotope(const Isotope &);
    size_t nbIsotope() const;
    bool aIsotopeStable() const;

    std::string getNom() const;
    uint8_t getNombreParticulesChargees() const;

    std::string toString() const;
};

std::ostream& operator<<(std::ostream&, const Element&);

#endif