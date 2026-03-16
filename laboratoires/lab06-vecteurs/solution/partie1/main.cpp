#include <iostream>
#include "Menu.h"
#include "TableauPeriodique.h"

using namespace std;

int main() {
    int choix;
    string recherche;
    const Element* resultatRecherche;
    Menu menu("Tableau périodique", "Choisir une option:", true);
    TableauPeriodique tableauPeriodique;

    menu.ajouterOption("Charger le tableau périodique");
    menu.ajouterOption("Afficher les elements");
    menu.ajouterOption("Trier les éléments par nom");
    menu.ajouterOption("Trier les éléments par numéro atomique");
    menu.ajouterOption("Rechercher un élément");

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
                case 3:
                    tableauPeriodique.trierParNom();
                    break;
                case 4:
                    tableauPeriodique.trierParNumeroAtomique();
                    break;
                case 5:
                    cout << "Entrez le nom de l'élément recherché: ";
                    cin >> recherche;
                    resultatRecherche = tableauPeriodique.getElementParNom(recherche);
                    if (resultatRecherche != nullptr) {
                        cout << *resultatRecherche << endl;
                    } else {
                        cout << "Élément non trouvé." << endl;
                    }
                    break;
            }
        }
    } while (choix != menu.valeurMaximale());

    cout << "Au revoir!" << endl;
}