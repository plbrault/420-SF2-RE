#include <iostream>
#include "fonctions.h"

using namespace std;

void afficherMenu() {
    cout << "Liste de tâches" << endl
        << "================================" << endl
        << "1. Afficher la liste" << endl
        << "2. Ajouter une tâche" << endl
        << "3. Marquer une tâche comme faite" << endl
        << "4. Échanger deux tâches" << endl
        << "5. Quitter" << endl;
}

int demanderChoix() {
    int choix;

    do {
        cout << "Entrez votre choix : ";
        cin >> choix;

        if (choix < 1 || choix > 5) {
            cout << "Le choix doit être un chiffre entre 1 et 5." << endl;
        }
    } while (choix < 1 || choix > 5);

    return choix;
}
