//
// Created by plbrault on 2026-04-12.
//

#include "Simulateur.h"
#include "fonctions.h"
#include <random>
#include <functional>
#include <chrono>
#include <thread>

const unsigned long DUREE_JOURNEE = 28800;
const int VITESSE_MAX = 1000;
const unsigned long TEMPS_PIC_MATIN = 7200;
const unsigned long TEMPS_PIC_APRES_MIDI = 21000;
const double SIGMA_MATIN = 2700.0;
const double SIGMA_APRES_MIDI = 2700.0;
const double TAUX_PIC_MATIN = 0.34;
const double TAUX_PIC_APRES_MIDI = 0.35;

Simulateur::Simulateur() {
}

Simulateur::~Simulateur() {
    for (Visiteur* visiteur : _visiteurs) {
        delete visiteur;
    }
}

double Simulateur::calculerTauxArrivee(unsigned long temps) {
    double t = static_cast<double>(temps);
    double tauxMatin = TAUX_PIC_MATIN * std::exp(-(std::pow(t - TEMPS_PIC_MATIN, 2)) / (2 * std::pow(SIGMA_MATIN, 2)));
    double tauxApresMidi = TAUX_PIC_APRES_MIDI * std::exp(-(std::pow(t - TEMPS_PIC_APRES_MIDI, 2)) / (2 * std::pow(SIGMA_APRES_MIDI, 2)));
    return tauxMatin + tauxApresMidi;
}

void Simulateur::simuler() {
    std::random_device rd;
    std::mt19937 gen(
        std::hash<unsigned long>{}(
            std::chrono::system_clock::now().time_since_epoch().count()
            ^ rd()
        )
    );

    GlissadeEau glissade;
    int facteurVitesse = 1;
    int arriveesCeMinute = 0;

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
        arriveesCeMinute += nombreNouveauxVisiteurs;
        for (int i = 0; i < nombreNouveauxVisiteurs; i++) {
            Visiteur* nouveauVisiteur = new Visiteur();
            _visiteurs.insert(nouveauVisiteur);
            glissade.ajouterVisiteur(nouveauVisiteur);
        }

        Visiteur* visiteurSorti = glissade.traiterSortie();
        if (visiteurSorti != nullptr) {
            _visiteurs.erase(visiteurSorti);
            delete visiteurSorti;
        }

        if (glissade.getTemps().getTotalSeconds() % 60 == 0) {
            if (arriveesCeMinute < 3) {
                int manquant = 3 - arriveesCeMinute;
                for (int i = 0; i < manquant; i++) {
                    Visiteur* nouveauVisiteur = new Visiteur();
                    _visiteurs.insert(nouveauVisiteur);
                    glissade.ajouterVisiteur(nouveauVisiteur);
                }
            }
            arriveesCeMinute = 0;
        }
    }

    std::cout << std::endl << "La journee est terminee!" << std::endl;
}
