# Laboratoire 02

## Objectif

Mettre en pratique les notions suivantes:

* Création d'une classe avec ses attributs et ses méthodes
* Implémentation des constructeurs avec et sans paramètres
* Implémentation d'un destructeur
* Instancation et utilisation des objets
* Création et utilisation d'un tableau d'objets en allocation statique
* Passage d'un objet en paramètre d'une fonction

## Parties

Ce laboratoire est divisé en trois parties:

* **Laboratoire 02-A**: représentation du système solaire à l'aide d'une classe `Planete`
* **Laboratoire 02-B**: implémentation d'une classe `Parabole` représentant une équation quadratique
* **Laboratoire 02-C**: implémentation d'une classe `Menu` dans le programme du Laboratoire 01-C

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

Voici à quoi devrait ressembler votre définition de classe à ce stade-ci:

```cpp
class Planete {
private:
    std::string _nom;
    double _rayon;
    double _masse;
    double _distanceSoleil;

public:
    Planete(std::string nom, double rayon, double masse, double distanceSoleil);
};
```

Pour pouvoir utiliser cette classe, il vous reste à **implémenter** votre constructeur dans le fichier `Planete.cpp`.

```cpp
Planete::Planete(std::string nom, double rayon, double masse, double distanceSoleil) {
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

### Étape 2

On veut maintenant pouvoir afficher le contenu de notre objet de type `Planete`. Pour ce faire, nous allons ajouter une méthode `afficher` dans la partie publique de la classe (fichier **.h**):

```cpp
void afficher();
```

Et l'implémentation (fichier **.cpp**):

```cpp
void Planete::afficher() {
    // Ajoutez ici le code nécessaire pour afficher les attributs de la planète
}
```

Voici un exemple de l'affichage voulu à ce stade-ci:

```text
Planète Terre:
 - Rayon: 6371000 m
 - Masse: 5.972e+24 kg
 - Distance du soleil: 1.496e+08
```

Pour tester votre méthode, il faut l'appeler. Ajoutez donc la ligne de code suivante à la suite de l'instanciation de l'objet `terre` dans votre `main`:

```cpp
terre.afficher();
```

Vous devriez obtenir le même affichage que dans l'exemple ci-dessus. Autrement, corrigez le code de votre méthode.

Testez maintenant votre méthode avec une deuxième planète:

```cpp
Planete mars("Mars", 3390000, 6.39e23, 2.279e8);

mars.afficher();
```

Voici le résultat attendu:

```text
Planète Mars:
 - Rayon: 3390000 m
 - Masse: 6.39e+23 kg
 - Distance du soleil: 2.279e+08
```

### Étape 3

Votre méthode `afficher` fonctionne bien, mais elle assume qu'on veut afficher la planète dans la **sortie standard**. Si on voulait plutôt afficher la planète dans une autre sortie, par exemple la sortie d'erreur ou les journaux du système, on ne pourrait pas utiliser cette méthode.

N'ayez crainte, car il existe une façon simple de rendre notre méthode plus réutilisable. Elle consiste à **passer la sortie voulue à la méthode**. Pour ce faire, il faut ajouter un paramètre de type `std::ostream`, passé par référence:

```cpp
void afficher(std::ostream& sortie);
```

Ensuite, il faut modifier le code de la méthode en y remplaçant `std::cout` par `sortie`.

```cpp
void Planete::afficher(std::ostream &sortie) {
    sortie << "Planète " << this->_nom << ":" << std::endl
        << // ...
}
```

Finalement, il faut modifier l'appel de la méthode `afficher` pour passer `std::cout` au paramètre `sortie`:

```cpp
Planete terre("Terre", 6371000, 5.972e24, 1.496e8);
Planete mars("Mars", 3390000, 6.39e23, 2.279e8);

terre.afficher(std::cout);
mars.afficher(std::cout);
```

Validez que votre programme compile toujours et que son résultat n'a pas changé.

> Suite à cette modification, il devient même possible d'utiliser la méthode `afficher` pour écrire dans un fichier, en lui passant un objet de type `std::ofstream` au lieu de `std::cout`. Cela est permis puisque `std::ofstream` est une version spécialisée de `std::ostream`. Cela sera plus clair lorsque nous aurons vu l'héritage au chapitre 5.

### Étape 4

Bon, la réutilisabilité c'est bien, mais ça vous ennuie quand même un peu de devoir toujours passer `std::cout` chaque fois que vous appelez la méthode `afficher`, non? Et si on ajoutait une deuxième version de la méthode, qui utiliserait `std::cout` par défaut?

**Conservez votre méthode `void afficher(std::ostream& sortie)` actuelle.** Suite à cette méthode, ajoutez une autre méthode, qui portera le même nom:

```cpp
void afficher();
```

Voici son implémentation:

```cpp
void Planete::afficher() {
    this->afficher(std::cout);
}
```

Comme vous voyez, cette méthode ne prend aucun paramètre (comme avant!). Mais au lieu de faire l'affichage directement, elle appelle l'**autre version de la méthode**, en passant `std::cout` à son paramètre `sortie`.

![](./images/bob_leponge_reutilisation.jpg)

Vous pouvez maintenant ré-enlever `std::cout` dans vos appels de la méthode `afficher` (dans le `main`):

```cpp
Planete terre("Terre", 6371000, 5.972e24, 1.496e8);
Planete mars("Mars", 3390000, 6.39e23, 2.279e8);

terre.afficher();
mars.afficher();
```

## Étape 5

À ce stade-ci, notre classe `Planete` a:

* 4 attributs privés
* 1 constructeur avec paramètres
* 2 versions d'une méthode `afficher`

Ne serait-il pas amusant d'ajouter une méthode pour calculer la [gravité de surface](https://fr.wikipedia.org/wiki/Gravit%C3%A9_de_surface) de la planète?

La formule pour calculer la gravité de surface ($g$) est:

$$
g = G \times \frac{M}{R^{2}}
$$

Où:

* $G$ est la constante gravitationnelle universelle (`6.67430e-11`)
* $M$ est la masse de la planète
* $R$ est le rayon de la planète

La gravité de surface s'exprime en $\mathrm{m\,/\,s^{2}}$.

Voici le prototype de la méthode que vous devez implémenter:

```cpp
double calculerGraviteSurface();
```

Une fois votre méthode implémentée, appelez-la dans votre `main` sur les objets `terre` et `mars`, et faites afficher le résultat. Vous devriez obtenir les valeurs suivantes:

* Terre: `9.81997`
* Mars: `3.71114`

## Étape 6

Ce serait bien d'afficher la gravité de surface avec le reste des caractéristiques de la planète.

Pour ce faire, modifiez la méthode `afficher` pour ajouter cette valeur à l'affichage. La méthode `afficher` doit appeler la méthode `calculerGraviteSurface`.

La sortie de votre programme devrait maintenant ressembler à ceci:

```text
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
```

## Étape 7

Remplacez votre code du `main` par celui-ci, qui instancie toutes les planètes du système solaire:

```cpp
Planete mercure("Mercure", 2439000, 3.301e23, 5.79e7);
Planete venus("Vénus", 6052000, 4.867e24, 1.082e8);
Planete terre("Terre", 6371000, 5.972e24, 1.496e8);
Planete mars("Mars", 3390000, 6.39e23, 2.279e8);
Planete jupiter("Jupiter", 69911000, 1.898e27, 7.785e8);
Planete saturne("Saturne", 58232000, 5.683e26, 1.433e9);
Planete uranus("Uranus", 25362000, 8.681e25, 2.877e9);
Planete neptune("Neptune", 24622000, 1.024e26, 4.503e9);
```

Vérifiez que votre programme compile toujours (il ne devrait maintenant rien afficher).

Nous voulons maintenant ajouter ces planètes à un tableau représentant le système solaire. Commencez par déclarer ce tableau en allocation statique:

```cpp
Planete systemeSolaire[8];
```

Oh non! Vous avez maintenant une erreur de compilation! 😱 Pourquoi donc?

Voyons voir ce que dit le message d'erreur en passant la souris sur notre tableau dans CLion:

> *Cannot initialize an object of type Planet[8]: default constructor is missing*

On nous parle de *default constructor* qui serait manquant 🤔. L'erreur serait-elle en lien avec notre constructeur?

```cpp
Planete(std::string nom, double rayon, double masse, double distanceSoleil);
```

Ah, voilà. Nous avons implémenté un **constructeur avec paramètres**. Ce faisant, nous avons désactivé le **constructeur par défaut**, qui lui est un **constructeur sans paramètre**.

Le problème, c'est que pour allouer un tableau d'objets, la classe concernée doit absolument posséder un constructeur sans paramètre. Sinon, le compilateur ne sait pas comment allouer la mémoire pour le tableau.

Mais quelle tragédie! Qu'allons donc nous faire? 😭

Surtout pas de panique! Nous allons tout simplement... 🥁 ajouter un constructeur sans paramètre!

```cpp
Planete();
```

> Oui, mais prof, on met quoi dans l'implémentation de notre constructeur sans paramètre? 🤔

On donne des valeurs par défaut à notre objet, tout simplement. Voici l'implémentation que je vous propose:

```cpp
Planete::Planete() {
    this->_nom = "(Planète sans nom)";
    this->_rayon = 0;
    this->_masse = 0;
    this->_distanceSoleil = 0;
}
```

Et voilà. Ainsi, à la création de notre tableau, le compilateur initialisera 8 planètes avec le **constructeur sans paramètre**. Ces planètes auront donc le nom `(Planète sans nom)` et leurs attributs numériques seront initialisés à 0. Ensuite, nous allons remplacer ces 8 planètes par celles que nous aurons instanciées à l'aide du **constructeur avec paramètres**.

Votre code devrait maintenant compiler. Si c'est bien le cas, modifiez votre `main` pour assigner les 8 planètes aux 8 emplacements du tableau. Utilisez le débogueur pour valider que tout fonctionne correctement.

## Étape 8

Maintenant que vous avez un tableau contenant les 8 planètes, vous devriez assez facilement pouvoir faire une boucle qui itère sur tout le tableau et appelle la méthode `afficher` de chaque planète. Pour rappel, voici le résultat visé:

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

**⚠️ Faites valider votre laboratoire 02-A par l'enseignant.**

## Laboratoire 02-B

La partie précédente vous a guidé étape par étape dans la création et l'utilisation de votre première classe, la classe `Planete`. Voyons maintenant si vous pouvez créer une deuxième classe simple par vous-même.

Votre mission, si vous l'acceptez (et je vous recommande fortement de l'accepter), est de créer une classe `Parabole` qui représente une équation sous la forme suivante:

$$
y = ax^2 + bx + c
$$

Votre classe doit posséder les attributs privés suivants:

* `_valA`
* `_valB`
* `_valC`

Ces attributs représentent respectivement les valeur de $a$, $b$ et $c$ dans l'équation.

> 🤔 Quels devraient être les types de ces attributs?

Elle doit aussi posséder deux constructeurs:

* Un constructeur sans paramètre
* Un constructeur avec trois paramètres (`valA`, `valB` et `valC`)

Le constructeur sans paramètre doit initialiser les paramètres de manière à ce que l'équation par défaut soit la suivante:

$$
y = x^2
$$

Finalement, votre classe doit posséder également les quatre méthodes suivantes:

* `double evaluerY(double x);`
* `std::string obtenirEquation();`
* `void afficher(std::ostream& sortie);`
* `void afficher();`

La méthode `evaluerY` prend en paramètre une valeur de `x` et calcule la valeur de `y` correspondante.

La méthode `obtenirEquation` retourne une chaîne de caractères correspondant à l'équation sous la forme `ax^2 + bx + c`, en remplaçant bien sûr `a`, `b` et `c` par les valeurs des attributs de l'objet.

> **Note:** pour concaténer un `double` à une `string`, vous pouvez d'abord convertir le `double` en `string` à l'aide de la fonction `std::to_string(double)`.

La méthode `afficher(std::ostream& sortie)` affiche l'équation à l'aide du `std::ostream` reçu en paramètre. Pour ce faire, elle appelle la méthode `obtenirEquation`.

La deuxième version de la méthode `afficher` appelle la première en lui passant `std::cout`, comme vous avez fait dans la première partie du laboratoire.

**Testez vos méthodes au fur et à mesure que vous les implémentez.**

Une fois que le tout est fonctionnel, utilisez votre classe pour créer un programme qui:

1. Demande à l'utilisateur les valeurs de $a$, $b$ et $c$
2. Instancie une `Parabole` à l'aide de ces valeurs
3. Affiche l'équation de la parabole
4. Demande à l'utilisateur la valeur de $x$
5. Affiche la valeur de $y$ correspondante

Voici un exemple de l'exécution attendue:

```text
Entrez la valeur de a: 14
Entrez la valeur de b: 21
Entrez la valeur de c: 12.7

Équation: 14.000000x^2 + 21.000000x + 12.700000

Entrez la valeur de x: 144
Valeur de y: 293341
```

**⚠️ Faites valider votre laboratoire 02-B par l'enseignant.**

## Laboratoire 02-C

Reprenez votre programme du **Laboratoire 01-C** avec la liste de températures.

Ce programme affiche un menu et valide le choix de l'utilisateur:

```text
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
Entrez un choix entre 1 et 6: 7
Votre choix est invalide.
Entrez un choix entre 1 et 6: 6

Au revoir!
```

Ne serait-il pas pratique de déplacer cette logique dans une classe `Menu`?

### Étape 1

Créez les nouveaux fichiers `Menu.h` et `Menu.cpp` dans votre projet.

Dans le fichier `Menu.h`, ajoutez la définition de classe suivante:

```cpp
class Menu {
private:
    std::string* _options;
    size_t _nombreOptions;
    bool _optionQuitter;
public:
    Menu();
    Menu(bool optionQuitter);
    ~Menu();

    void ajouterOption(std::string option);
    std::string obtenirChaine();
    int demanderChoix();
    bool estQuitter(int idOption);
};
```

Puis, dans le fichier `Menu.cpp`, ajoutez les implémentations vides ci-dessous. Vous allez les compléter dans les étapes ultérieures.

```cpp
Menu::Menu() {
}

Menu::Menu(bool optionQuitter) : Menu() {
}

Menu::~Menu() {
}

void Menu::ajouterOption(std::string option) {
}

std::string Menu::obtenirChaine() {
    return "";
}

int Menu::demanderChoix() {
    return 0;
}

bool Menu::estQuitter(int option) {
    return false;
}
```

Voici quelques détails sur le fonctionnement de notre classe:

* Le pointeur `_options` pointera sur un tableau contenant toutes les options disponibles dans le menu (à l'exception de l'option « Quitter »). Nous utilisons un pointeur, car nous ne savons pas d'avance combien d'options comprendra le menu (l'objectif étant de créer un menu réutilisable).
* `_nombreOptions` indiquera le nombre d'éléments contenus dans `_options`.
* `_optionQuitter` indiquera si le menu doit afficher une option "Quitter".

### Étape 2

Implémentez le constructeur sans paramètre de la classe. Celui-ci doit:

* Initialiser l'attribut `_options` à `nullptr`
* Initialiser l'attribut `_nombreOptions` à 0
* Initialiser l'attribut `_optionQuitter` à `false`

Testez dans votre `main` que vous êtes en mesure d'instancier un menu avec `Menu menu`.

### Étape 3

Implémentez le deuxième constructeur, qui prend un paramètre `optionQuitter`. Attardons-nous à un petit détail de l'implémentation vide que vous avez ajoutée précédemment dans votre `.cpp`:

```cpp
Menu::Menu(bool optionQuitter) : Menu() {
}
```

Remarquez le ` : Menu()` après la parenthèse fermante de la signature du constructeur.

Il indique au compilateur que le **constructeur avec paramètre** doit lui-même appeler le **constructeur sans paramètre** avant de faire quoique ce soit d'autre.

Ainsi, dans l'implémentation du **constructeur avec paramètre**, vous n'avez pas à initialiser les attributs `_options` et `_nombreOptions`, puisqu'ils sont déjà initialisés aux valeurs voulues par le **constructeur sans paramètre**!

![](./images/bob_leponge_reutilisation.jpg)

Voici donc la seule chose qu'il vous reste à faire dans le constructeur avec paramètre:

```cpp
Menu::Menu(bool optionQuitter) : Menu() {
    this->_optionQuitter = optionQuitter;
}
```

Dans votre `main`, remplacez votre instanciation précédente (`Menu menu`) par (`Menu menu(true)`). Utilisez le débogueur pour valider que `_optionQuitter` reçoit la bonne valeur.

### Étape 4

Puisque notre classe contient un pointeur (l'attribut `_options`) auquel elle allouera de la mémoire, elle doit impérativement implémenter un **destructeur** pour désallouer la mémoire de ce pointeur.

Ajoutez donc la ligne de code nécessaire au destructeur (`~Menu()`) pour désallouer le tableau pointé par `_options`.

### Étape 5

Implémentez maintenant la méthode `ajouterOption`. Celle-ci doit:

* Agrandir d'un emplacement le tableau `_options` (souvenez-vous des étapes suivies dans le laboratoire 1 pour agrandir un tableau)
* Insérer l'option reçue en paramètre à la fin du tableau
* Incrémenter l'attribut `_nombreOptions`

### Étape 6

Il est temps d'implémenter la méthode `obtenirChaine`. Cette méthode, au lieu d'afficher directement le menu à l'écran, doit **retourner une chaîne de caractères contenant le contenu à afficher**.

Pour ce faire, il vous est suggéré d'utiliser un objet de type `std::stringstream`, qui se trouve dans la librairie `sstream`. Un `std::stringstream` s'utilise de la même façon que `std::cout`, mais permet de produire une chaîne de caractères au lieu d'afficher du texte à l'écran.

Voici un exemple de programme qui utilise `std::stringstream` pour produire une chaîne de caractères contenant les chiffres de 0 à 9 séparés par des sauts de ligne:

```cpp
#include <iostream>
#include <sstream>

int main() {
    std::string chaine;
    std::stringstream flux;
    
    // Ajout du contenu au stringstream (flux)
    flux << "Les chiffres du système décimal:" << std::endl;
    for (int i = 0; i < 10; i++) {
        flux << i << std::endl;
    }
    
    /* 
    Génération de la chaîne de caractères contenant
    tout ce qui a été ajouté au flux
    */
    chaine = flux.str();

    /*
    `chaine` contient maintenant "Les chiffres du système décimal:"
    suivi d'un saut de ligne, puis des chiffres de 0 à 9 avec un
    saut de ligne entre chaque chiffre. Rien n'a encore été affiché
    à l'écran.
    */
    
    // Affichage de la chaîne
    std::cout << chaine;

    return 0;
}
```

Dans votre cas, vous voulez plutôt générer une chaîne de caractères contenant le menu au format suivant:

```cpp
MENU
====================
1. Afficher les températures en degrés Celsius
2. Afficher les températures en Kelvin
3. Calculer la température moyenne
4. Ajouter une température
5. Exporter les températures
6. Quitter
```

Il faut bien sûr que la chaîne contienne les options qui se trouvent dans l'attribut `_options`. De plus, il faut aussi ajouter une option "Quitter" **si et seulement si** l'attribut `_optionQuitter` vaut `true`.

Il est maintenant temps de tester le tout dans votre `main`. Pour ce faire, commencez par ajouter toutes les options au menu (sauf l'option « Quitter ») à l'aide de la méthode `ajouterOption`.

Ensuite, modifiez votre fonction `afficherMenu` des laboratoires précédents pour qu'elle reçoive le menu en paramètre, puis affiche la chaîne de caractères produite par sa méthode `obtenirChaine`. **ATTENTION:** il est essentiel que votre fonction `afficherMenu` reçoive le menu par référence, pour des raisons que nous verrons dans les chapitres ultérieurs.

```cpp
void afficherMenu(Menu& menu);
```

N'oubliez pas de modifier l'appel de la fonction `afficherMenu` dans le `main` afin de lui passer le menu.

Testez votre programme. Il devrait fonctionner comme avant. Si ce n'est pas le cas, corrigez votre code.

### Étape 7

Il est temps d'implémenter votre méthode `demanderChoix`. Cette méthode doit faire la même chose que votre ancienne fonction du même nom, mais elle doit utiliser les attributs de l'objet `Menu` pour valider le choix au lieu de prendre des paramètres `min` et `max`.

Modifiez ensuite votre `main` pour utiliser votre nouvelle méthode.

Testez votre programme. Il devrait fonctionner comme avant. Si ce n'est pas le cas, corrigez votre code.

### Étape 8

Implémentez finalement la méthode `estQuitter`. Cette méthode prend en paramètre l'indice d'une option du menu, et retourne un booléen indiquant si cet indice correspond à l'option « Quitter ». Si l'attribut `_optionQuitter` vaut `false`, il faut toujours retourner `false`.

Utilisez ensuite cette méthode dans la condition de la boucle principale du programme pour déterminer s'il faut quitter.

Testez votre programme. Il devrait fonctionner comme avant. Si ce n'est pas le cas, corrigez votre code.

**⚠️ Faites valider votre laboratoire 02-C par l'enseignant.**

> 🎉 Félicitations, vous avez complété votre premier laboratoire sur la programmation orientée objet!