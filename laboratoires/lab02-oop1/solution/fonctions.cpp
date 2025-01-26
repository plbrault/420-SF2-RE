#include <iostream>
#include <fstream>
#include "fonctions.h"

Menu construireMenuPrincipal(void) {
    Menu menuPrincipal("Menu principal", "Votre choix ?", true);

    menuPrincipal.ajouterOption("Afficher la liste");
    menuPrincipal.ajouterOption("Ajouter une tâche");
    menuPrincipal.ajouterOption("Marquer une tâche comme faite");
    menuPrincipal.ajouterOption("Échanger deux tâches");
    menuPrincipal.ajouterOption("Supprimer une tâche");;
    menuPrincipal.ajouterOption("Sauvegarder les tâches");;
    menuPrincipal.ajouterOption("Charger les tâches");

    return menuPrincipal;
}

void afficherMenu(Menu &menu) {
    std::cout << menu.obtenirChaine();
}

int demanderChoix(Menu &menu) {
    int choix;

    bool valide = false;

    do {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        }
        std::cin >> choix;
        valide = menu.validerSelection(choix);
        if (!valide) {
            std::cout << "Le choix doit être un chiffre entre 1 et " 
                        << menu.valeurMaximale() 
                        << "." << std::endl;
        }
    } while (!valide);

    return choix;
}

void afficherListe(Personne &toi) {
    if(toi.obtenirNombreTache() == 0) {
        std::cout << "La liste est vide." << std::endl;
    } else {
        std::cout << toi.obtenirChaine() << std::endl;
    }
}

void ajouterTache(Personne &toi) {
    std::string tache;

    if (toi.obtenirNombreTache() == 100) {
        std::cout << "La liste est pleine." << std::endl;
    } else {
        std::cout << "Entrez la tâche à ajouter : ";
        std::cin.ignore();
        std::getline(std::cin, tache);

        Tache t(tache, false);
        toi.ajouterTache(t);
    }
}

size_t demanderNumeroTache(std::string etiquette, Personne &toi) {
    size_t numeroTache;

    bool valide = false;

    do {
        std::cout << etiquette;
        std::cin >> numeroTache;
        valide = numeroTache >= 1 && numeroTache <= toi.obtenirNombreTache();
        if (!valide) {
            std::cout << "Le numéro entré est invalide." << std::endl;
        }
    } while (!valide);

    return numeroTache;
}


void marquerFaite(Personne &toi) {
    std::cout << std::endl;

    afficherListe(toi);

    if (toi.obtenirNombreTache() > 0) {
        int numeroTache = demanderNumeroTache("Entrez le numéro de la tâche à marquer comme faite : ", toi);
        toi.obtenirTache(numeroTache)->marquerFait();
    }
}

void echangerTaches(Personne &toi) {
    int numeroTache1, numeroTache2;
    std::string tacheTemp;

    if (toi.obtenirNombreTache() >= 2) {
        afficherListe(toi);
        std::cout << std::endl;

        numeroTache1 = demanderNumeroTache("Entrez le numéro de la première tâche à échanger : ", toi);
        numeroTache2 = demanderNumeroTache("Entrez le numéro de la deuxième tâche à échanger : ", toi);

        toi.echangerTache(numeroTache1, numeroTache2);

        std::cout << "Échange complété." << std::endl;
    } else {
        std::cout << "La liste comporte moins de deux tâches." << std::endl;
    }
}

void supprimerTache(Personne &toi) {
    afficherListe(toi);

    if (toi.obtenirNombreTache() > 0) {
        int numeroTache = demanderNumeroTache("Entrez le numéro de la tâche à supprimer : ", toi);

        toi.supprimerTache(numeroTache);
    }
}

void sauvegarderPersonne(Personne &toi) {
    std::ofstream fichier("taches.txt");
    if (!fichier.is_open()) {
        std::cout << "Le fichier taches.txt n'a pas pu être ouvert." << std::endl;
        return;
    }

    for (size_t i = 0; i < toi.obtenirNombreTache(); i++) {
        fichier << toi.obtenirTache(i + 1)->obtenirDescription() << std::endl;
        fichier << toi.obtenirTache(i + 1)->estFait() << std::endl;
    };

    fichier.close();

    std::cout << "La liste de tâches a été sauvegardée." << std::endl;
}

void chargerPersonne(Personne &toi) {
    std::ifstream fichier("taches.txt");
    if (!fichier.is_open()) {
        std::cout << "Le fichier taches.txt n'a pas pu être ouvert." << std::endl;
        return;
    }

    std::string description;
    std::string estFaitStr;
    bool estFait;
    while (std::getline(fichier, description)) {
        std::getline(fichier, estFaitStr);
        estFait = estFaitStr == "1";
        toi.ajouterTache(Tache(description, estFait));
    }

    std::cout << "La liste de tâches a été chargée." << std::endl;
}
