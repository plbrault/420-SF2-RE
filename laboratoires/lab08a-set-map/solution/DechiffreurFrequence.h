#pragma once

#include "Dechiffreur.h"
#include <map>

class DechiffreurFrequence : Dechiffreur {
private:
    std::map<float, char> _lettresParFrequenceLangue;
    std::map<char, unsigned int> _occurencesLettres;

    void _compterLettres();
public:
    DechiffreurFrequence(const std::map<float, char>& lettresParFrequenceLangue);
    void dechiffrer() override;
};