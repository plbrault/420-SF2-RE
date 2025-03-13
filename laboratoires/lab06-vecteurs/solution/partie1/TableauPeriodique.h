#pragma once

#include <iostream>
#include <vector>
#include "CSVParser.h"
#include "Element.h"

class TableauPeriodique {
private:
    CSVParser _parser;
    std::vector<Element> _elements;
public:
    void charger(const std::string& nomFichier);
    void afficher(std::ostream& sortie);
};

std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
