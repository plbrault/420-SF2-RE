#pragma once

#include <string>

class Element {
private:
    std::string _nom;
    int _numeroAtomique;
    std::string _symbole;
    double _masseAtomique;

public:
    Element() : Element("", 0, "", 0) {}
    Element(const std::string& nom, int numeroAtomique, const std::string& symbole, double masseAtomique);

    const std::string& getNom() const;
    int getNumeroAtomique() const;
    const std::string& getSymbole() const;
    double getMasseAtomique() const;

    void setNom(const std::string& nom);
    void setNumeroAtomique(int numeroAtomique);
    void setSymbole(const std::string& symbole);
    void setMasseAtomique(double masseAtomique);

    bool operator==(const Element& other) const;
};
