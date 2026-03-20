#include <iostream>
#include <fstream>
#include "Menu.h"

#define COL_WIDTH 16

int main() {
    Menu menu(true);
    menu.ajouterOption("Charger le tableau périodique");
    menu.ajouterOption("Afficher le tableau périodique");
    menu.ajouterOption("Trier le tableau périodique par nom");
    menu.ajouterOption("Trier le tableau périodique par numéro atomique");
    menu.ajouterOption("Trouver un élément par son symbole");
    menu.ajouterOption("Trouver un élément par son nom");
    menu.ajouterOption("Trouver un élément par son numéro atomique");

    std::cout << menu;

    return 0;
}