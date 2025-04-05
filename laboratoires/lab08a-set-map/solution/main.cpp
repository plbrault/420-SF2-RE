#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include "JSONParser.h"
#include "DechiffreurCesar.h"
#include "DechiffreurFrequence.h"
#include "Langue.h"

using namespace std;

int main() {
    ifstream fluxTexteChiffre;

    Langue francais("mots.json", "frequences_lettres.json");
    francais.charger();

    DechiffreurCesar dechiffreurCesar(&francais);
    DechiffreurFrequence dechiffreurFrequence(&francais);

    // Lecture du premier texte à déchiffrer
    fluxTexteChiffre.open("texte1.txt");
    if (!fluxTexteChiffre) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    dechiffreurCesar.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    // Lecture du deuxième texte à déchiffrer
    fluxTexteChiffre.open("texte2.txt");
    if (!fluxTexteChiffre) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        return 1;
    }
    dechiffreurFrequence.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    // Déchiffrement du premier texte
    //dechiffreurCesar.dechiffrer();
    //cout << dechiffreurCesar.getTexteDechiffre();

    // Déchiffrement du deuxième texte
    dechiffreurFrequence.dechiffrer();
    cout << dechiffreurFrequence.getTexteDechiffre();

    char ancien, nouveau;
    while (true) {
        cout << "Entrez une nouvelle substitution (ancien nouveau): ";
        cin >> ancien >> nouveau;
        dechiffreurFrequence.changerSubstitution(ancien, nouveau);
        cout << "-------------------------" << endl;
        cout << dechiffreurFrequence.getTexteDechiffre();
    }

    return 0;
}