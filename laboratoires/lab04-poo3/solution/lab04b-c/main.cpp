#include <iostream>
#include "TemperatureHistory.h"
#include "Menu.h"

int main() {
    Menu menu(true);
    menu.ajouterOption("Charger l'historique");
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
                    std::cout << "Historique chargé avec succès." << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Erreur lors du chargement de l'historique: " << e.what() << std::endl;
                }
                break;
            case 2: { // L'accolade crée une portée (scope) pour les variables locales
                DateTime datetimeMin, datetimeMax;
                size_t firstIndex, lastIndex;
                double sum = 0;

                std::cout << "Entrez la date et heure de début (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> datetimeMin;
                std::cout << "Entrez la date et heure de fin (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> datetimeMax;

                try {
                    firstIndex = history.findDatapoint(datetimeMin);
                    lastIndex = history.findDatapoint(datetimeMax);
                } catch (const std::exception& e) {
                    std::cout << "L'une des dates et heures saisies n'est pas présente dans l'historique." << std::endl;
                    break;
                }

                for (size_t i = firstIndex; i <= lastIndex; i++) {
                    sum += history[i].getTemperature();
                }
                double average = sum / (lastIndex - firstIndex + 1);
                std::cout << "La température moyenne entre " << datetimeMin << " et "
                          << datetimeMax << " est: " << average << std::endl;
                break;
            }
            case 3: {
                DateTime datetimeToDelete;
                std::cout << "Entrez la date et heure de la lecture à supprimer (format AAAA-MM-DDTHH:MM:SS): ";
                std::cin >> datetimeToDelete;
                try {
                    history.deleteDatapoint(datetimeToDelete);
                    std::cout << "Lecture supprimée avec succès." << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Aucune lecture trouvée pour la date et heure saisies." << std::endl;
                }
                break;
            }
        }
    } while (!menu.estQuitter(choix));

    return 0;
}