// #pragma once
//
// #include <iostream>
// #include <vector>
// #include "CSVParser.h"
// #include "Element.h"
//
// class TableauPeriodique {
// private:
//     CSVParser _parser;
//     std::vector<Element> _elements;
// public:
//     TableauPeriodique();
//     void charger(const std::string& nomFichier);
//     void afficher(std::ostream& sortie);
//     const Element* trouverElementParSymbole(const std::string& symbole) const;
//     const Element* trouverElementParNom(const std::string& nom) const;
// };
//
// std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
