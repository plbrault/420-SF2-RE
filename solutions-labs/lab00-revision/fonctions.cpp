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

void afficherListe(string taches[], bool tacheCompletee[], int nombreTaches) {
    if (nombreTaches == 0) {
        cout << "La liste est vide." << endl;
    } else {
        for (int i = 0; i < nombreTaches; i++) {
            cout << i + 1 << ". ";
            if (tacheCompletee[i]) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << taches[i] << endl;
        }
    }
}

void ajouterTache(string taches[], int& nombreTaches) {
    string tache;

    if (nombreTaches == 100) {
        cout << "La liste est pleine." << endl;
    } else {
        cout << "Entrez la tâche à ajouter : ";
        cin.ignore();
        getline(cin, tache);

        taches[nombreTaches] = tache;
        nombreTaches++;
    }
}
