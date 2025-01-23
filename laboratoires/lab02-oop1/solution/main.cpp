#include <iostream>

#include "tache.h"

#define TACHE_QUANTITE_DEPART 10

int main() {
    std::locale::global(std::locale{ "" });

    size_t mySize = 3;

    int taille = TACHE_QUANTITE_DEPART;
    int quantite = 0;
    Tache *taches = new Tache[taille];

    bool termine = false;
    std::string ligne;

    char selection;

    std::cout << "Saisissez vos tâches" << std::endl;
    do {
        std::cout << "Tâche numero " << (quantite + 1) << " : ";

        std::getline(std::cin, ligne);
        taches[quantite].changerDescription(ligne);

        quantite++;

        if (quantite == taille) {
            taille *= 2;
            Tache* tampon = new Tache[taille];
            for (int i = 0; i < quantite; i++) {
                tampon[i] = taches[i];
            }
            taches = tampon;
            tampon = nullptr;
        }

        std::cout << "Avez-vous d'autres tâches ? [O|N] ";
        std::cin >> selection;
        termine = !(toupper(selection) == 'O');
        std::cin.ignore();
    } while(!termine);

    for (int i = 0; i < quantite; i++) {
        std::cout << "Avez-vous complétez la tâches suivantes : " << std::endl;
        std::cout << "\"    " << taches[i].obtenirDescription() << "\"" << std::endl;
        std::cout << " [O|N] : ";
        std::cin >> selection;
        if (toupper(selection) == 'O') {
            taches[i].marquerFait();
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Votre liste de tâches actuelles" << std::endl;
    for (int i = 0; i < quantite; i++) {
        std::cout << taches[i].obtenirChaine(i + 1) << std::endl;
    }

    delete [] taches;

    return 0;
}
