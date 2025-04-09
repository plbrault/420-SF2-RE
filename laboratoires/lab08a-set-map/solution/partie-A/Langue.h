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
    std::string _nomFichierFrequences;
    std::set<std::string> _mots;
    std::map<float, std::vector<char>> _lettresParFrequence;
    std::vector<char> _lettresTriees;
    bool _estCharge;

    void _trierLettres();
public:
    Langue(const std::string& nomFichierMots, const std::string& nomFichierFrequences);
    void charger();
    bool contientMot(const std::string& mot) const;
    const std::vector<char>& getLettresTriees() const;
};
