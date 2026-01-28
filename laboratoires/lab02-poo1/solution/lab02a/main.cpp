#include <iostream>
#include "Planete.h"

const size_t NOMBRE_PLANETES = 8;

int main() {
    Planete mercure("Mercure", 2439000.0, 3.301e23, 5.79e7);
    Planete venus("Vénus", 6052000.0, 4.867e24, 1.082e8);
    Planete terre("Terre", 6371000.0, 5.972e24, 1.496e8);
    Planete mars("Mars", 3390000.0, 6.39e23, 2.279e8);
    Planete jupiter("Jupiter", 69911000.0, 1.898e27, 7.785e8);
    Planete saturne("Saturne", 58232000.0, 5.683e26, 1.433e9);
    Planete uranus("Uranus", 25362000.0, 8.681e25, 2.877e9);
    Planete neptune("Neptune", 24622000.0, 1.024e26, 4.503e9);

    Planete systemeSolaire[NOMBRE_PLANETES] = {
        mercure,
        venus,
        terre,
        mars,
        jupiter,
        saturne,
        uranus,
        neptune
    };

    std::cout << "=== PLANÈTES DU SYSTÈME SOLAIRE ===" << std::endl
              << "===================================" << std::endl << std::endl;

    for (size_t i = 0; i < NOMBRE_PLANETES; i++) {
        systemeSolaire[i].afficher();
        std::cout << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}