#include <iostream>

#include "hanoi.h"

int main () {
    std::cout << "Lab 8" << std::endl;

    Hanoi game;
    game.newGame();

    bool ended = false;
    
    while (!ended) {
        std::cout << game << std::endl;

        int from;
        std::cout << "Sélectionner la tour de provenance: ";
        std::cin >> from;

        while (from < 1 || from > 3) {
            std::cout << "SVP, saisir une valeur entre 1 et 3" << std::endl;
            std::cout << "Sélectionner la tour de provenance: ";
            std::cin >> from;
        }

        int target;
        std::cout << "Sélectionner la tour cible: ";
        std::cin >> target;

        while ((target < 1 || target > 3) && from != target) {
            std::cout << "SVP, saisir une valeur entre 1 et 3, différente de provenance" << std::endl;
            std::cout << "Sélectionner la tour cible : ";
            std::cin >> target;
        }

        if (game[from - 1].transfert(game[target - 1])) {
            std::cout << "Déplacement valide" << std::endl;
        } else {
            std::cout << "ERREUR: Déplacement invalide" << std::endl;
        }

        char again;
        std::cout << "Voulez-vous continuer ? [o|n]: ";
        std::cin >> again;

        ended = tolower(again) != 'o';
    }
    
    std::cout << game << std::endl;
    return 0;
}
