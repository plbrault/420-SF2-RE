#include <iostream>
#include "fonctions.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    locale::global(locale{ "" });

    int choix;
    string *taches = nullptr;
    bool *tacheCompletee = nullptr;
    int nombreTaches = 0;

    do {
        afficherMenu();
        choix = demanderChoix();

        cout << endl;
        switch (choix) {
            case 1:
                afficherListe(taches, tacheCompletee, nombreTaches);
                break;
            case 2:
                if (nombreTaches == 0) {
                    nombreTaches = 1;
                    taches = new string[1];
                    tacheCompletee = new bool[1] {false};
                } else {
                    string* tachesTemp = taches;
                    bool* tacheCompleteeTemp = tacheCompletee;

                    nombreTaches++;

                    taches = new string[nombreTaches];
                    tacheCompletee = new bool[nombreTaches] {false};

                    for (int i = 0; i < nombreTaches - 1; i++) {
                        taches[i] = tachesTemp[i];
                        tacheCompletee[i] = tacheCompleteeTemp[i];
                    }

                    delete[] tachesTemp;
                    delete[] tacheCompleteeTemp;
                }

                ajouterTache(taches, nombreTaches);
                break;
            case 3:
                marquerFaite(taches, tacheCompletee, nombreTaches);
                break;
            case 4:
                echangerTaches(taches, tacheCompletee, nombreTaches);
                break;
            default:
                cout << "Au revoir!" << endl;
        }
        cout << endl;
    } while (choix != 5);

    delete[] taches;
    delete[] tacheCompletee;
}
