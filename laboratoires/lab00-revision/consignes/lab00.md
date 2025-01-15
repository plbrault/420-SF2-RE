# Laboratoire 0 - Révision du cours *Introduction à la programmation*

## Objectif

Réviser les principales notions de C++ vues dans le cours *Introduction à la programmation*.

Ce laboratoire doit être complété avant le deuxième cours. Vous repartirez de votre code du laboratoire 0 pour réaliser le laboratoire 1.

## Mise en situation

Vous allez développer un programme permettant de gérer une liste de tâches. Une tâche a une description, et peut être marquée comme ayant été faite. Le programme demandé possède un menu offrant les options suivantes:

1. Afficher la liste de tâches
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter

### Exemple d'exécution

Voici un premier exemple d'exécution du programme attendu, dans lequel on exécute toutes les options sauf la sixième:

```
Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

La liste est vide.

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 2

Entrez la tâche à ajouter : Faire le laboratoire 0

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 2

Entrez la tâche à ajouter : Faire valider mon laboratoire

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

1. [ ] Faire le laboratoire 0
2. [ ] Faire valider mon laboratoire

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 3

1. [ ] Faire le laboratoire 0
2. [ ] Faire valider mon laboratoire
Entrez le numéro de la tâche à marquer comme faite : 1

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

1. [X] Faire le laboratoire 0
2. [ ] Faire valider mon laboratoire

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 4

1. [X] Faire le laboratoire 0
2. [ ] Faire valider mon laboratoire
Entrez le numéro de la première tâche à échanger : 1
Entrez le numéro de la deuxième tâche à échanger : 2
Échange complété.

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

1. [ ] Faire valider mon laboratoire
2. [X] Faire le laboratoire 0

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 5

La liste de tâches a été sauvegardée.

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 7

Au revoir!
```

Voici maintenant un deuxième exemple d'exécution dans lequel on charge la liste de tâches sauvegardée précédemment:

```
Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

La liste est vide.

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 6

La liste de tâches a été chargée.

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 1

1. [ ] Faire valider mon laboratoire
2. [X] Faire le laboratoire 0

Liste de tâches
================================
1. Afficher la liste
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter
Entrez votre choix : 7

Au revoir!
```

## Code de départ

Dans Visual Studio, créez un nouveau projet C++ vide. Dans votre projet, créez les trois fichiers suivants:

* main.cpp
* fonctions.h
* fonctions.cpp

Ajoutez le contenu suivant à vos fichiers:

**main.cpp**

```c++
#include <iostream>
#include "fonctions.h"

using namespace std;
int main() {
    locale::global(locale{ "" });
}
```

**fonctions.h**

```c++
#pragma once

// Attention: Vous ne devez PAS modifier ce fichier!

void afficherMenu();
int demanderChoix(int max);
void afficherListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void ajouterTache(std::string taches[], int& nombreTaches);
int demanderNumeroTache(std::string texte, int nombreTaches);
void marquerFaite(std::string taches[], bool tacheCompletee[], int nombreTaches);
void echangerTaches(std::string taches[], bool tacheCompletee[], int nombreTaches);
void sauvegarderListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void chargerListe(std::string taches[], bool tacheCompletee[], int& nombreTaches);
```

**fonctions.cpp**

```c++
#include <iostream>
#include <fstream>
#include "fonctions.h"

using namespace std;

void afficherMenu() {
}

int demanderChoix(int max) {
    int choix;

    return choix;
}

void afficherListe(string taches[], bool tacheCompletee[], int nombreTaches) {
}

void ajouterTache(string taches[], int& nombreTaches) {
}

int demanderNumeroTache(string texte, int nombreTaches) {
}


void marquerFaite(string taches[], bool tacheCompletee[], int nombreTaches) {
}

void echangerTaches(string taches[], bool tacheCompletee[], int nombreTaches) {
}

void sauvegarderListe(std::string taches[], bool tacheCompletee[], int nombreTaches) {
}

void chargerListe(std::string taches[], bool tacheCompletee[], int& nombreTaches) {
}
```

## Étape 1
