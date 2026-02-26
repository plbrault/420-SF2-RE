#include <iostream>
#include "TemperatureHistory.h"
#include "Menu.h"

int main() {
    Menu menu(true);
    menu.ajouterOption("Charger l'historique");
    menu.ajouterOption("Afficher la température à un moment précis");
    menu.ajouterOption("Calculer la température moyenne entre deux moments");
    menu.ajouterOption("Supprimer une lecture");

    TemperatureHistory history;

    int choix;
    do {
        std::cout << menu.obtenirChaine() << std::endl;
        choix = menu.demanderChoix();

        switch (choix) {
            case 1:
                try {
                    history.readFromFile("../temperatures.txt");
                    std::cout << "Historique chargé avec succès." << std::endl << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Erreur lors du chargement de l'historique: " << e.what() << std::endl;
                }
                break;
            case 2: { // Les accolades créent une portée (scope) pour les variables déclarées localement
                DateTime moment;
                try {
                    std::cout << "Entrez le moment (format AAAA-MM-DDTHH:MM:SS): ";
                    std::cin >> moment;
                } catch (const std::exception& e) {
                    std::cout << "Le moment saisi est invalide." << std::endl << std::endl;
                    break;
                }
                try {
                    const TemperatureDatapoint& datapoint = history[moment];
                    std::cout << "La température au moment " << moment << " était: " << datapoint.getTemperature()
                              << std::endl << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Aucune lecture trouvée pour la date et heure saisies." << std::endl << std::endl;
                }
                break;
            }
            case 3: {
                DateTime minMoment, maxMoment;
                size_t firstIndex, lastIndex;
                double sum = 0;

                std::cout << "Entrez le moment de début (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> minMoment;
                std::cout << "Entrez le moment de fin (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> maxMoment;

                if (minMoment >= maxMoment) {
                    std::cout << "Le moment de début doit être antérieur au moment de fin." << std::endl << std::endl;
                    break;
                }

                firstIndex = history.findDatapoint(minMoment);
                lastIndex = history.findDatapoint(maxMoment);
                if (firstIndex >= history.getSize() || lastIndex >= history.getSize()) {
                    std::cout << "L'une des dates et heures saisies n'est pas présente dans l'historique." << std::endl;
                    break;
                }

                for (size_t i = firstIndex; i <= lastIndex; i++) {
                    sum += history[i].getTemperature();
                }
                double average = sum / (lastIndex - firstIndex + 1);
                std::cout << "La température moyenne entre " << minMoment << " et "
                          << maxMoment << " est: " << average << std::endl << std::endl;
                break;
            }
            case 4: {
                DateTime momentToDelete;
                std::cout << "Entrez le moment de la lecture à supprimer (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> momentToDelete;
                try {
                    history.deleteDatapoint(momentToDelete);
                    std::cout << "Lecture supprimée avec succès." << std::endl << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Aucune lecture trouvée pour la date et heure saisies." << std::endl;
                }
                break;
            }
        }
    } while (!menu.estQuitter(choix));

    std::cout << "Au revoir!" << std::endl;

    return 0;
}