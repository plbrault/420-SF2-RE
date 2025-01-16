# Laboratoire 0 - Révision du cours *Introduction à la programmation*

## Objectif

Réviser les principales notions de C++ vues dans le cours *Introduction à la programmation*.

Ce laboratoire doit être complété avant le deuxième cours. Vous repartirez de votre code du laboratoire 0 pour réaliser le laboratoire 1.

## Mise en situation

Vous devez développer un programme permettant de gérer une liste de tâches. Une tâche a une description, et peut être marquée comme ayant été faite. Le programme attendu possède un menu offrant les options suivantes:

1. Afficher la liste de tâches
2. Ajouter une tâche
3. Marquer une tâche comme faite
4. Échanger deux tâches
5. Sauvegarder la liste de tâches
6. Charger la liste de tâches
7. Quitter

Un maximum de 100 tâches doivent pouvoir être ajoutées par l'utilisateur.

Vous devez utiliser seulement les notions couvertes dans le cours *Introduction à la programmation*.

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

Prenez connaissance de ce code avant de poursuivre.

## Étapes

### Étape 1

Implémentez la fonction `afficherMenu` en complétant sa définition dans le fichier `fonctions.cpp`. La fonction doit produire l'affichage suivant:

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
```

Testez votre fonction en l'appelant dans le `main`.

### Étape 2

Implémentez maintenant la fonction `demanderChoix`.

* Cette fonction sert à demander à l'utilisateur quelle option du menu il veut exécuter.
* Si l'option saisie est invalide, une nouvelle saisie est demandée.
* L'option saisie est valide si elle est supérieure à 0, et inférieure ou égale à la valeur du paramètre `int max`.
* La fonction retourne l'option choisie.

Voici un exemple d'exécution de cette fonction:

```
Entrez votre choix : -1
Le choix doit être un chiffre entre 1 et 7.
Entrez votre choix : 8
Le choix doit être un chiffre entre 1 et 7.
Entrez votre choix : 1
```

Testez votre fonction en l'appelant dans le `main`. Assurez-vous que la validation fonctionne correctement.

### Étape 3

Vous pouvez maintenant ajouter la structure de base de la fonction `main`. Celle-ci est constituée des éléments suivants:

* Une boucle *do-while* qui se ré-exécute tant que l'option 7 (Quitter) n'est pas choisie. Le corps de cette boucle doit:

    1. Appeler la fonction `afficherMenu`
    2. Appeler la fonction `demanderChoix` et stocker son résultat dans une variable.
    3. Exécuter une structure conditionnelle `switch-case` avec un cas pour chacune des options 1 à 6 et un cas par défaut qui affiche « Au revoir! ». Laissez les cas des options 1 à 6 vides pour le moment.

Assurez-vous que votre code fonctionne correctement avant de continuer.

### Étape 4

Il vous faut maintenant ajouter au `main` les variables dont vous aurez besoin pour gérer la liste de tâches. Ces variables sont les suivantes:

* Un tableau de chaînes de caractères (string) de 100 éléments, nommé `taches`, qui contiendra les description des tâches.
* Un tableau de booléens de 100 éléments initialisés à `false`, nommé `tacheCompletee`, qui permettra d'indiquer si une tâche est marquée comme complétée ou non.
* Un nombre entier initialisé à 0, nommé `nombreTaches`, indiquant le nombre de tâches ayant été ajoutées jusqu'à maintenant.

### Étape 5

Vous devez maintenant implémenter les fonctions `afficherListe` et `ajouterTache`.

La fonction `afficherListe` doit:

* Afficher « La liste est vide. » si le nombre de tâches est de 0.
* Autrement, afficher la liste de tâches au format suivant:

```
1. [x] Compléter le laboratoire 0
2. [ ] Faire valider le laboratoire 0 par l'enseignant
3. [ ] Dormir
```

* La présence d'un `x` à l'intérieur du `[ ]` à côté d'une tâche indique que celle-ci a été complétée.

La fonction `ajouterTache` doit:

* S'assurer que la liste n'est pas pleine et afficher un message d'erreur le cas échéant.
* Demander à l'utilisateur de saisir une tâche.
* Ajouter la tâche saisie au tableau de tâches.
* Incrémenter `nombreTaches`.

Ajoutez les appels de ces deux fonctions aux endroits appropriés dans le `main`. Testez votre code rigoureusement.

### Étape 6

Vous devez maintenant implémenter les fonctions `demanderNumeroTache` et `marquerFaite`.

La fonction `demanderNumeroTache` est utilisée par la fonction `marquerFaite`.

* Elle demande une saisie au clavier en affichant d'abord le texte reçu en paramètre (ex: `"Entrez le numéro de la tâche à marquer comme faite:"`).
* Elle valide la saisie et s'assure qu'il s'agit d'un numéro de tâche valide, c'est-à-dire un numéro entre 1 et le nombre de tâches. Si la saisie est invalide, elle en demande une nouvelle.
* Elle retourne le numéro saisi.

Voici un exemple d'exécution de la fonction `demanderNumeroTache` en supposant que la liste de tâches contient 50 tâches:

```
Entrez le numéro de la tâche à marquer comme faite : -1
Le numéro saisi est invalide.
Entrez le numéro de la tâche à marquer comme faite : 51
Le numéro saisi est invalide.
Entrez le numéro de la tâche à marquer comme faite : 22
```

La fonction `marquerFaite` doit, pour sa part:

* Afficher la liste des tâches en appelant la fonction appropriée.
* Si la liste contient au moins une tâche, utiliser la fonction `demanderNumeroTache` pour demander à l'utilisateur d'entrer le numéro de la tâche faite.
* Changer la valeur appropriée du tableau `tacheCompletee` pour `true`.

Appelez l'appel de la fonction `marquerFaite` à l'endroit approprié du `main`. Testez votre code rigoureusement.

### Étape 7

Implémentez maintenant la fonction `echangerTaches`. Cette fonction doit:

* Demander deux numéros de tâche à l'utilisateur (vous pouvez réutiliser une fonction que vous avez déjà codée pour cela!).
* Échanger ces deux tâches dans le tableau `taches`.
* Échanger les valeurs correspondantes dans le tableau `tacheCompletee`.

La fonction doit d'abord s'assurer que la liste comporte au moins deux tâches, et afficher un message d'erreur si ce n'est pas le cas.

Appelez la fonction à l'endroit approprié dans le `main`. Testez votre code rigoureusement.

### Étape 8

Implémentez la fonction `sauvegarderListe`. Cette fonction doit enregistrer les tâches dans le fichier `taches.txt`. Chaque tâche doit utiliser deux lignes dans le fichier:

1. Une ligne pour la description de la tâche.
2. Une ligne pour l'état de la tâche, soit complétée (1) ou non complétée (0).

Par exemple, si la liste de tâches ressemble présentement à ceci:

```
1. [ ] Compléter le laboratoire 0
2. [x] Faire valider le laboratoire 0 par l'enseignant
3. [ ] Dormir
```

Le contenu du fichier après sauvegarde ressemblera à cela:

```
Compléter le laboratoire 0
0
Faire valider le laboratoire 0 par l'enseignant
1
Dormir
0
```

Appelez la fonction à l'endroit approprié dans le `main`. Testez votre code vigoureusement et vérifiez que le contenu du fichier est correct.

### Étape 9

Implémentez la fonction `chargerListe`. Cette fonction doit lire le fichier `taches.txt` créé par la fonction de sauvegarde, puis écraser le contenu des variables `taches`, `tacheCompletee` avec celui du fichier. N'oubliez pas de mettre à jour la variable `nombreTaches`!

Cette étape complète le programme. Validez que tout fonctionne correctement.
