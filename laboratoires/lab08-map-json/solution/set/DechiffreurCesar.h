#pragma once

#include "Dechiffreur.h"
#include <set>
#include <vector>

class DechiffreurCesar : public Dechiffreur {
private:
    const std::set<std::string>* _langue;

    std::vector<char> _lettresMinuscules;
    std::vector<char> _lettresMajuscules;
    char _decalerLettre(char lettre, int decalage) const;
    bool _essayerDecalage(const std::string& mot, int decalage) const;
public:
    DechiffreurCesar(const std::set<std::string>* mots);
    void dechiffrer() override;
};
