#include <iostream>
#include "fonctions.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    locale::global(locale{ "" });

    int choix;

    do {
        afficherMenu();
        choix = demanderChoix();

        switch (choix) {
            case 1:
                cout << "Afficher la liste" << endl;
                break;
            case 2:
                cout << "Ajouter une tâche" << endl;
                break;
            case 3:
                cout << "Marquer une tâche comme faite" << endl;
                break;
            case 4:
                cout << "Échanger deux tâches" << endl;
                break;
        }
    } while (choix != 5);

    cout << "Au revoir!" << endl;
}
