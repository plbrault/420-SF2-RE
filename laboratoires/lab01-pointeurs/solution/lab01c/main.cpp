#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
    locale::global(locale{ "" });

    int choix;
    int tailleTableau = 10;
    string *taches = new string[tailleTableau];
    bool *tacheCompletee = new bool[tailleTableau];
    int nombreTaches = 0;

    do {
        afficherMenu();
        choix = demanderChoix(8);

        cout << endl;
        switch (choix) {
            case 1:
                afficherListe(taches, tacheCompletee, nombreTaches);
                break;
            case 2:
                nombreTaches++;

                if (nombreTaches > tailleTableau) {
                    tailleTableau *= 2;

                    string* tachesTemp = taches;
                    bool* tacheCompleteeTemp = tacheCompletee;

                    taches = new string[tailleTableau];
                    tacheCompletee = new bool[tailleTableau] {false};

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
            case 5:
                supprimerTache(taches, tacheCompletee, nombreTaches);
                break;
            case 6:
                sauvegarderListe(taches, tacheCompletee, nombreTaches);
                break;
            case 7:
                chargerListe(taches, tacheCompletee, nombreTaches);
                break;
            default:
                cout << "Au revoir!" << endl;
        }
        cout << endl;
    } while (choix != 6);

    delete[] taches;
    delete[] tacheCompletee;
}
