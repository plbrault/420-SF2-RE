# Laboratoire 02

## Objectif

Mettre en pratique les notions suivantes:

* Création d'une classe avec ses attributs et ses méthodes
* Implémentation des constructeurs avec et sans paramètres
* Implémentation d'un destructeur
* Instancation et utilisation des objets
* Création et utilisation d'un tableau d'objets en allocation statique et dynamique

## Parties

Ce laboratoire est divisé en deux parties:

* **Laboratoire 02-A**: représentation du système solaire à l'aide d'une classe `Planete`
* **Laboratoire 02-B**: implémentation des classes `Temperature` et `Menu` dans le programme des laboratoire précédents

## Laboratoire 02-A

Dans cette première partie, nous allons coder un programme qui affiche certaines caractéristiques des 8 planètes du système solaire, comme ceci:

```text
=== PLANÈTES DU SYSTÈME SOLAIRE ===
===================================

Planète Mercure:
 - Rayon: 2.439e+06 m
 - Masse: 3.301e+23 kg
 - Distance du soleil: 5.79e+07
 - Gravité de surface: 3.70363 m/s^2

Planète Vénus:
 - Rayon: 6.052e+06 m
 - Masse: 4.867e+24 kg
 - Distance du soleil: 1.082e+08
 - Gravité de surface: 8.86889 m/s^2

Planète Terre:
 - Rayon: 6.371e+06 m
 - Masse: 5.972e+24 kg
 - Distance du soleil: 1.496e+08
 - Gravité de surface: 9.81997 m/s^2

Planète Mars:
 - Rayon: 3.39e+06 m
 - Masse: 6.39e+23 kg
 - Distance du soleil: 2.279e+08
 - Gravité de surface: 3.71114 m/s^2

Planète Jupiter:
 - Rayon: 6.9911e+07 m
 - Masse: 1.898e+27 kg
 - Distance du soleil: 7.785e+08
 - Gravité de surface: 25.9186 m/s^2

Planète Saturne:
 - Rayon: 5.8232e+07 m
 - Masse: 5.683e+26 kg
 - Distance du soleil: 1.433e+09
 - Gravité de surface: 11.1856 m/s^2

Planète Uranus:
 - Rayon: 2.5362e+07 m
 - Masse: 8.681e+25 kg
 - Distance du soleil: 2.877e+09
 - Gravité de surface: 9.00759 m/s^2

Planète Neptune:
 - Rayon: 2.4622e+07 m
 - Masse: 1.024e+26 kg
 - Distance du soleil: 4.503e+09
 - Gravité de surface: 11.2735 m/s^2
```

Pour ce faire, nous allons bien sûr utiliser une classe `Planete` !

### Étape 1

Commencez par créer un nouveau projet avec un `main` vide. Assurez-vous que le tout compile.

Dans ce projet, ajoutez ensuite un fichier `Planete.h` et un fichier `Planete.cpp`.

> **Astuce:** vous pouvez utiliser l'option ***New C++ Class*** dans CLion. Celle-ci créera automatiquement votre fichier **.h** et votre fichier **.cpp**.

Dans votre fichier `Planete.h`, ajoutez le code de départ pour la définition d'une classe `Planete`.

```cpp
class Planete {
private:

public:

};
```

Dans la partie privée (***private***) de la classe, définissez les attributs (propriétés) suivants:

* `_nom` de type `std::string`
* `_rayon` de type `double`
* `_masse` de type `double`
* `_distanceSoleil` de type `double`

Les attributs `_rayon` et `_distanceSoleil` sont exprimés en mètres, tandis que l'attribut `masse` est exprimé en kilogrammes.

Ensuite, dans la partie publique (***public***), ajoutez le constructeur suivant:

```cpp
Planete(std::string nom, double rayon, double masse, double distanceSoleil);
```