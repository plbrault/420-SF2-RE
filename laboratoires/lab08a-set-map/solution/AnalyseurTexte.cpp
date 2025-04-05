#include "AnalyseurTexte.h"
#include <map>

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

void AnalyseurTexte::analyser(const std::string& texte) {
    _texte = texte;
    _compterLettres();
    _trierLettres();
}

vector<char> AnalyseurTexte::getLettresTriees() {
    return _lettresTriees;
}
