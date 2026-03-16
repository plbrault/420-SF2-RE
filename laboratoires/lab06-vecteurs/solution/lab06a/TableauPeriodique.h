#pragma once

#include <iostream>
#include <vector>
#include "CSVParser.h"
#include "Element.h"

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
    const Element* getElementParNom(const std::string& nom) const;
};

std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
