# Laboratoire 03

## Objectif

Mettre en pratique les notions suivantes:

* L'implémentation et l'utilisation d'accesseurs et de mutateurs
* L'implémentation d'un constructeur de copie
* L'interprétation de [diagrammes de classes](https://fr.wikipedia.org/wiki/Diagramme_de_classes)
* Les relations entre les classes

## Parties

Ce laboratoire est divisé entre quatre parties:

* **Laboratoire 03-A**: amélioration de la classe `Planete` du Laboratoire 02-A et ajout d'une classe `SystemePlanetaire`
* **Laboratoire 03-B**: création de classes `Element` et `Isotope`
* **Laboratoire 03-C**: amélioration de la classe `Parabole` du Laboratoire 02-B et ajout d'une classe `Point`
* **Laboratoire 03-D**: évolution de la liste des températures à l'aide d'une nouvelle classe `ListeTemperatures`

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
    Planete* _planetes;
    size_t _nombrePlanetes;
public:
    SystemePlanetaire();
    SystemePlanetaire(const SystemePlanetaire& autreSysteme);
    ~SystemePlanetaire();

    void ajouterPlanete();

    size_t getNombrePlanetes();
    Planete getPlanete(size_t i) const;
    Planete getPlanete(std::string nom) const;
};
```

Vous devriez remarquer un certain nombre de choses par rapport à cette classe:

* Elle contient un pointeur de `Planete` et un nombre de planètes. On peut supposer qu'elle allouera dynamiquement un tableau de `Planete`.
* Elle contient une méthode `ajouterPlanete`. On peut supposer qu'elle fera agrandir le tableau, comme le faisait la méthode `ajouterOption` de la classe `Menu` du laboratoire précédent.
* Elle définit un constructeur de copie. Cela est essentiel puisqu'elle contient un pointeur. On veut éviter qu'une copie d'un `SystemePlanetaire` pointe sur le même tableau de `Planete` que le `SystemePlanetaire` d'origine.
* Elle définit un destructeur. Cela est nécessaire puisque la classe alloue de la mémoire dynamiquement.
* Elle définit deux accesseurs du même nom (`getPlanete`), et ceux-ci sont particuliers parce qu'ils prennent chacun un paramètre.
