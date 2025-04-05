#pragma once

#include "Dechiffreur.h"
#include <map>
#include <vector>

class DechiffreurFrequence : public Dechiffreur {
private:
    std::map<float, std::vector<char>> _lettresParFrequenceLangue;
    std::vector<char> _lettresTrieesLangue;

    std::map<char, unsigned int> _occurencesLettresTexte;
    std::vector<char> _lettresTrieesTexte;
    std::map<char, char> _substitutions;

    void _trierLettresLangue();
    void _compterLettresTexte();
    void _trierLettresTexte();
    void _genererSubstitutions();
public:
    DechiffreurFrequence(const std::map<float, std::vector<char>> lettresParFrequenceLangue);
    void dechiffrer() override;
};