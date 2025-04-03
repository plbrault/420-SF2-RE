#pragma once

#include <iostream>

class Dechiffreur {
protected:
    std::string _texteChiffre;
    std::string _texteDechiffre;
public:
    void lireTexteChiffre(std::istream& entree);
    virtual void dechiffrer() = 0;
    const std::string& getTexteChiffre() const;
    const std::string& getTexteDechiffre() const;
};