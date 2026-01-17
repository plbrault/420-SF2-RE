# Laboratoire 0 - Révision du cours *Introduction à la programmation*

## Objectif

Réviser les principales notions de C++ vues dans le cours *Introduction à la programmation*.

Ce laboratoire doit être complété avant le deuxième cours. Vous repartirez de votre code du laboratoire 0 pour réaliser le laboratoire 1.

## Mise en situation

Vous devez développer un programme permettant de gérer une liste de températures. Votre programme doit d'abord lire un fichier contenant les températures, et les ajouter à un tableau de valeurs décimales (nous utiliserons le type `double`). Les températures sont exprimées en degrés Celsius.

Votre programme devra ensuite présenter un menu offrant les options suivantes:

1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter

Le tableau de températures peut contenir un maximum de 100 valeurs.

Vous devez utiliser seulement les notions couvertes dans le cours *Introduction à la programmation*.

### Exemple d'exécution

Voici un exemple d'exécution du programme attendu, dans lequel on exécute toutes les options une à la suite de l'autre:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 1

1. -8°C
2. -7.5°C
3. -7.5°C
4. -7.25°C
5. -7°C
6. -6.75°C
7. -6.75°C
8. -6.5°C
9. -6°C
10. -5.5°C
11. -5°C
12. -4°C
13. -4°C
14. -3°C
15. -2°C
16. -1.5°C
17. -0.5°C
18. 0°C
19. 0.25°C
20. 0.5°C
21. 1°C
22. 1°C
23. 1.5°C
24. 2°C

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 2

1. 265.15 K
2. 265.65 K
3. 265.65 K
4. 265.9 K
5. 266.15 K
6. 266.4 K
7. 266.4 K
8. 266.65 K
9. 267.15 K
10. 267.65 K
11. 268.15 K
12. 269.15 K
13. 269.15 K
14. 270.15 K
15. 271.15 K
16. 271.65 K
17. 272.65 K
18. 273.15 K
19. 273.4 K
20. 273.65 K
21. 274.15 K
22. 274.15 K
23. 274.65 K
24. 275.15 K

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 3

La température moyenne est de -3.4375°C

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 4

Entrez une nouvelle température en Celsius: -10
La température a été ajoutée.

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 5

Entrer le nom du fichier dans lequel enregistrer les températures: temperatures2.txt
Les données ont été enregistrées dans temperatures2.txt.

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 6 

Au revoir!
```

## Consignes

### Étape 1 - Mise en place du projet

Créez un nouveau projet à l'aide de votre IDE. Dans ce projet, créez les trois fichiers suivants:

* main.cpp
* fonctions.h
* fonctions.cpp

À la racine de votre projet, créez un fichier texte que vous nommerez `temperatures.txt`. Voici le contenu de ce fichier:

```text
-8.0
-7.5
-7.5
-7.25
-7.0
-6.75
-6.75
-6.5
-6.0
-5.5
-5.0
-4.0
-4.0
-3.0
-2.0
-1.5
-0.5
0
0.25
0.5
1
1
1.5
2
```

Ajoutez le code de départ suivant dans vos fichiers de code et assurez-vous que votre programme compile:

**fonctions.h**

```cpp
#ifndef SOLUTION_FONCTIONS_H
#define SOLUTION_FONCTIONS_H

#include <string>

bool chargerTemperatures(double temperatures[], size_t& nbTemperatures, size_t capaciteTableau, std::string nomFichier);

void afficherMenu();
int demanderChoix(int min, int max);

void afficherTemperaturesCelsius(double temperatures[], size_t nbTemperatures);
void afficherTemperaturesKelvin(double temperatures[], size_t nbTemperatures);
double calculerTemperatureMoyenne(double temperatures[], size_t nbTemperatures);
bool ajouterTemperature(double temperatures[], size_t &nbTemperatures, size_t capaciteTableau);
void exporterTemperatures(double temperatures[], size_t nbTemperatures);

#endif
```

**fonctions.cpp**

```cpp
#include "fonctions.h"
#include <fstream>
#include <iostream>

const double ZERO_ABSOLU = -273.15;
const double TEMPERATURE_DE_PLANCK = 1.416808e32;

bool chargerTemperatures(double temperatures[], size_t& nbTemperatures, size_t capaciteTableau, std::string nomFichier) {
    return true;
}

void afficherMenu() {
}

int demanderChoix(int min, int max) {
    return 0;
}

void afficherTemperaturesCelsius(double temperatures[], size_t nbTemperatures) {
}

void afficherTemperaturesKelvin(double temperatures[], size_t nbTemperatures) {
}

double calculerTemperatureMoyenne(double temperatures[], size_t nbTemperatures) {
    return 0.0;
}

bool ajouterTemperature(double temperatures[], size_t &nbTemperatures, size_t capaciteTableau) {
    return false;
}

void exporterTemperatures(double temperatures[], size_t nbTemperatures) {
}
```

**main.cpp**

```cpp
#include <iostream>
#include <fstream>
#include "fonctions.h"

const size_t CAPACITE_TEMPERATURES = 100;

int main() {
    double temperatures[CAPACITE_TEMPERATURES];
    size_t nbTemperatures = 0;

    if (!chargerTemperatures(temperatures, nbTemperatures, CAPACITE_TEMPERATURES, "temperatures.txt")) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    return 0;
}
```

### Étape 2 - Fonction `chargerTemperatures`

Complétez la fonction `chargerTemperatures`. Cette fonction doit:

* Lire toutes les températures dans le fichier `nomFichier`
* Les ajouter au tableau `temperatures`
* Mettre à jour la variable `nbTemperatures` (passée par référence)

Si l'ouverture du fichier échoue, il faut immédiatement retourner `false`. Autrement, on retourne `true` à la fin de la fonction. N'oubliez cependant pas de fermer le fichier!

La fonction doit aussi s'assurer de ne pas tenter d'ajouter plus de températures que la capacité du tableau (`capaciteTableau`).

Vous pouvez prendre pour acquis que toutes les valeurs contenues dans le fichier sont valides.

La fonction est déjà appelée dans le `main`. **Utilisez le débogueur pour valider son fonctionnement avant de passer à l'étape suivante.**

> Remarquez que la fonction `chargerTemperatures` prend 4 paramètres. Cela commence à faire beaucoup! Nous avons besoin de trois paramètres uniquement pour la gestion du tableau. La programmation orientée objet et les structures de données nous aideront éventuellement à simplifier de telles fonctions.

### Étape 3 - Fonction `afficherMenu`

Complétez la fonction `afficherMenu`. Celle-ci doit afficher le menu ci-dessous:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
```

Appelez la fonction dans le `main` pour la tester.

### Étape 4 - Fonction `demanderChoix`

Complétez la fonction `demanderChoix`. Celle-ci doit:

* Demander à l'utilisateur d'entrer un choix entre `min` et `max`
* Tant que la valeur saisie n'est pas dans la plage demandée, afficher un message d'erreur et demander une nouvelle valeur
* Une fois qu'une valeur valide est saisie, retourner cette valeur

Il n'est pas nécessaire de valider le type de la donnée saisie (prendre pour acquis que l'utilisateur entre un nombre entier).

Voici un exemple d'exécution:

```text
Entrez un choix entre 1 et 6: -7
Votre choix est invalide.
Entrez un choix entre 1 et 6: 8
Votre choix est invalide.
Entrez un choix entre 1 et 6: 2
```

Testez bien votre fonction dans le `main` avant de poursuivre.

### Étape 5 - Boucle principale

Il est temps d'ajouter la boucle principale du programme dans le `main`. Chaque itération de cette boucle doit:

1. Afficher le menu
2. Demander un choix à l'utilisateur
3. Utiliser un `switch` pour gérer l'option choisie (les `case` seront vides pour l'instant)

Cette boucle doit se répéter tant que l'option `6 - Quitter` n'est pas choisie. Dans ce dernier cas, il faut afficher `Au revoir!` avant l'arrêt du programme.

Testez bien votre code. Voici à quoi devrait ressembler son exécution à ce stade-ci:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 1

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 2

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 6

Au revoir!
```

### Étape 6 - Fonction `afficherTemperaturesCelsius`

Complétez la fonction `afficherTemperaturesCelsius`. Celle-ci doit parcourir le tableau de températures et afficher son contenu. Voici l'affichage attendu:

```text
1. -8°C
2. -7.5°C
3. -7.5°C
4. -7.25°C
5. -7°C
6. -6.75°C
7. -6.75°C
8. -6.5°C
9. -6°C
10. -5.5°C
11. -5°C
12. -4°C
13. -4°C
14. -3°C
15. -2°C
16. -1.5°C
17. -0.5°C
18. 0°C
19. 0.25°C
20. 0.5°C
21. 1°C
22. 1°C
23. 1.5°C
24. 2°C
```

Vous pouvez utiliser la valeur `'\370'` pour afficher le caractère `°` sur Windows.

Appelez la fonction à l'endroit approprié dans votre `main`. Testez bien votre code.

### Étape 7 - Fonction `afficherTemperaturesKelvin`

Complétez la fonction `afficherTemperaturesKelvin`. Celle-ci doit parcourir le tableau de températures et afficher son contenu converti en Kelvin. Voici l'affichage attendu:

```text
1. 265.15 K
2. 265.65 K
3. 265.65 K
4. 265.9 K
5. 266.15 K
6. 266.4 K
7. 266.4 K
8. 266.65 K
9. 267.15 K
10. 267.65 K
11. 268.15 K
12. 269.15 K
13. 269.15 K
14. 270.15 K
15. 271.15 K
16. 271.65 K
17. 272.65 K
18. 273.15 K
19. 273.4 K
20. 273.65 K
21. 274.15 K
22. 274.15 K
23. 274.65 K
24. 275.15 K
```

Appelez la fonction à l'endroit approprié dans votre `main`. Testez bien votre code.

### Étape 8 - Fonction `calculerTemperatureMoyenne`

Complétez la fonction `calculerTemperatureMoyenne`. Celle-ci doit retourner la moyenne en Celsius de toutes les températures du tableau. Avec le contenu actuel du fichier, vous devriez obtenir la valeur **-3.4375**.

Dans le `main`, utilisez cette fonction pour générer l'affichage suivant lorsque l'utilisateur choisit l'option 3:

```text
La température moyenne est de -3.4375°C
```

### Étape 9 - Fonction `ajouterTemperature`

Complétez la fonction `ajouterTemperature`. Cette fonction demande à l'utilisateur d'entrer une température en degrés Celsius. Elle valide ensuite que la température saisie respecte les conditions suivantes:

* Elle n'est pas inférieure au zéro absolu
* Elle n'est pas supérieure à la [température de Planck](https://fr.wikipedia.org/wiki/Temp%C3%A9rature_de_Planck)

Si une de ces conditions n'est pas respectée, un message d'erreur significatif doit être affiché. La fonction doit ensuite immédiatement retourner `false`.

Si la température est valide, il faut l'ajouter à la suite de la dernière température ajoutée au tableau, et mettre à jour `nbTemperatures`. N'oubliez pas de valider que la capacité du tableau n'est pas dépassée!

La fonction doit retourner `true` uniquement si l'ajout d'une température est réussi.

Voici quelques exemples d'exécution:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 4

Entrez une nouvelle température en Celsius: -345.67 
La température est trop petite.

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 4

Entrez une nouvelle température en Celsius: 1e33
La température est trop grande.

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 4

Entrez une nouvelle température en Celsius: 14.5
La température a été ajoutée.

MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 1

1. -8°C
2. -7.5°C
3. -7.5°C
4. -7.25°C
5. -7°C
6. -6.75°C
7. -6.75°C
8. -6.5°C
9. -6°C
10. -5.5°C
11. -5°C
12. -4°C
13. -4°C
14. -3°C
15. -2°C
16. -1.5°C
17. -0.5°C
18. 0°C
19. 0.25°C
20. 0.5°C
21. 1°C
22. 1°C
23. 1.5°C
24. 2°C
25. 14.5°C
```

Testez bien les différentes possibilités avant de poursuivre.

### Étape 10 - Fonction `exporterTemperatures`

Complétez la fonction `exporterTemperatures`. Cette fonction doit écrire le contenu du tableau de températures dans le fichier indiqué par l'utilisateur. Voici un exemple d'exécution:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 5

Entrer le nom du fichier dans lequel enregistrer les températures: temperatures2.txt
Les données ont été enregistrées dans temperatures2.txt.
```

Il faut bien sûr gérer l'ouverture et la fermeture du fichier, de même que l'affichage d'un message significatif en cas d'erreur.

Les températures dans le fichier de sortie doivent être séparées par des sauts de ligne.

Vérifiez que le contenu du fichier est correct.

> 🎉 Félicitations, vous avez complété le Laboratoire 0! Conservez vos fichiers en lieu sûr, car vous en aurez besoin pour le Laboratoire 1.
