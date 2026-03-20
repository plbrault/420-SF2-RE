#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Element.h"

class Molecule
{
private:
    struct ElementMolecule
    {
        Element element;
        int _nombreAtomes;
    };

    std::vector<ElementMolecule> _elements;
    std::string _formule;
public:
    Molecule() : Molecule("", std::vector<Element>(), std::vector<int>()) {}
    Molecule(const std::string& formule, const std::vector<Element>& elements, const std::vector<int>& nombreAtomes);

    const std::string& getFormule() const;
    size_t getNombreElements() const;

    const Element& getElement(size_t indice) const;
    int getNombreAtomes(size_t indice) const;
    int getNombreAtomes(const std::string& symbole) const;
    int getNombreAtomes(const Element& element) const;
};

std::ostream& operator<<(std::ostream& output, const Molecule& molecule);
