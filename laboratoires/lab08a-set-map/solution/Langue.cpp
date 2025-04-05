#include "Langue.h"

using namespace std;

Langue::Langue(const string& nomFichierMots) {
    _nomFichierMots = nomFichierMots;
}

void Langue::charger() {
    ifstream fichier(_nomFichierMots);
    if (!fichier) {
        throw runtime_error("Impossible d'ouvrir le fichier " + _nomFichierMots);
    }
    _jsonParser.parse(fichier);
    fichier.close();
    _mots = _jsonParser.getData().template get<set<string>>();
    _estCharge = true;
}

const set<string>& Langue::getMots() const {
    if (!_estCharge) {
        throw runtime_error("Langue non chargée.");
    }
    return _mots;
}
