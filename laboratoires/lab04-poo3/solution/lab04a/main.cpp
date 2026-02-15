#include <iostream>
#include "Planete.h"
#include "SystemePlanetaire.h"
#include "Menu.h"

const size_t NOMBRE_PLANETES = 8;

int main() {
    SystemePlanetaire systemeSolaire("Système solaire");

    systemeSolaire += Planete("Mercure", 2439000, 3.301e23, 5.79e7);
    systemeSolaire += Planete("Vénus", 6052000, 4.867e24, 1.082e8);
    systemeSolaire += Planete("Terre", 6371000, 5.972e24, 1.496e8);
    systemeSolaire += Planete("Mars", 3390000, 6.39e23, 2.279e8);
    systemeSolaire += Planete("Jupiter", 69911000, 1.898e27, 7.785e8);
    systemeSolaire += Planete("Saturne", 58232000, 5.683e26, 1.433e9);
    systemeSolaire += Planete("Uranus", 25362000, 8.681e25, 2.877e9);
    systemeSolaire += Planete("Neptune", 24622000, 1.024e26, 4.503e9);

    Menu menu(true);
    menu.ajouterOption("Afficher toutes les planètes");
    menu.ajouterOption("Rechercher une planète par numéro");
    menu.ajouterOption("Rechercher une planète par nom");

    int choix;
    do {
        int numeroPlanete;
        std::string nomPlanete;
        Planete planete;

        std::cout << menu.obtenirChaine();
        choix = menu.demanderChoix();

        switch (choix) {
            case 1:
                std::cout << systemeSolaire;
                break;
            case 2:
                std::cout << "Entrer le numéro de la planète: ";
                std::cin >> numeroPlanete;
                try {
                    planete = systemeSolaire[numeroPlanete - 1];
                    std::cout << planete << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Numéro de planète invalide. " << std::endl;
                }
                break;
            case 3:
                std::cout << "Entrer le nom de la planète: ";
                std::cin >> nomPlanete;
                try {
                    planete = systemeSolaire[nomPlanete];
                    std::cout << planete << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Nom de planète invalide. " << std::endl;
                }
                std::cout << std::endl;
                break;
        }
    } while (!menu.estQuitter(choix));

    std::cout << "Au revoir!" << std::endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}