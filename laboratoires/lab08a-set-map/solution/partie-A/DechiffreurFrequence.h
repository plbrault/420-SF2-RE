#pragma once

#include "Dechiffreur.h"
#include "AnalyseurTexte.h"
#include <map>

class DechiffreurFrequence : public Dechiffreur {
private:
    AnalyseurTexte _analyseur;
    std::map<char, char> _substitutions;

    void _genererSubstitutions();
    void _substituer();
public:
    DechiffreurFrequence(const Langue* langue) : Dechiffreur(langue) {}
    void dechiffrer() override;
    void changerSubstitution(char ancien, char nouveau);
};