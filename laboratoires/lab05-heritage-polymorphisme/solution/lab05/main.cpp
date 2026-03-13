#include <iostream>
#include "TemperatureHistory.h"
#include "Menu.h"

int main() {
    Duration* temporalUnits[2]; // Attention: ceci est un tableau de 2 pointeurs de Duration et non pointeur sur un tableau de 2 Duration!

    temporalUnits[0] = new Duration(0);
    temporalUnits[1] = new Time(0, 0, 0);

    for (size_t i = 0; i < 2; i++) {
        Duration* unit = temporalUnits[i];
        try {
            unit->setTotalSeconds(25 * 60 * 60);
            std::cout << "setTotalSeconds(25 * 60 * 60) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "setTotalSeconds(25 * 60 * 60) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            unit->setHours(25);
            std::cout << "setHours(25) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "setHours(25) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            unit->addHours(25);
            std::cout << "addHours(25) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "addHours(25) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            unit->addMinutes(25 * 60);
            std::cout << "addHours(25 * 60) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "addHours(25 * 60) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            unit->addSeconds(25 * 60 * 60);
            std::cout << "addHours(25 * 60 * 60) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "addHours(25 * 60 * 60) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            *unit += Duration(25, 0, 0);
            std::cout << "operator+=(Duration(25, 0, 0)) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "operator+=(Duration(25, 0, 0)) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            *unit -= Duration(1, 0, 0);
            std::cout << "operator-=(Duration(1, 0, 0)) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "operator-=(Duration(1, 0, 0)) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        try {
            *unit *= 2;
            std::cout << "operator*=(2) a réussi pour l'unité temporelle " << i << std::endl;
        } catch (const std::exception& e) {
            std::cout << "operator*=(2) a échoué pour l'unité temporelle " << i << ": " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }

    //
    // Menu menu(true);
    // menu.ajouterOption("Charger l'historique");
    // menu.ajouterOption("Afficher la température à un moment précis");
    // menu.ajouterOption("Calculer la température moyenne entre deux moments");
    // menu.ajouterOption("Supprimer une lecture");
    //
    // TemperatureHistory history;
    //
    // int choix;
    // do {
    //     std::cout << menu.obtenirChaine() << std::endl;
    //     choix = menu.demanderChoix();
    //
    //     switch (choix) {
    //         case 1:
    //             try {
    //                 history.readFromFile("../temperatures.txt");
    //                 std::cout << "Historique chargé avec succès." << std::endl << std::endl;
    //             } catch (const std::exception& e) {
    //                 std::cout << "Erreur lors du chargement de l'historique: " << e.what() << std::endl;
    //             }
    //             break;
    //         case 2: { // Les accolades créent une portée (scope) pour les variables déclarées localement
    //             DateTime moment;
    //             try {
    //                 std::cout << "Entrez le moment (format AAAA-MM-DDTHH:MM:SS): ";
    //                 std::cin >> moment;
    //             } catch (const std::exception& e) {
    //                 std::cout << "Le moment saisi est invalide." << std::endl << std::endl;
    //                 break;
    //             }
    //             try {
    //                 const TemperatureDatapoint& datapoint = history[moment];
    //                 std::cout << "La température au moment " << moment << " était: " << datapoint.getTemperature()
    //                           << std::endl << std::endl;
    //             } catch (const std::exception& e) {
    //                 std::cout << "Aucune lecture trouvée pour la date et heure saisies." << std::endl << std::endl;
    //             }
    //             break;
    //         }
    //         case 3: {
    //             DateTime minMoment, maxMoment;
    //             size_t firstIndex, lastIndex;
    //             double sum = 0;
    //
    //             std::cout << "Entrez le moment de début (format AAAA-MM-DDTHH:MM:SS): ";
    //             std::cin >> minMoment;
    //             std::cout << "Entrez le moment de fin (format AAAA-MM-DDTHH:MM:SS): ";
    //             std::cin >> maxMoment;
    //
    //             if (minMoment >= maxMoment) {
    //                 std::cout << "Le moment de début doit être antérieur au moment de fin." << std::endl << std::endl;
    //                 break;
    //             }
    //
    //             firstIndex = history.findDatapoint(minMoment);
    //             lastIndex = history.findDatapoint(maxMoment);
    //             if (firstIndex >= history.getSize() || lastIndex >= history.getSize()) {
    //                 std::cout << "L'une des dates et heures saisies n'est pas présente dans l'historique." << std::endl;
    //                 break;
    //             }
    //
    //             for (size_t i = firstIndex; i <= lastIndex; i++) {
    //                 sum += history[i].getTemperature();
    //             }
    //             double average = sum / (lastIndex - firstIndex + 1);
    //             std::cout << "La température moyenne entre " << minMoment << " et "
    //                       << maxMoment << " est: " << average << std::endl << std::endl;
    //             break;
    //         }
    //         case 4: {
    //             DateTime momentToDelete;
    //             std::cout << "Entrez le moment de la lecture à supprimer (format AAAA-MM-DDTHH:MM:SS): ";
    //             std::cin >> momentToDelete;
    //             try {
    //                 history.deleteDatapoint(momentToDelete);
    //                 std::cout << "Lecture supprimée avec succès." << std::endl << std::endl;
    //             } catch (const std::exception& e) {
    //                 std::cout << "Aucune lecture trouvée pour la date et heure saisies." << std::endl;
    //             }
    //             break;
    //         }
    //     }
    // } while (!menu.estQuitter(choix));
    //
    // std::cout << "Au revoir!" << std::endl;

    return 0;
}