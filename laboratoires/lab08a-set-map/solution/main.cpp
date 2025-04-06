#include <iostream>
#include <fstream>
#include "JSONParser.h"
#include "DechiffreurCesar.h"
#include "DechiffreurFrequence.h"
#include "Langue.h"
#include "fonctions.h"

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

    // Substitutions manuelles
    vector<string> lignesTexteDechiffre = split(dechiffreurFrequence.getTexteDechiffre(), '\n');
    char ancien, nouveau;
    for (int i = 0; i < lignesTexteDechiffre.size(); i++) {
        while (lignesTexteDechiffre[i] != "" && ancien != '.' && ancien != '!') {
            cout << lignesTexteDechiffre[i] << endl;
            cout << ">>> Entrer une nouvelle substitution (ancien nouveau), ou « . » pour passer à la ligne suivante, ou « ! » pour terminer." << endl;
            cin >> ancien;
            if (ancien != '.' && ancien != '!') {
                cin >> nouveau;
                dechiffreurFrequence.changerSubstitution(ancien, nouveau);
                lignesTexteDechiffre = split(dechiffreurFrequence.getTexteDechiffre(), '\n');
            }
        } if (ancien == '!') {
            break;
        }
        ancien = '\0';
    }
    cout << "Texte déchiffré:" << endl << dechiffreurFrequence.getTexteDechiffre() << endl;

    return 0;
}