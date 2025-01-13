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

int demanderChoix(int max) {
    int choix;

    do {
        cout << "Entrez votre choix : ";
        cin >> choix;

        if (choix < 1 || choix > max) {
            cout << "Le choix doit être un chiffre entre 1 et " << max << "." << endl;
        }
    } while (choix < 1 || choix > max);

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

int demanderNumeroTache(string texte, int nombreTaches) {
    int numeroTache;

    do {
        cout << texte;
        cin >> numeroTache;
        if (numeroTache < 1 || numeroTache > nombreTaches) {
            cout << "Le numéro entré est invalide." << endl;
        }
    } while (numeroTache < 1 || numeroTache > nombreTaches);

    return numeroTache;
}


void marquerFaite(string taches[], bool tacheCompletee[], int nombreTaches) {
    int numeroTache;

    afficherListe(taches, tacheCompletee, nombreTaches);

    if (nombreTaches > 0) {
        numeroTache = demanderNumeroTache(
    "Entrez le numéro de la tâche à marquer comme faite : ",
            nombreTaches
        );
        tacheCompletee[numeroTache - 1] = true;
    }
}

void echangerTaches(string taches[], bool tacheCompletee[], int nombreTaches) {
    int numeroTache;

    int numeroTache1, numeroTache2;
    string tacheTemp;
    bool completeeTemp;

    if (nombreTaches >= 2) {
        afficherListe(taches, tacheCompletee, nombreTaches);

        numeroTache1 = demanderNumeroTache(
            "Entrez le numéro de la première tâche à échanger : ",
            nombreTaches
        );
        numeroTache2 = demanderNumeroTache(
            "Entrez le numéro de la deuxième tâche à échanger : ",
            nombreTaches
        );

        tacheTemp = taches[numeroTache1 - 1];
        taches[numeroTache1 - 1] = taches[numeroTache2 - 1];
        taches[numeroTache2 - 1] = tacheTemp;

        completeeTemp = tacheCompletee[numeroTache1 - 1];
        tacheCompletee[numeroTache1 - 1] = tacheCompletee[numeroTache2 - 1];
        tacheCompletee[numeroTache2 - 1] = completeeTemp;

        cout << "Échange complété." << endl;
    } else {
        cout << "La liste comporte moins de deux tâches." << endl;
    }
}
