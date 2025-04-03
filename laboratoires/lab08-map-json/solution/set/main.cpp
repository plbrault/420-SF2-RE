#include <iostream>
#include <fstream>
#include <set>
#include "JSONParser.h"
#include "DechiffreurCesar.h"

using namespace std;

int main() {
    JSONParser jsonParser;
    ifstream fluxLangue("mots.json");
    ifstream fluxTexteChiffre;
    set<string> langue;
    DechiffreurCesar cesar(&langue);

    // Chargement de la langue
    if (!fluxLangue) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    jsonParser.parse(fluxLangue);
    fluxLangue.close();
    langue = jsonParser.getData().template get<set<string>>();

    // Lecture du premier texte à déchiffrer
    fluxTexteChiffre.open("texte1.txt");
    if (!fluxTexteChiffre) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    cesar.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    cout << cesar.getTexteChiffre();

    return 0;
}