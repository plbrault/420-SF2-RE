#pragma once

void afficherMenu();
int demanderChoix(int max);
void afficherListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void ajouterTache(std::string taches[], int& nombreTaches);
int demanderNumeroTache(std::string texte, int nombreTaches);
void marquerFaite(std::string taches[], bool tacheCompletee[], int nombreTaches);
void echangerTaches(std::string taches[], bool tacheCompletee[], int nombreTaches);
void sauvegarderListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void chargerListe(std::string taches[], bool tacheCompletee[], int& nombreTaches);
