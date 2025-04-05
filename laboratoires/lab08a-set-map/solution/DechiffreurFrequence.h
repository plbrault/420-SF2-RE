#pragma once

#include "Dechiffreur.h"
#include <map>
#include <vector>

class DechiffreurFrequence : public Dechiffreur {
private:
    std::map<char, unsigned int> _occurencesLettresTexte;
    std::vector<char> _lettresTrieesTexte;
    std::map<char, char> _substitutions;

    void _compterLettresTexte();
    void _trierLettresTexte();
    void _genererSubstitutions();
public:
    DechiffreurFrequence(const Langue* langue) : Dechiffreur(langue) {}
    void dechiffrer() override;
};