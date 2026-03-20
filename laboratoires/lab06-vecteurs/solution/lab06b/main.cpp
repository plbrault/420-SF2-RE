#include <iostream>
#include <fstream>
#include "Menu.h"
#include "TableauPeriodique.h"

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

    TableauPeriodique tableauPeriodique;

    int option;
    do {
        std::cout << menu;
        option = menu.demanderChoix();

        switch (option) {
        case 1:
            try {
                tableauPeriodique.charger("../elements.csv");
                std::cout << "Tableau périodique chargé avec succès." << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Erreur lors du chargement du tableau périodique: " << e.what() << std::endl;
            }
            break;
        case 2:
            tableauPeriodique.afficher(std::cout);
            break;
        case 3:
            tableauPeriodique.trierParNom();
            std::cout << "Le tableau périodique est maintenant trié par nom." << std::endl;
            break;
        case 4:
            tableauPeriodique.trierParNumeroAtomique();
            std::cout << "Le tableau périodique est maintenant trié par numéro atomique." << std::endl;
            break;
        case 5:
            try {
                std::string symbole;
                std::cout << "Entrez le symbole de l'élément: ";
                std::cin >> symbole;
                const Element& element = tableauPeriodique.trouverElementParSymbole(symbole);
                std::cout << "Élément trouvé: " << element.getNom() << " (Numéro atomique: " << element.getNumeroAtomique() << ", Masse atomique: " << element.getMasseAtomique() << ")" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erreur lors de la recherche de l'élément: " << e.what() << std::endl;
            }
            break;
        case 6:
            try {
                std::string nom;
                std::cout << "Entrez le nom de l'élément: ";
                std::cin >> nom;
                const Element& element = tableauPeriodique.trouverElementParNom(nom);
                std::cout << "Élément trouvé: " << element.getSymbole() << " (Numéro atomique: " << element.getNumeroAtomique() << ", Masse atomique: " << element.getMasseAtomique() << ")" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erreur lors de la recherche de l'élément: " << e.what() << std::endl;
            }
        }

        std::cout << std::endl;
    } while (!menu.estQuitter(option));

    return 0;
}