#include <iostream>
#include "fonctions.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    locale::global(locale{ "" });

    int choix;
    string taches[100];
    int nombreTaches = 0;

    do {
        afficherMenu();
        choix = demanderChoix();

        cout << endl;
        switch (choix) {
            case 1:
                afficherListe(taches, nombreTaches);
                break;
            case 2:
                ajouterTache(taches, nombreTaches);
                break;
            case 3:
                cout << "Marquer une tâche comme faite" << endl;
                break;
            case 4:
                cout << "Échanger deux tâches" << endl;
                break;
        }
        cout << endl;
    } while (choix != 5);

    cout << "Au revoir!" << endl;
}
