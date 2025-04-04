#pragma once

#include "Dechiffreur.h"
#include <map>
#include <vector>

class DechiffreurFrequence : public Dechiffreur {
private:
    std::map<float, std::vector<char>> _lettresParFrequenceLangue;
    std::map<char, unsigned int> _occurencesLettres;
    std::vector<char> _lettresTrieesLangue;
    std::vector<char> _lettresTrieesTexte;
    std::map<char, char> _substitutitons;

    void _trierLettresLangue();
    void _compterLettresTexte();
    void _trierLettresTexte();
    void _genererSubstitutitons();
public:
    DechiffreurFrequence(const std::map<float, std::vector<char>> lettresParFrequenceLangue);
    void dechiffrer() override;
};