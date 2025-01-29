#pragma once

#include "menu.h"
#include "personne.h"

Menu construireMenuPrincipal(void);
void afficherMenu(Menu &);
int demanderChoix(Menu &menu);
void afficherListe(Personne &);
void ajouterTache(Personne &);
size_t demanderNumeroTache(std::string, Personne &);
void marquerFaite(Personne &);
void echangerTaches(Personne &);
void sauvegarderPersonne(Personne &);
void chargerPersonne(Personne &);
void supprimerTache(Personne &);
