#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
    locale::global(locale{ "" });

    int choix;
    string taches[100];
    bool tacheCompletee[100] = {false};
    int nombreTaches = 0;

    do {
        afficherMenu();
        choix = demanderChoix(7);

        cout << endl;
        switch (choix) {
            case 1:
                afficherListe(taches, tacheCompletee, nombreTaches);
                break;
            case 2:
                ajouterTache(taches, nombreTaches);
                break;
            case 3:
                marquerFaite(taches, tacheCompletee, nombreTaches);
                break;
            case 4:
                echangerTaches(taches, tacheCompletee, nombreTaches);
                break;
            case 5:
                sauvegarderListe(taches, tacheCompletee, nombreTaches);
                break;
            case 6:
                chargerListe(taches, tacheCompletee, nombreTaches);
                break;
            default:
                cout << "Au revoir!" << endl;
        }
        cout << endl;
    } while (choix != 7);
}
