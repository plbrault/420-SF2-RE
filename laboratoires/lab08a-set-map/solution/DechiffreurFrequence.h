#pragma once

#include "Dechiffreur.h"
#include <map>
#include <vector>

class DechiffreurFrequence : public Dechiffreur {
private:
    const std::map<float, std::vector<char>>* _lettresParFrequenceLangue;
    size_t _nombreLettres;
    std::map<char, unsigned int> _occurencesLettres;

    void _compterLettres();
public:
    DechiffreurFrequence(const std::map<float, std::vector<char>>* lettresParFrequenceLangue);
    void dechiffrer() override;
};