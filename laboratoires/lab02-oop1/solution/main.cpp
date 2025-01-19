#include <iostream>
#include <stdint.h>
#include <string>

#include "personne.h"

int main() {
    std::locale::global(std::locale{ "" });

    int choix;

    std::string prenom;
    std::cout << "Quel est ton prénom ? ";
    std::cin >> prenom;

    std::string nom;
    std::cout << "Quel est ton nom ? ";
    std::cin >> nom;

    Personne toi(prenom, nom);
    std::cout << "Bonjour a toi, " << toi.obtenirNomComplet() << std::endl;

    do {

    } while(choix != 'q');

    return 0;

}