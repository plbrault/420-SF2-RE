# Laboratoire 03

## Objectif

Mettre en pratique les notions suivantes:

* L'implémentation et l'utilisation d'accesseurs et de mutateurs
* L'implémentation d'un constructeur de copie
* L'interprétation de [diagrammes de classes](https://fr.wikipedia.org/wiki/Diagramme_de_classes)
* Les relations entre les classes

## Parties

Ce laboratoire comprend deux parties:

* **Laboratoire 03-A**: amélioration de la classe `Planete` du Laboratoire 02-A et ajout d'une classe `SystemePlanetaire`
* **Laboratoire 03-B**: le tableau périodique des éléments (classes `Element` et `Isotope`)

## Laboratoire 03-A

Dans cette première partie, nous allons faire évoluer la classe `Planete` du Laboratoire 02-A. Nous allons d'abord ajouter des accesseurs (*getters*) et des mutateurs (*setters*) à cette classe, puis nous allons ajouter une nouvelle classe `SystemePlanetaire` en relation avec la classe `Planete`.

Reprenez donc votre programme du Laboratoire 02-A.

### Étape 1

Commencez par renommer l'attribut `_distanceSoleil` de votre classe pour `_distanceEtoile`, afin de la rendre un peu plus générique, et donc plus réutilisable. Cela implique d'effectuer des changements à quelques endroits:

* Le nom de l'attribut dans la définition de la classe
* Le nom du paramètre dans le constructeur
* Le nom de l'attribut dans le code des méthodes

Assurez-vous que tout fonctionne correctement. Le résultat de votre programme ne devrait normalement pas avoir changé.

### Étape 2

Ajoutons un premier accesseur (*getter*) à votre classe, soit la méthode `getNom`. Voici la signature de cette méthode:

```cpp
std::string getNom() const;
```

Remarquez bien le **const** à la fin de la signature. Celui-ci indique qu'il s'agit d'une **méthode constante**, c'est-à-dire qu'elle ne modifie aucun attribut de l'objet. C'est généralement le cas pour les accesseurs.

Implémentez la méthode. Elle doit simplement retourner la valeur de l'attribut `_nom` de la planète.

Pour tester votre accesseur, mettez en commentaire le corps actuel de la boucle `for` de votre `main`, et remplacez-le par:

```cpp
std::cout << systemeSolaire[i].getNom() << std::endl;
```

Exécutez votre programme. Son résultat devrait maintenant ressembler à ceci:

```text
=== PLANÈTES DU SYSTÈME SOLAIRE ===
===================================

Mercure
Vénus
Terre
Mars
Jupiter
Saturne
Uranus
Neptune
```

### Étape 3

Ajoutez les accesseurs suivants à votre classe `Planete`:

* `getRayon`
* `getMasse`
* `getDistanceEtoile`

N'oubliez pas les `const`!

Testez bien vos nouvelles méthodes dans votre `main` avant de poursuivre.

### Étape 4

Il est maintenant temps d'ajouter un premier mutateur (*setter*). Voici la signature du mutateur de nom:

```cpp
void setNom(std::string nom);
```

Remarquez cette fois-ci l'absence de **const**. C'est normal, car par définition, un mutateur modifie un attribut de l'objet sur lequel il est appelé.

Ajoutez l'implémentation. Celle-ci doit prendre le nom reçu en paramètre et l'assigner à l'attribut `_nom`.

Faites la même chose avec les mutateurs suivants:

* `setRayon`
* `setMasse`
* `setDistanceEtoile`

Afin de bien tester vos mutateurs, retirez du `main` la déclaration des planètes `mercure`, `venus`, etc, et remplacez l'initialisation de votre tableau `systemeSolaire` par ceci:

```cpp
Planete systemeSolaire[8];

systemeSolaire[0].setNom("Mercure");
systemeSolaire[0].setRayon(2439000);
systemeSolaire[0].setMasse(3.301e23);
systemeSolaire[0].setDistanceEtoile(5.79e7);

systemeSolaire[1].setNom("Vénus");
systemeSolaire[1].setRayon(6052000);
systemeSolaire[1].setMasse(4.867e24);
systemeSolaire[1].setDistanceEtoile(1.082e8);

systemeSolaire[2].setNom("Terre");
systemeSolaire[2].setRayon(6371000);
systemeSolaire[2].setMasse(5.972e24);
systemeSolaire[2].setDistanceEtoile(1.496e8);

systemeSolaire[3].setNom("Mars");
systemeSolaire[3].setRayon(3390000);
systemeSolaire[3].setMasse(6.39e23);
systemeSolaire[3].setDistanceEtoile(2.279e8);

systemeSolaire[4].setNom("Jupiter");
systemeSolaire[4].setRayon(69911000);
systemeSolaire[4].setMasse(1.898e27);
systemeSolaire[4].setDistanceEtoile(7.785e8);

systemeSolaire[5].setNom("Saturne");
systemeSolaire[5].setRayon(58232000);
systemeSolaire[5].setMasse(5.683e26);
systemeSolaire[5].setDistanceEtoile(1.433e9);

systemeSolaire[6].setNom("Uranus");
systemeSolaire[6].setRayon(25362000);
systemeSolaire[6].setMasse(8.681e25);
systemeSolaire[6].setDistanceEtoile(2.877e9);

systemeSolaire[7].setNom("Neptune");
systemeSolaire[7].setRayon(24622000);
systemeSolaire[7].setMasse(1.024e26);
systemeSolaire[7].setDistanceEtoile(4.503e9);
```

Vous avez peut-être l'impression que ce n'est pas une amélioration, puisqu'on semble avoir complexifié le code pour obtenir le même résultat qu'avant. Ce n'est pas faux, mais au moins vous avez maintenant du code qui teste vos mutateurs.

> 🤔 **Qu'est-ce qui se trouve dans les attributs des 8 planètes avant l'appel des mutateurs?**

La réponse est très simple en fait: quand on instancie un objet sans appeler son **constructeur avec paramètres**, c'est le **constructeur sans paramètre** qui est appelé. C'est le cas lorsqu'on déclare un tableau de `Planete` en allocation statique. Ainsi, tout de suite après l'exécution de la ligne `Planete systemeSolaire[8];`, on a un tableau de 8 planètes avec le nom `"(Planète inconnue)"` et la valeur `0` pour les trois autres attributs. C'est ce que vous observerez si vous utilisez le débogueur pour vérifier la valeur des attributs à ce moment.

> 🧐 Souvenez-vous: pour pouvoir instancier un tableau d'objets, il faut impérativement que la classe correspondante ait un constructeur sans paramètre!

Pour tester le tout correctement, retirez le code que vous avez ajouté dans la boucle du `main` à l'étape précédente, puis décommentez l'ancien code qui utilisait la méthode `afficher`. Le résultat d'origine devrait être de retour.

### Étape 5

Présentement, vos mutateurs se contentent d'insérer les valeurs reçues dans les attributs correspondant. Éventuellement, nous améliorerons nos mutateurs afin qu'ils valident la donnée reçue avant de modifier la valeur de l'attribut.

Pour cette raison, il serait judicieux de modifier le **constructeur avec paramètres** afin qu'il appelle les mutateurs au lieu d'affecter les valeurs aux attributs directement. Ainsi, le jour où nous ajouterons du code de validation dans nos mutateurs, nous n'aurons pas besoin d'ajouter ce même code dans le constructeur.

![](./images/bob_leponge_reutilisation.jpg)

Modifiez donc votre constructeur de la manière suivante:

```cpp
Planete::Planete(std::string nom, double rayon, double masse, double distanceEtoile) {
    this->setNom(nom);
    this->setRayon(rayon);
    this->setMasse(masse);
    this->setDistanceEtoile(distanceEtoile);
}
```

Il n'est pas obligatoire de faire la même chose dans le constructeur sans paramètre, puisque les valeurs qu'il affecte aux attributs sont forcément valides. Il n'y aurait cependant rien de mal à le faire quand même.

Testez votre constructeur modifié avant de poursuivre.

### Étape 6

Vous souvenez-vous de la méthode `calculerGraviteSurface`?

Celle-ci calcule une valeur basée sur les attributs de l'objet, puis la retourne.

Formellement, cette méthode n'est pas un accesseur (*getter*), puisqu'elle ne retourne pas la valeur d'un attribut de l'objet.

Du point de vue de l'utilisateur de la classe cependant, cette méthode ressemble beaucoup à un accesseur: elle retourne une valeur, **et ne modifie aucun attribut de l'objet**.

Il serait donc très intuitif de voir cette méthode comme un accesseur, même s'il n'en est pas techniquement un. En fait, l'utilisateur de la classe n'a aucunement besoin de savoir que cette méthode n'est pas un accesseur. En ce qui le concerne, la méthode *agit* comme un accesseur. Pour autant qu'il sache, la gravité de surface pourrait tout aussi bien être un attribut de l'objet. Voilà toute la distinction entre l'**interface** (ce que l'utilisateur de la classe voit) et l'**implémentation** (le fonctionnement interne de la classe).

Ainsi, puisqu'il serait intuitif pour l'utilisateur de penser que cette méthode est un accesseur, nous allons la « déguiser » en accesseur. Pour ce faire, renommez la méthode en `getGraviteSurface`. N'oubliez pas d'ajouter le modificateur `const`!

Effectuez les autres changements nécessaires dans votre code. Validez que tout fonctionne toujours.

### Étape 7

Lors des étapes précédentes, vous avez utilisé le modificateur `const` pour chacune des méthodes suivantes:

* `getNom`
* `getRayon`
* `getMasse`
* `getDistanceEtoile`
* `getGraviteSurface`

Les mutateurs ne prennent pas de `const` puisqu'ils modifient des attributs de l'objet.

Cela dit, il reste encore deux méthodes auxquelles nous devrions ajouter `const`:

* `void afficher(std::ostream &sortie)`
* `void afficher()`

En effet, bien que ces deux méthodes produisent des effets de bord (elles écrivent en console), elles ne modifient aucunement l'objet `Planete`. Il faut donc leur ajouter `const`!

Faites la modification et assurez-vous que votre code compile toujours.

### Étape 8

Bon, laissons de côté la classe `Planete` pour le moment. Et si on s'amusait maintenant à créer une autre classe qui aurait pour but de représenter un ensemble de planètes?

Et oui, j'ai nommé la classe `SystemePlanetaire`! Un système planétaire contient plusieurs planètes gravitant autour d'une étoile. Le système solaire pourrait donc être représenté par une instance de la classe `SystemePlanetaire`.

Voici la définition de la classe `SystemePlanetaire`:

```cpp
class SystemePlanetaire {
private:
    std::string _nom;
    Planete* _planetes;
    size_t _nombrePlanetes;
    size_t _capacitePlanetes;
public:
    SystemePlanetaire();
    SystemePlanetaire(std::string nom);
    SystemePlanetaire(const SystemePlanetaire& autreSysteme);
    ~SystemePlanetaire();

    void ajouterPlanete(Planete planete);
    void afficher(std::ostream& sortie) const;
    void afficher() const;

    std::string getNom() const;
    size_t getNombrePlanetes() const;
    Planete* getPlanete(size_t indice) const;
    Planete* getPlanete(std::string nom) const;

    void setNom(std::string nom);
};
```

Vous devriez remarquer un certain nombre de choses par rapport à cette classe:

* Elle contient un pointeur de `Planete` et un attribut `_nombrePlanetes`. On peut supposer qu'elle allouera dynamiquement un tableau de `Planete`.
* Elle contient aussi un attribut `_capacitePlanetes`. À quoi sert cet attribut? Nous y reviendrons.
* Elle contient une méthode `ajouterPlanete`. On peut supposer qu'elle fera agrandir le tableau, comme le faisait la méthode `ajouterOption` de la classe `Menu` du laboratoire précédent.
* Elle définit un constructeur de copie. Cela est essentiel puisqu'elle contient un pointeur. On veut éviter qu'une copie d'un `SystemePlanetaire` pointe sur le même tableau de `Planete` que le `SystemePlanetaire` d'origine.
* Elle définit un destructeur. Cela est nécessaire puisque la classe alloue de la mémoire dynamiquement.
* Elle définit plusieurs accesseurs (*getters*), dont deux qui sont particuliers parce qu'ils prennent chacun un paramètre. Ces deux accesseurs ont par ailleurs le même nom.
* Elle définit un seul mutateur (*setter*), soit pour le nom. Il ferait peu de sens de définir des mutateurs pour les autres attributs, qui sont gérés à l'interne par la classe.

On est donc en présence d'une classe qui gère un tableau dynamique d'instances d'une autre classe. La taille de ce tableau varie d'un système planétaire à l'autre.

Revenons à l'attribut `_capacitePlanetes`. À quoi peut-il bien servir?

Voyez-vous, jusqu'à maintenant, nous avons géré les tableaux dynamiques en augmentant leur taille de 1 à chaque ajout. Cela est peu efficace, puisqu'à chaque agrandissement, il faut allouer un nouveau tableau et recopier un par un chacun des éléments de l'ancien tableau vers le nouveau tableau. Ainsi, pour ajouter 1 milliard d'éléments à un tableau, il faudrait effectuer  $5 \times 10^{17}$ opérations de copie!

En programmation, il faut souvent faire un compromis entre la mémoire et le temps. Jusqu'à maintenant, nous avons géré les tableaux dynamiques en minimisant l'utilisation de la mémoire: nos tableaux ont toujours contenu exactement le nombre d'éléments dont nous avions besoin. Cette façon de faire est cependant coûteuse en temps, vu la nécessité de recopier tout le tableau chaque fois qu'on ajoute un élément. Cette fois-ci, nous allons faire un compromis consistant à utiliser un peu plus de mémoire que nécessaire, afin de limiter les opérations de copie du tableau à une fois de temps en temps.

Voici l'approche que nous utiliserons:

1) Au lieu d'initialiser le pointeur à `nullptr`, le constructeur allouera immédiatement un tableau de 2 `Planete`.
2) La méthode `ajouterPlanete` vérifiera d'abord s'il reste de la place dans le tableau. Si ce n'est pas le cas, elle allouera un nouveau tableau **deux fois plus grand** avant d'y insérer la planète.

Ainsi, les opérations d'allocation et de copie ne seront nécessaires que lors de l'ajout d'une troisième planète, puis d'une cinquième, puis d'une neuvième, puis d'une dix-septième, puis d'une trente-troisième, et ainsi de suite. Notre code sera beaucoup plus efficace de cette manière, même s'il utilisera le plus souvent « trop » de mémoire pour ses besoins.

Pour ce faire, nous devons faire la ditinction entre la **capacité du tableau** (le nombre d'emplacements alloués en mémoire) et la **taille du tableau** (le nombre d'éléments utiles présents dans le tableau). Dans notre classe, l'attribut `_nombrePlanetes` correspond à la taille, et `_capacitePlanetes` à la capacité.

Avec tout cela en tête, implémentez le **constructeur sans paramètre**. Celui-ci doit:

* Initialiser à 2 la **capacité** du tableau (`_capacitePlanetes`)
* Initialiser à 0 la **taille** du tableau (`_nombrePlanetes`)
* Allouer un tableau de `_capacitePlanetes` et l'assigner à `_planetes`

Implémentez ensuite le **constructeur avec paramètre**, qui prend seulement un paramètre `nom`. Celui-ci doit:

* Appeler le constructeur sans paramètre (retournez voir votre constructeur avec paramètre de `Menu` pour vous rappeler comment faire)
* Affecter le nom reçu à l'attribut `_nom`

Vous devez aussi implémenter le destructeur, qui désalloue le tableau `_planetes`.

Instanciez deux `SystemePlanetaire` dans votre `main` en utilisant les deux versions du constructeur, et vérifiez à l'aide du débogueur qu'ils reçoivent les bonnes valeurs d'attributs.

## Étape 9

Implémentez maintenant la méthode `ajouterPlanete`. Celle-ci prend un objet `Planete` en paramètre.

Voici pour rappel le fonctionnement attendu de cette méthode:

* S'il n'y a plus de place dans le tableau (autrement dit, si sa taille est égale à sa capacité), doubler la capacité du tableau.
* Ajouter la planète à l'endroit approprié dans le tableau et incrémenter la taille.

Pour pouvoir vérifier que votre méthode fonctionne correctement, implémentez aussi les deux versions de la méthode `afficher`. Celle-ci doit d'abord afficher le nom du système planétaire, suivi d'un « : » puis d'une ligne vide, et appeler ensuite la méthode « afficher » de chacune des planètes du système planétaire, avec une ligne vide entre chaque planète.

Voici du code à utiliser dans votre `main` pour tester vos deux méthodes:

```cpp
SystemePlanetaire systemeSolaire("Système solaire");

systemeSolaire.ajouterPlanete(Planete("Mercure", 2439000, 3.301e23, 5.79e7));
systemeSolaire.ajouterPlanete(Planete("Vénus", 6052000, 4.867e24, 1.082e8));
systemeSolaire.ajouterPlanete(Planete("Terre", 6371000, 5.972e24, 1.496e8));
systemeSolaire.ajouterPlanete(Planete("Mars", 3390000, 6.39e23, 2.279e8));
systemeSolaire.ajouterPlanete(Planete("Jupiter", 69911000, 1.898e27, 7.785e8));
systemeSolaire.ajouterPlanete(Planete("Saturne", 58232000, 5.683e26, 1.433e9));
systemeSolaire.ajouterPlanete(Planete("Uranus", 25362000, 8.681e25, 2.877e9));
systemeSolaire.ajouterPlanete(Planete("Neptune", 24622000, 1.024e26, 4.503e9));

systemeSolaire.afficher();
```

Et voici le résultat attendu:

```text
Système solaire:

Planète Mercure:
 - Rayon: 2.439e+06 m
 - Masse: 3.301e+23 kg
 - Distance de l'étoile: 5.79e+07
 - Gravité de surface: 3.70363 m/s^2

Planète Vénus:
 - Rayon: 6.052e+06 m
 - Masse: 4.867e+24 kg
 - Distance de l'étoile: 1.082e+08
 - Gravité de surface: 8.86889 m/s^2

Planète Terre:
 - Rayon: 6.371e+06 m
 - Masse: 5.972e+24 kg
 - Distance de l'étoile: 1.496e+08
 - Gravité de surface: 9.81997 m/s^2

Planète Mars:
 - Rayon: 3.39e+06 m
 - Masse: 6.39e+23 kg
 - Distance de l'étoile: 2.279e+08
 - Gravité de surface: 3.71114 m/s^2

Planète Jupiter:
 - Rayon: 6.9911e+07 m
 - Masse: 1.898e+27 kg
 - Distance de l'étoile: 7.785e+08
 - Gravité de surface: 25.9186 m/s^2

Planète Saturne:
 - Rayon: 5.8232e+07 m
 - Masse: 5.683e+26 kg
 - Distance de l'étoile: 1.433e+09
 - Gravité de surface: 11.1856 m/s^2

Planète Uranus:
 - Rayon: 2.5362e+07 m
 - Masse: 8.681e+25 kg
 - Distance de l'étoile: 2.877e+09
 - Gravité de surface: 9.00759 m/s^2

Planète Neptune:
 - Rayon: 2.4622e+07 m
 - Masse: 1.024e+26 kg
 - Distance de l'étoile: 4.503e+09
 - Gravité de surface: 11.2735 m/s^2
```

### Étape 10

Le temps est venu d'implémenter le constructeur de copie! Ce constructeur prend en paramètre une instance de `SystemePlanetaire`, et en crée une copie.

**Le plus important pour le constructeur de copie est de bien copier les planètes**. Il ne faut surtout pas faire `this->_planetes = autreSysteme._planetes`. On veut plutôt faire cela:

1. Allouer un nouveau tableau avec la même capacité que celui d'`autreSysteme` et assigner son adresse à `this->_planetes`
2. Copier un par un les planètes d'`autreSysteme` vers ce nouveau tableau

Pour ce qui est des autres attributs (`_nom`, `_nombrePlanetes`, `_capacitePlanetes`), ceux-ci peuvent être copiés tels quels, puisqu'ils ne sont pas des pointeurs.

Pour tester le fonctionnement de votre constructeur de copie, ajouter le code suivant **à la fin** de votre `main`:

```cpp
// Créer une copie du système solaire en allocation statique
SystemePlanetaire copie1(systemeSolaire);

// Créer une deuxième copie du système solaire en allocation dynamique
SystemePlanetaire* copie2 = new SystemePlanetaire(copie1);

// Désallouer la deuxième copie
// Si le constructeur de copie est implémenté correctement, les autres
// copies ne seront pas affectées
delete copie2;

// Renommer la copie
copie1.setNom("Système solaire (copie)");

// Afficher la copie
copie1.afficher();
```

Si votre implémentation est correcte, vous verrez maintenant la copie du système solaire s'afficher à la suite de l'original.

### Étape 11

Implémentez le mutateur `setNom`. Testez-le dans votre `main` en remplaçant l'initialisation de `systemeSolaire` de cette façon:

```cpp
SystemePlanetaire systemeSolaire;
systemeSolaire.setNom("Système solaire");
```

### Étape 12

Implémentez `getNom` et `getNombrePlanetes`. Testez ces deux méthodes avant de continuer. Avec l'objet `systemeSolaire`, elles devraient retourner respectivement `"Système solaire"` et `8`.

### Étape 13

Nous en sommes maintenant à implémenter l'accesseur `Planete* getPlanete(size_t indice) const`. Celui-ci prend un paramètre, car il retourne l'**adresse** d'une planète en particulier (celle à l'indice `indice`), et non pas du tableau de planètes. Si l'indice est invalide, la méthode retourne `nullptr`.

Voici une ligne de code vous permettant de tester votre méthode:

```cpp
std::cout << "Affichage de la planète à l'indice 2:" << std::endl;
systemeSolaire.getPlanete(2)->afficher();
```
