#ifndef SOLUTION_FONCTIONS_H
#define SOLUTION_FONCTIONS_H

#include <string>

void afficherMenu();
int demanderChoix(int min, int max);

void afficherTemperaturesCelsius(double temperatures[], int nbTemperatures);
void afficherTemperaturesKelvin(double temperatures[], int nbTemperatures);
double calculerTemperatureMoyenne(double temperatures[], int nbTemperatures);
bool ajouterTemperature(double temperatures[], int& nbTemperatures, int capaciteTableau);
void exporterTemperatures(double temperatures[], int nbTemperatures);

#endif