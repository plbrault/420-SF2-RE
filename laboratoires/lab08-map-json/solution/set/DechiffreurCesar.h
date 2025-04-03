#pragma once

#include "Dechiffreur.h"
#include <set>

class DechiffreurCesar : public Dechiffreur {
private:
    const std::set<std::string>* _langue;
public:
    DechiffreurCesar(const std::set<std::string>* mots);
    void dechiffrer() override;
};
