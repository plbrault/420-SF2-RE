//
// Created by plbrault on 2026-04-11.
//

#ifndef LAB09_FONCTIONS_H
#define LAB09_FONCTIONS_H

enum class Touche { AUCUNE, DROITE, GAUCHE, QUITTER };

void effacerEcran();
Touche lireTouche();
double calculerTauxArrivee(unsigned long temps);

#endif //LAB09_FONCTIONS_H
