#include <iostream>
#include <fstream>
#include "fonctions.h"

using namespace std;

void afficherMenu() {
    cout << "Liste de tâches" << endl
        << "================================" << endl
        << "1. Afficher la liste" << endl
        << "2. Ajouter une tâche" << endl
        << "3. Marquer une tâche comme faite" << endl
        << "4. Échanger deux tâches" << endl
        << "5. Supprimer une tâche" << endl
        << "6. Sauvegarder les tâches" << endl
        << "7. Charger les tâches" << endl
        << "8. Quitter" << endl;
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

void ajouterTache(string taches[], int nombreTaches) {
    string tache;

    cout << "Entrez la tâche à ajouter : ";
    cin.ignore();
    getline(cin, tache);

    taches[nombreTaches - 1] = tache;
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

void supprimerTache(std::string taches[], bool tacheCompletee[], int &nombreTaches) {
    int numeroTache;

    afficherListe(taches, tacheCompletee, nombreTaches);

    if (nombreTaches > 0) {
        numeroTache = demanderNumeroTache(
            "Entrez le numéro de la tâche à supprimer :",
            nombreTaches
        );

        nombreTaches--;
        for (int i = numeroTache - 1; i < nombreTaches; i++) {
            taches[i] = taches[i + 1];
            tacheCompletee[i] = tacheCompletee[i + 1];
        }

        cout << "Suppression complétée." << endl;
    }
}

void sauvegarderListe(std::string taches[], bool tacheCompletee[], int nombreTaches) {
    ofstream fichier("taches.txt");
    if (!fichier.is_open()) {
        cout << "Le fichier taches.txt n'a pas pu être ouvert." << endl;
        return;
    }

    for (int i = 0; i < nombreTaches; i++) {
        fichier << taches[i] << endl;
        fichier << tacheCompletee[i] << endl;
    };

    fichier.close();

    cout << "La liste de tâches a été sauvegardée." << endl;
}

void chargerListe(std::string taches[], bool tacheCompletee[], int& nombreTaches) {
    ifstream fichier("taches.txt");
    if (!fichier.is_open()) {
        cout << "Le fichier taches.txt n'a pas pu être ouvert." << endl;
        return;
    }

    nombreTaches = 0;

    string ligne;
    while (getline(fichier, ligne)) {
        taches[nombreTaches] = ligne;
        getline(fichier, ligne);
        tacheCompletee[nombreTaches] = ligne == "1";
        nombreTaches++;
    }

    cout << "La liste de tâches a été chargée." << endl;
}
