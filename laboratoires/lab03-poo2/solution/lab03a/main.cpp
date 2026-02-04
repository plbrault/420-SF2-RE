#include <iostream>
#include "Planete.h"

const size_t NOMBRE_PLANETES = 8;

int main() {
    Planete systemeSolaire[NOMBRE_PLANETES];

    systemeSolaire[0].setNom("Mercure");
    systemeSolaire[0].setRayon(2439000);
    systemeSolaire[0].setMasse(3.301e23);
    systemeSolaire[0].setDistanceEtoile(5.79e7);

    systemeSolaire[1].setNom("Vénus");
    systemeSolaire[1].setRayon(6052000);
    systemeSolaire[1].setMasse(4.867e24);
    systemeSolaire[1].setDistanceEtoile(1.082e8);

    systemeSolaire[2].setNom("Terre");
    systemeSolaire[2].setRayon(6371000);
    systemeSolaire[2].setMasse(5.972e24);
    systemeSolaire[2].setDistanceEtoile(1.496e8);

    systemeSolaire[3].setNom("Mars");
    systemeSolaire[3].setRayon(3390000);
    systemeSolaire[3].setMasse(6.39e23);
    systemeSolaire[3].setDistanceEtoile(2.279e8);

    systemeSolaire[4].setNom("Jupiter");
    systemeSolaire[4].setRayon(69911000);
    systemeSolaire[4].setMasse(1.898e27);
    systemeSolaire[4].setDistanceEtoile(7.785e8);

    systemeSolaire[5].setNom("Saturne");
    systemeSolaire[5].setRayon(58232000);
    systemeSolaire[5].setMasse(5.683e26);
    systemeSolaire[5].setDistanceEtoile(1.433e9);

    systemeSolaire[6].setNom("Uranus");
    systemeSolaire[6].setRayon(25362000);
    systemeSolaire[6].setMasse(8.681e25);
    systemeSolaire[6].setDistanceEtoile(2.877e9);

    systemeSolaire[7].setNom("Neptune");
    systemeSolaire[7].setRayon(24622000);
    systemeSolaire[7].setMasse(1.024e26);
    systemeSolaire[7].setDistanceEtoile(4.503e9);

    std::cout << "=== PLANÈTES DU SYSTÈME SOLAIRE ===" << std::endl
              << "===================================" << std::endl << std::endl;

    for (size_t i = 0; i < NOMBRE_PLANETES; i++) {
        systemeSolaire[i].afficher();
        std::cout << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}