#include <iostream>
#include "Menu.h"
#include "TableauPeriodique.h"

using namespace std;

int main() {
    int choix;
    Menu menu("Menu", "Choisir une option:", true);
    TableauPeriodique tableauPeriodique;

    menu.ajouterOption("Charger le tableau périodique");
    menu.ajouterOption("Afficher les elements du tableau périodique");

    do {
        cout << menu.obtenirChaine();
        cin >> choix;
        if (!menu.validerSelection(choix)) {
            cout << "Option invalide." << endl;
        } else {
            switch (choix) {
                case 1:
                    tableauPeriodique.charger("elements.csv");
                    break;
                case 2:
                    cout << tableauPeriodique;
                    break;
            }
        }
    } while (choix != menu.valeurMaximale());

    cout << "Au revoir!" << endl;
}