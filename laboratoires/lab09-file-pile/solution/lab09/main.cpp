#include <iostream>
#include <set>
#include <thread>
#include <chrono>
#include <random>
#include <functional>
#include "fonctions.h"
#include "GlissadeEau.h"

const unsigned long DUREE_JOURNEE = 28800;

int main() {
    std::random_device rd;
    std::mt19937 gen(
        std::hash<unsigned long>{}(
            std::chrono::system_clock::now().time_since_epoch().count()
            ^ rd()
        )
    );

    GlissadeEau glissade;
    std::set<Visiteur*> visiteurs;

    while (!touchePressee() && glissade.getTemps().getTotalSeconds() < DUREE_JOURNEE) {
        effacerEcran();
        std::cout << glissade;
        std::cout << "Appuyez sur n'importe quelle touche pour quitter." << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        glissade.mettreAJour();

        double lambda = calculerTauxArrivee(glissade.getTemps().getTotalSeconds());
        int nombreNouveauxVisiteurs = 0;
        if (lambda > 0.0) {
            std::poisson_distribution<int> dist(lambda);
            nombreNouveauxVisiteurs = dist(gen);
        }
        for (int i = 0; i < nombreNouveauxVisiteurs; i++) {
            Visiteur* nouveauVisiteur = new Visiteur();
            visiteurs.insert(nouveauVisiteur);
            glissade.ajouterVisiteur(nouveauVisiteur);
        }

        Visiteur* visiteurSorti = glissade.traiterSortie();
        if (visiteurSorti != nullptr) {
            visiteurs.erase(visiteurSorti);
            delete visiteurSorti;
        }
    }

    std::cout << std::endl << "La journee est terminee!" << std::endl;

    for (Visiteur* visiteur : visiteurs) {
        delete visiteur;
    }

    return 0;
}