#pragma once

#include "Dechiffreur.h"
#include <map>
#include <vector>

class DechiffreurFrequence : public Dechiffreur {
private:
    const std::map<float, std::vector<char>>* _lettresParFrequenceLangue;
    std::map<char, unsigned int> _occurencesLettres;
    std::vector<char> _lettresTrieesParOccurences;

    void _compterLettres();
    void _trierLettres();
public:
    DechiffreurFrequence(const std::map<float, std::vector<char>>* lettresParFrequenceLangue);
    void dechiffrer() override;
};