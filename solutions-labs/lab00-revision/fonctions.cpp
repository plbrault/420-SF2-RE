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

void marquerFaite(std::string taches[], bool tacheCompletee[], int nombreTaches) {
    int numeroTache;

    afficherListe(taches, tacheCompletee, nombreTaches);

    if (nombreTaches > 0) {
        do {
            cout << "Entrez le numéro de la tâche à marquer comme faite (0 pour annuler) : ";
            cin >> numeroTache;
            if (numeroTache >= 1 && numeroTache <= nombreTaches) {
                tacheCompletee[numeroTache - 1] = true;
            } else if (numeroTache != 0) {
                cout << "Le numéro de la tâche est invalide." << endl;
            }
        } while (numeroTache < 0 || numeroTache > nombreTaches);
    } else {
        cout << "La liste est vide." << endl;
    }
}

