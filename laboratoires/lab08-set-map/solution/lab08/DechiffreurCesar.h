#pragma once

#include "Dechiffreur.h"
#include <set>
#include <vector>
#include "Langue.h"

class DechiffreurCesar : public Dechiffreur {
private:
    std::vector<char> _lettresMinuscules;
    std::vector<char> _lettresMajuscules;
    char _decalerLettre(char lettre, int decalage) const;
    bool _essayerDecalage(const std::string& mot, int decalage) const;
public:
    DechiffreurCesar(const Langue* langue);
    void dechiffrer() override;
};
