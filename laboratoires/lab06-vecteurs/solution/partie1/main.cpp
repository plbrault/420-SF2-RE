#include <iostream>
#include "fonctions.h"
#include "Menu.h"

using namespace std;

int main() {
    int choix;
    Menu menu("Menu", "Choisir une option:", true);
    vector<Element> tableauPeriodique;

    menu.ajouterOption("Charger le tableau périodique");
    menu.ajouterOption("Afficher le tableau périodique");

    do {
        cout << menu.obtenirChaine();
        cin >> choix;
        if (!menu.validerSelection(choix)) {
            cout << "Option invalide." << endl;
        } else {
            switch (choix) {
                case 1:
                    tableauPeriodique = parseElements("elements.csv");
                    break;
                case 2:
                    for (Element element : tableauPeriodique) {
                        cout << element << endl;
                    }
                    break;
            }
        }
    } while (choix != menu.valeurMaximale());

    cout << "Au revoir!" << endl;
}