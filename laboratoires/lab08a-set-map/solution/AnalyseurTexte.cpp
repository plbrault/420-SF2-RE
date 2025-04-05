#include "AnalyseurTexte.h"
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

void AnalyseurTexte::_compterLettres() {
    for (char lettre = 'a'; lettre <= 'z'; lettre++) {
        _occurencesLettres[lettre] = 0;
    }
    for (auto caractere : _texte) {
        if ('a' <= tolower(caractere) && tolower(caractere) <= 'z') {
            _occurencesLettres[tolower(caractere)]++;
        }
    }
}

void AnalyseurTexte::_trierLettres() {
    _lettresTriees.clear();
    map<unsigned int, vector<char>> lettresParOccurences;
    for (auto it = _occurencesLettres.begin(); it != _occurencesLettres.end(); it++) {
        lettresParOccurences[it->second].push_back(it->first);
    }
    for (auto it = lettresParOccurences.begin(); it != lettresParOccurences.end(); it++) {
        for (auto lettre : it->second) {
            _lettresTriees.push_back(lettre);
        }
    }
}

void AnalyseurTexte::_preparerTexte() {
    set<char> ponctuation = {'.', ',', ';', ':', '!', '?', '-', '_', '(', ')', '[', ']', '{', '}', '\'', '"', '\n', '\r', '\t'};
    for (auto& caractere : _texte) {
        if (ponctuation.contains(caractere)) {
            caractere = ' ';
        }
    }
}

void AnalyseurTexte::_retirerMotPlusFrequent() {
    string mot;
    map<string, unsigned int> occurencesMots;
    stringstream flux1, flux2;

    flux1.str(_texte);
    while (flux1 >> mot) {
        occurencesMots[mot]++;
    }

    flux1.clear();
    flux1.str(_texte);
    while (flux1 >> mot) {
        if (mot.length() < 4 || occurencesMots[mot] < 0.05 * occurencesMots.size()) {
            flux2 << mot << " ";
        }
    }
    _texte = flux2.str();

    ;
}

void AnalyseurTexte::analyser(const std::string& texte) {
    _texte = texte;
    _preparerTexte();
    _retirerMotPlusFrequent();
    _compterLettres();
    _trierLettres();
}

vector<char> AnalyseurTexte::getLettresTriees() {
    return _lettresTriees;
}
