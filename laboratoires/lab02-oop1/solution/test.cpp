#include <iostream>
#include <stdint.h>

#include "menu.h"

int main() {

    Menu menuPrincipal("Menu principal", "Votre choix ?", true);

    menuPrincipal.ajouterOption("Afficher la liste");
    menuPrincipal.ajouterOption("Ajouter une tâche");
    menuPrincipal.ajouterOption("Marquer une tâche comme faite");
    menuPrincipal.ajouterOption("Échanger deux tâches");
    menuPrincipal.ajouterOption("Sauvegarder la liste de tâches");
    menuPrincipal.ajouterOption("Charger la liste de tâches");

    std::cout << menuPrincipal.obtenirChaine();
    int choix;
    std::cin >> choix;
    if (menuPrincipal.validerSelection(choix)) {
        std::cout << "Choix valide" << std::endl;
    }

    // std::string prenom("Andrew");
    // std::string nom("Knolton");
    // Personne quelquun(prenom, nom);

    // std::string descriptionTache[] = {
    //     "Faire le labo 1", 
    //     "Faire le labo 2", 
    //     "Faire le labo 3", 
    //     "Faire le labo 4", 
    //     "Faire le labo 5", 
    //     "Faire le labo 6", 
    //     "Faire le labo 7", 
    //     "Faire le labo 8", 
    //     "Faire le labo 9", 
    //     "Faire le labo 10", 
        
    //     "Laver la vaiselle"
    // };
    // int taille = sizeof(descriptionTache) / sizeof(descriptionTache[0]);

    // for (uint8_t i = 0; i < taille; i++) {
    //     quelquun.ajouterTache(descriptionTache[i]);
    // }

    // quelquun.supprimerTache(3);

    // quelquun.completeTache(1);
    // quelquun.completeTache(2);
    // quelquun.completeTache(3);
    // quelquun.completeTache(5);
    // quelquun.completeTache(8);
    // quelquun.completeTache(13);

    // Tache *uneTache = quelquun.obtenirTache(1);

    // std::cout << quelquun.obtenirChaine();

    // std::cout << std::endl << "Nous avons sélectionné la première tâches : " << uneTache->obtenirChaine(1) << std::endl;

    return 0;
}
