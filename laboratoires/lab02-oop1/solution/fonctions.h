#pragma once

#include "menu.h"
#include "personne.h"
#include "task.h"

Menu construireMenuPrincipal(void);
void afficherMenu(Menu &);
int demanderChoix(Menu &menu);
void afficherListe(Personne &);
void ajouterTache(Personne &);
int demanderNumeroTache(std::string, Personne &);
void marquerFaite(Personne &);
void echangerTaches(Personne &);
void sauvegarderListe(Personne &);
void chargerListe(Personne &);
void supprimerTache(Personne &);

void afficherTache(Task &);