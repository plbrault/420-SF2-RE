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
* `_rayon` de type `unsigned int`
* `_masse` de type `double`
* `_distanceSoleil` de type `double`

> `unsigned int` signifie « **nombre entier non signé** », c'est-à-dire un nombre entier qui ne peut être négatif. L'avantage d'utiliser un `unsigned int` lorsque possible est qu'on peut exprimer des nombres plus grands avec le même nombre de bits, puisque la valeur maximale d'un `unsigned int` sur 32 bits est **4 294 967 295** tandis que celle d'un `int` est **2 147 483 647**. Cela est dû au fait qu'un `int` doit réserver la moitié de ses valeurs possibles pour les nombres négatifs.

Les attributs `_rayon` et `_distanceSoleil` sont exprimés en mètres, tandis que l'attribut `masse` est exprimé en kilogrammes.

Ensuite, dans la partie publique (***public***), ajoutez le constructeur suivant:

```cpp
Planete(std::string nom, unsigned int rayon, double masse, double distanceSoleil);
```

Voici à quoi devrait ressembler votre définition de classe à ce stade-ci:

```cpp
class Planete {
private:
    std::string _nom;
    unsigned int _rayon;
    double _masse;
    double _distanceSoleil;

public:
    Planete(std::string nom, unsigned int rayon, double masse, double distanceSoleil);
};
```

Pour pouvoir utiliser cette classe, il vous reste à **implémenter** votre constructeur dans le fichier `Planete.cpp`.

```cpp
Planete::Planete(std::string nom, unsigned int rayon, double masse, double distanceSoleil) {
    // Ajoutez ici le code nécessaire pour assigner les
    // paramètres aux attributs correspondants de l'objet
}
```

Vous êtes maintenant en mesure d'instancier une planète dans votre `main`. Instanciez la Terre de la façon suivante:

```cpp
Planete terre("Terre", 6371000, 5.972e24, 1.496e8);
```

> N'oubliez pas d'inclure `Planete.h` au début de votre fichier `main.cpp`!

Cette ligne de code crée un nouvel **objet** de type `Planete`.
Cet objet est donc une **instance** de la classe `Planete`.
L'objet est stocké dans la variable `planete`.

Pour instancier cet objet, vous appelez son **constructeur**, qui prend 4 paramètres. Vous lui passez les paramètres suivants:

* Le nom de la planète, qui est `Terre`
* Son rayon, soit **6 371 000 mètres**
* Sa masse, soit **$5.972 \times 10^{24}$ kilogrammes**
* Sa distance du soleil, soit **$1.496 \times 10^{8}$ mètres**

Validez que votre code compile. Utilisez le débogueur pour vérifier que l'objet `terre` contient les bonnes valeurs d'attributs.