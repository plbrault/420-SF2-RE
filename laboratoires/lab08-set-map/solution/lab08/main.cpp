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
    ofstream sortie;

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
    dechiffreurCesar.dechiffrer();
    cout << dechiffreurCesar.getTexteDechiffre();
    sortie.open("sortie-cesar.txt");
    if (!sortie) {
        cerr << "Erreur d'ouverture du fichier de sortie" << endl;
        return 1;
    }
    sortie << dechiffreurCesar.getTexteDechiffre();
    sortie.close();

    // Déchiffrement du deuxième texte
    cout << "-----------------------------------------------" << endl;
    dechiffreurFrequence.dechiffrer();

    // Substitutions manuelles
    vector<string> lignesTexteDechiffre = split(dechiffreurFrequence.getTexteDechiffre(), '\n');
    char ancien, nouveau;
    for (size_t i = 0; i < lignesTexteDechiffre.size(); i++) {
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
    cout << "DEUXIÈME TEXTE DÉCHIFFRÉ:" << endl << dechiffreurFrequence.getTexteDechiffre() << endl;

    sortie.open("sortie-frequence.txt");
    if (!sortie) {
        cerr << "Erreur d'ouverture du fichier de sortie" << endl;
        return 1;
    }
    sortie << dechiffreurFrequence.getTexteDechiffre();
    sortie.close();

    return 0;
}