#ifndef SOLUTION_FONCTIONS_H
#define SOLUTION_FONCTIONS_H

#include <string>

double* chargerTemperatures(size_t &nbTemperatures, std::string nomFichier);

void afficherMenu();
int demanderChoix(int min, int max);

void afficherTemperaturesCelsius(double temperatures[], size_t nbTemperatures);
void afficherTemperaturesKelvin(double temperatures[], size_t nbTemperatures);
double calculerTemperatureMoyenne(double temperatures[], size_t nbTemperatures);
double* ajouterTemperature(double* temperatures, size_t &nbTemperatures);
void exporterTemperatures(double temperatures[], size_t nbTemperatures);

#endif