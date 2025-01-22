#include <iostream>

#include "fonctions.h"
#include "task.h"

int main () {
    std::locale::global(std::locale{ "" });

    Task maTache;
    maTache._description = "Compléter le laboratoire 2";
    maTache._fait = false;

    std::cout << maTache.obtenirChaine(1) << std::endl;

    return 0;
}


/*
#include <iostream>
#include <stdint.h>
#include <string>

#include "fonctions.h"
#include "personne.h"


int main() {
    std::locale::global(std::locale{ "" });

    std::string prenom;
    std::cout << "Quel est ton prénom ? ";
    std::cin >> prenom;

    std::string nom;
    std::cout << "Quel est ton nom ? ";
    std::cin >> nom;

    Personne toi(prenom, nom);
    std::cout << "Bonjour a toi, " << toi.obtenirNomComplet() << std::endl;

    Menu menuPrincipale = construireMenuPrincipal();

    int choix;

    do {
        afficherMenu(menuPrincipale);
        choix = demanderChoix(menuPrincipale);

        std::cout << std::endl;
        switch (choix) {
        case 1: 
            afficherListe(toi);
            break;
        
        case 2: 
            ajouterTache(toi);
            break;
        
        case 3: 
            marquerFaite(toi);
            break;
        
        case 4: 
            echangerTaches(toi);
            break;
        
        case 5: 
            supprimerTache(toi);
            break;

        case 6:
            std::cout << "Au revoir!" << std::endl;
            break;
        
        default: 
            std::cout << "Une erreur inconnue c'est produite. Veuillez recommencer!" << std::endl;
        }
    } while(choix != menuPrincipale.valeurMaximale());

    return 0;

}
*/