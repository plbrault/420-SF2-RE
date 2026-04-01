#include <iostream>
#include <fstream>
#include "JSONParser.h"
#include "DechiffreurCesar.h"
#include "DechiffreurFrequence.h"
#include "Langue.h"
#include "fonctions.h"

int main() {
    std::ifstream fluxTexteChiffre;
    std::ofstream sortie;

    Langue francais("../mots.json", "../frequences_lettres.json");
    francais.charger();

    DechiffreurCesar dechiffreurCesar(&francais);
    DechiffreurFrequence dechiffreurFrequence(&francais);

    // Lecture du premier texte à déchiffrer
    fluxTexteChiffre.open("../texte1.txt");
    if (!fluxTexteChiffre) {
        std::cerr << "Erreur d'ouverture du fichier" << std::endl;
        return 1;
    }
    dechiffreurCesar.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    // Lecture du deuxième texte à déchiffrer
    fluxTexteChiffre.open("../texte2.txt");
    if (!fluxTexteChiffre) {
        std::cerr << "Erreur d'ouverture du fichier" << std::endl;
        return 1;
    }
    dechiffreurFrequence.lireTexteChiffre(fluxTexteChiffre);
    fluxTexteChiffre.close();

    // Déchiffrement du premier texte
    dechiffreurCesar.dechiffrer();
    std::cout << dechiffreurCesar.getTexteDechiffre();
    sortie.open("sortie-cesar.txt");
    if (!sortie) {
        std::cerr << "Erreur d'ouverture du fichier de sortie" << std::endl;
        return 1;
    }
    sortie << dechiffreurCesar.getTexteDechiffre();
    sortie.close();

    // Déchiffrement du deuxième texte
    std::cout << "-----------------------------------------------" << std::endl;
    dechiffreurFrequence.dechiffrer();

    // Substitutions manuelles
    std::vector<std::string> lignesTexteDechiffre = split(dechiffreurFrequence.getTexteDechiffre(), '\n');
    char ancien, nouveau;
    for (size_t i = 0; i < lignesTexteDechiffre.size(); i++) {
        while (lignesTexteDechiffre[i] != "" && ancien != '.' && ancien != '!') {
            std::cout << lignesTexteDechiffre[i] << std::endl;
            std::cout << ">>> Entrer une nouvelle substitution (ancien nouveau), ou « . » pour passer à la ligne suivante, ou « ! » pour terminer." << std::endl;
            std::cin >> ancien;
            if (ancien != '.' && ancien != '!') {
                std::cin >> nouveau;
                dechiffreurFrequence.changerSubstitution(ancien, nouveau);
                lignesTexteDechiffre = split(dechiffreurFrequence.getTexteDechiffre(), '\n');
            }
        } if (ancien == '!') {
            break;
        }
        ancien = '\0';
    }
    std::cout << "DEUXIÈME TEXTE DÉCHIFFRÉ:" << std::endl << dechiffreurFrequence.getTexteDechiffre() << std::endl;

    sortie.open("sortie-frequence.txt");
    if (!sortie) {
        std::cerr << "Erreur d'ouverture du fichier de sortie" << std::endl;
        return 1;
    }
    sortie << dechiffreurFrequence.getTexteDechiffre();
    sortie.close();

    return 0;
}