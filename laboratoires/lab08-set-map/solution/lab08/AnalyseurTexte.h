#pragma once

#include <map>
#include <string>
#include <vector>

class AnalyseurTexte {
private:
    std::string _texte;
    std::map<char, unsigned int> _occurencesLettres;
    std::vector<char> _lettresTriees;

    void _preparerTexte();
    void _retirerMotsTropFrequents();
    void _compterLettres();
    void _trierLettres();
public:
    void analyser(const std::string& texte);
    std::vector<char> getLettresTriees();
};
