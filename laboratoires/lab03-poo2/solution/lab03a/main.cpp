#include <iostream>
#include "Planete.h"
#include "SystemePlanetaire.h"

const size_t NOMBRE_PLANETES = 8;

int main() {
    SystemePlanetaire systemeSolaire;
    systemeSolaire.setNom("Système solaire");

    systemeSolaire.ajouterPlanete(Planete("Mercure", 2439000, 3.301e23, 5.79e7));
    systemeSolaire.ajouterPlanete(Planete("Vénus", 6052000, 4.867e24, 1.082e8));
    systemeSolaire.ajouterPlanete(Planete("Terre", 6371000, 5.972e24, 1.496e8));
    systemeSolaire.ajouterPlanete(Planete("Mars", 3390000, 6.39e23, 2.279e8));
    systemeSolaire.ajouterPlanete(Planete("Jupiter", 69911000, 1.898e27, 7.785e8));
    systemeSolaire.ajouterPlanete(Planete("Saturne", 58232000, 5.683e26, 1.433e9));
    systemeSolaire.ajouterPlanete(Planete("Uranus", 25362000, 8.681e25, 2.877e9));
    systemeSolaire.ajouterPlanete(Planete("Neptune", 24622000, 1.024e26, 4.503e9));

    systemeSolaire.afficher();

    // Créer une copie du système solaire en allocation statique
    SystemePlanetaire copie1(systemeSolaire);

    // Créer une deuxième copie du système solaire en allocation dynamique
    SystemePlanetaire* copie2 = new SystemePlanetaire(copie1);

    // Désallouer la deuxième copie
    // Si le constructeur de copie est implémenté correctement, les autres
    // copies ne seront pas affectées
    delete copie2;

    // Renommer la copie
    copie1.setNom("Système solaire (copie)");

    // Afficher la copie
    copie1.afficher();

    std::cout << "Affichage de la planète à l'indice 2:" << std::endl;
    systemeSolaire.getPlanete(2)->afficher();

    std::cout << "Affichage de la planète Jupiter:" << std::endl;
    systemeSolaire.getPlanete("Jupiter")->afficher();

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}