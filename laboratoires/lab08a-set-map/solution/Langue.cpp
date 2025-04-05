#include "Langue.h"

using namespace std;

Langue::Langue(const string& nomFichierMots, const string& nomFichierFrequences) {
    _nomFichierMots = nomFichierMots;
    _nomFichierFrequences = nomFichierFrequences;
    _estCharge = false;
}

void Langue::_trierLettres() {
    for (auto it = _lettresParFrequence.begin(); it != _lettresParFrequence.end(); it++) {
        for (auto lettre : it->second) {
            _lettresTriees.push_back(lettre);
        }
    }
}

void Langue::charger() {
    ifstream fichier;

    fichier.open(_nomFichierMots);
    if (!fichier) {
        throw runtime_error("Impossible d'ouvrir le fichier " + _nomFichierMots);
    }
    _jsonParser.parse(fichier);
    fichier.close();
    _mots = _jsonParser.getData().template get<set<string>>();

    fichier.open(_nomFichierFrequences);
    if (!fichier) {
        throw runtime_error("Impossible d'ouvrir le fichier " + _nomFichierFrequences);
    }
    _jsonParser.parse(fichier);
    fichier.close();

    for (const auto& [frequence, lettres] : _jsonParser.getData().template get<map<string, vector<string>>>()) {
        float frequenceFloat = stof(frequence);
        for (const auto& lettre : lettres) {
            _lettresParFrequence[frequenceFloat].push_back(lettre[0]);
        }
    }

    _estCharge = true;
}

const set<string>& Langue::getMots() const {
    if (!_estCharge) {
        throw runtime_error("Langue non chargée.");
    }
    return _mots;
}

const vector<char>& Langue::getLettresTriees() const {
    if (!_estCharge) {
        throw runtime_error("Langue non chargée.");
    }
    return _lettresTriees;
}
