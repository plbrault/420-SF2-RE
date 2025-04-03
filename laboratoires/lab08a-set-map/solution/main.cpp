#include <iostream>
#include <fstream>
#include <set>
#include "JSONParser.h"
#include "DechiffreurCesar.h"

using namespace std;

int main() {
    JSONParser jsonParser;
    ifstream fluxLangueFrancaise("mots.json");
    ifstream fluxFrequencesLettres("frequences_lettres.json");
    ifstream fluxTexteChiffre;
    set<string> motsLangueFrancaise;
    map<float, vector<char>> lettresParFrequence;
    DechiffreurCesar cesar(&motsLangueFrancaise);

    // Chargement des mots de la langue française
    if (!fluxLangueFrancaise) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    jsonParser.parse(fluxLangueFrancaise);
    fluxLangueFrancaise.close();
    motsLangueFrancaise = jsonParser.getData().template get<set<string>>();

    // Chargement des lettres par fréquence
    if (!fluxFrequencesLettres) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    jsonParser.parse(fluxFrequencesLettres);
    fluxFrequencesLettres.close();
    lettresParFrequence = jsonParser.getData().template get<map<float, vector<char>>>();

    // Lecture du premier texte à déchiffrer
    fluxTexteChiffre.open("texte1.txt");
    if (!fluxTexteChiffre) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    cesar.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    // Déchiffrement du premier texte
    cesar.dechiffrer();
    cout << cesar.getTexteDechiffre();

    return 0;
}