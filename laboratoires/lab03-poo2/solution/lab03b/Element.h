#ifndef LAB03B_ELEMENT_H
#define LAB03B_ELEMENT_H

#include "Isotope.h"

class Element {
private:
    std::string _symbole;
    std::string _nom;
    int _nbParticulesChargees;
    std::string _groupe;
    Isotope* _isotopes;
    size_t _nombreIsotopes;
    size_t _capaciteIsotopes;

public:
    Element();
    Element(std::string symbole, std::string nom, int nbParticulesChargees, std::string groupe);
    Element(const Element& autreElement);
    ~Element();

    void ajouterIsotope(Isotope isotope);

    std::string getSymbole() const;
    std::string getNom() const;
    int getNbParticulesChargees() const;
    std::string getGroupe() const;
    size_t getNombreIsotopes() const;
    Isotope* getIsotope(size_t indice) const;

    void setSymbole(std::string symbole);
    void setNom(std::string nom);
    void setNbParticulesChargees(int nbParticulesChargees);
    void setGroupe(std::string groupe);

    bool aIsotopeStable() const;
};

#endif //LAB03B_ELEMENT_H
