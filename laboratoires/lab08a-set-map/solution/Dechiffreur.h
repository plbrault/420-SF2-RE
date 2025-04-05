#pragma once

#include <iostream>
#include "Langue.h"

class Dechiffreur {
protected:
    std::string _texteChiffre;
    std::string _texteDechiffre;
    const Langue* _langue;
public:
    Dechiffreur(const Langue* langue);
    void lireTexteChiffre(std::istream& entree);
    virtual void dechiffrer() = 0;
    const std::string& getTexteChiffre() const;
    const std::string& getTexteDechiffre() const;
};