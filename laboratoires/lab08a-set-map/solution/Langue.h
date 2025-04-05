#pragma once

#include <set>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "JSONParser.h"

class Langue {
private:
    JSONParser _jsonParser;
    std::string _nomFichierMots;
    //std::string _nomFichierFrequences;
    std::set<std::string> _mots;
    //std::map<float, std::vector<char>> _lettresParFrequence;
    //std::vector<char> _lettresTriees;
    bool _estCharge;
public:
    Langue(const std::string& nomFichierMots);
    void charger();
    const std::set<std::string>& getMots() const;
};
