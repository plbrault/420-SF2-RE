#pragma once

#include <vector>
#include "CSVParser.h"
#include "Element.h"
#include "Molecule.h"

class TableauPeriodique {
private:
    CSVParser _parser;
    std::vector<Element> _elements;
    bool _estTrieParNom;
public:
    TableauPeriodique();
    void charger(const std::string& nomFichier);
    void afficher(std::ostream& sortie);
    void trierParNom();
    void trierParNumeroAtomique();
    const Element& trouverElementParSymbole(const std::string& symbole) const;
    const Element& trouverElementParNom(const std::string& nom) const;
    const Element& trouverElementParNumeroAtomique(int numeroAtomique) const;
    Molecule creerMolecule(const std::string& formule) const;
};

// std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
