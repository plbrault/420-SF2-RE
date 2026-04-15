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
const int VITESSE_MAX = 10000;
const unsigned long HEURE_PIC_MATIN = 7200;
const unsigned long HEURE_PIC_APRES_MIDI = 21000;
const double SIGMA_MATIN = 2700.0;
const double SIGMA_APRES_MIDI = 2700.0;
const double TAUX_PIC_MATIN = 0.34;
const double TAUX_PIC_APRES_MIDI = 0.35;

Simulateur::Simulateur() {
    _glissade = GlissadeEau(3);
    _facteurVitesse = 1;
    _arriveesMinuteCourante = 0;
}

Simulateur::~Simulateur() {
    for (Visiteur* visiteur : _visiteurs) {
        delete visiteur;
    }
}

double Simulateur::calculerTauxArrivee(unsigned long secondesEcoulees) {
    double t = static_cast<double>(secondesEcoulees);
    double tauxMatin = TAUX_PIC_MATIN * std::exp(-(std::pow(t - HEURE_PIC_MATIN, 2)) / (2 * std::pow(SIGMA_MATIN, 2)));
    double tauxApresMidi = TAUX_PIC_APRES_MIDI * std::exp(-(std::pow(t - HEURE_PIC_APRES_MIDI, 2)) / (2 * std::pow(SIGMA_APRES_MIDI, 2)));
    return tauxMatin + tauxApresMidi;
}

void Simulateur::afficher() const {
    effacerEcran();
    std::cout << _glissade;
    std::cout << "Vitesse: ";
    if (_facteurVitesse > 1) {
        std::cout << "[-] ";
    }
    std::cout << _facteurVitesse << "x";
    if (_facteurVitesse < VITESSE_MAX) {
        std::cout << " [+]";
    }
    std::cout << std::endl;
    std::cout << "q pour quitter" << std::endl;
}

void Simulateur::simulerArrivees(std::mt19937& gen) {
    unsigned long secondesEcoulees = _glissade.getHeureActuelle().getTotalSeconds() - 9 * 3600;
    double lambda = calculerTauxArrivee(secondesEcoulees);
    int nombreNouveauxVisiteurs = 0;
    if (lambda > 0.0) {
        std::poisson_distribution<int> dist(lambda);
        nombreNouveauxVisiteurs = dist(gen);
    }
    if (secondesEcoulees < 60) {
        std::bernoulli_distribution distVague(0.15);
        if (distVague(gen)) {
            std::uniform_int_distribution<int> distTaille(1, 3);
            nombreNouveauxVisiteurs += distTaille(gen);
        }
    }
    _arriveesMinuteCourante += nombreNouveauxVisiteurs;
    for (int i = 0; i < nombreNouveauxVisiteurs; i++) {
        Visiteur* nouveauVisiteur = new Visiteur();
        _visiteurs.insert(nouveauVisiteur);
        _glissade.ajouterVisiteur(nouveauVisiteur);
    }

    Visiteur* visiteurSorti = _glissade.traiterSortie();
    if (visiteurSorti != nullptr) {
        _visiteurs.erase(visiteurSorti);
        delete visiteurSorti;
    }

    if (secondesEcoulees % 60 == 0) {
        if (_arriveesMinuteCourante < 3) {
            int manquant = 3 - _arriveesMinuteCourante;
            for (int i = 0; i < manquant; i++) {
                Visiteur* nouveauVisiteur = new Visiteur();
                _visiteurs.insert(nouveauVisiteur);
                _glissade.ajouterVisiteur(nouveauVisiteur);
            }
        }
        _arriveesMinuteCourante = 0;
    }
}

void Simulateur::simuler() {
    std::random_device rd;
    std::mt19937 gen(
        std::hash<unsigned long>{}(
            std::chrono::system_clock::now().time_since_epoch().count()
            ^ rd()
        )
    );

    while (_glissade.getHeureActuelle().getTotalSeconds() < 17 * 3600) {
        Touche touche = lireTouche();
        if (touche == Touche::QUITTER) {
            break;
        }
        if (touche == Touche::PLUS && _facteurVitesse < VITESSE_MAX) {
            _facteurVitesse *= 10;
        }
        if (touche == Touche::MOINS && _facteurVitesse > 1) {
            _facteurVitesse /= 10;
        }

        if (_facteurVitesse <= 10) {
            afficher();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / _facteurVitesse));
            _glissade.mettreAJour();
            simulerArrivees(gen);
        } else {
            for (int i = 0; i < _facteurVitesse / 10; i++) {
                _glissade.mettreAJour();
                simulerArrivees(gen);
            }
            afficher();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    std::cout << std::endl << "La journee est terminee!" << std::endl;
}
