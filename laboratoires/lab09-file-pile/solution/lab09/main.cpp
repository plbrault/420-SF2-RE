#include <iostream>
#include <set>
#include <thread>
#include <chrono>
#include <random>
#include <functional>
#include "fonctions.h"
#include "GlissadeEau.h"

const unsigned long DUREE_JOURNEE = 28800;
const int VITESSE_MAX = 1000;

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
    int facteurVitesse = 1;

    while (glissade.getTemps().getTotalSeconds() < DUREE_JOURNEE) {
        Touche touche = lireTouche();
        if (touche == Touche::QUITTER) {
            break;
        }
        if (touche == Touche::DROITE && facteurVitesse < VITESSE_MAX) {
            facteurVitesse *= 10;
        }
        if (touche == Touche::GAUCHE && facteurVitesse > 1) {
            facteurVitesse /= 10;
        }

        effacerEcran();
        std::cout << glissade;
        std::cout << "Vitesse: " << facteurVitesse << "x" << std::endl;
        std::cout << "Fleche droite: accelerer | Fleche gauche: ralentir | Autre touche: quitter" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / facteurVitesse));

        glissade.mettreAJour();

        double lambda = calculerTauxArrivee(glissade.getTemps().getTotalSeconds());
        int nombreNouveauxVisiteurs = 0;
        if (lambda > 0.0) {
            std::poisson_distribution<int> dist(lambda);
            nombreNouveauxVisiteurs = dist(gen);
        }
        if (glissade.getTemps().getTotalSeconds() < 60) {
            std::bernoulli_distribution distVague(0.15);
            if (distVague(gen)) {
                std::uniform_int_distribution<int> distTaille(1, 3);
                nombreNouveauxVisiteurs += distTaille(gen);
            }
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