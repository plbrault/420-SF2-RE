#ifndef SOLUTION_FONCTIONS_H
#define SOLUTION_FONCTIONS_H

#include <string>

void chargerTemperatures(double temperatures[], size_t& nbTemperatures, size_t capaciteTableau, std::string nomFichier);

void afficherMenu();
int demanderChoix(int min, int max);

void afficherTemperaturesCelsius(double temperatures[], size_t nbTemperatures);
void afficherTemperaturesKelvin(double temperatures[], size_t nbTemperatures);
double calculerTemperatureMoyenne(double temperatures[], size_t nbTemperatures);
bool ajouterTemperature(double temperatures[], size_t &nbTemperatures, size_t capaciteTableau);
void exporterTemperatures(double temperatures[], size_t nbTemperatures);

#endif