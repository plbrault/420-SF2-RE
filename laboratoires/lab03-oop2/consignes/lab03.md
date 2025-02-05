# Laboratoire 03

## Objectif

Approfondir les notions de Programmation orientée objet avec les concepts d'accesseurs et mutateurs, constructeur de copie et opérateur d'assignation. Nous allons également comprendre les concepts d'agrégation et de composition. On vous encourage a faire valider chacune des parties.

## Partie 1 - Le tableau périodique des éléments

Implémentez les classes présentées ci-dessous. En plus des membres définis ici, vous devez également fournir **les accesseurs et mutateurs pour chaque attribut privé**. N'oubliez pas le requis pour être en mesure de créer un tableau d'objets d'une instance donnée.

```plantuml
Element *-- Isotope

@startuml
class Isotope {
    - std::string _nom
    - uint8_t _nbNeutron
    - double _occurence
    - bool _stable
    - double _demiVie
    - double _masse

    + Isotope(std::string nom, uint8_t nbNeutron, double occurence, double masse)
    + Isotope(std::string nom, uint8_t nbNeutron, double occurence, double demiVie, double masse)
}

class Element {
    - uint8_t _nbParticuleChargee
    - uint8_t _nbTrou
    - std::string _groupe
    - std::string _symbole
    - Isotope *_isotopes

    + Element(std::string symbole, uint8_t nbParticuleChargee, uint8_t nbTrou, std::string groupe)
    + void ajouterIsotope(const Isotope &)

    + bool aIsotopeStable()
}

@enduml
```

> Prenez note que `uint8_t` est un type de donnée fourni par la librairie `<cstdint>` qui permet de s'assurer de la taille en bits de notre entier. `u`spécifie `unsigned` (non signé), `int` signifie « entier », le 8 définit combien de bits nous avons, et `t` signifie `type`. Un `uint8` nous permet donc de représenter une valeur entre 0 et 255. Il existe aussi `uint16_t`, `uint32_t` et `uint64_t` ainsi que leurs versions signées, donc sans le `u`, comme `int8_t`, qui couvre la plage de -128 à 127.

Dans votre fonction `main`, instanciez un tableau d'éléments pour les 6 premiers éléments en vous assurant d'y inscrire les valeurs appropriées, et assurez-vous d'avoir au minimum un isotope par élément. Puis, générer la sortie suivante :

```
---------------
| He       18 |
| Helium      |
|             |
| 9         2 |
---------------
```

`He` est le symbol, `18` est le groupe, `Helium` est le nom, `9` est le nombre d'isotopes, et `2` le nombre de particules chargées (2 protons, 2 électrons).

## Partie 2 - Le plan cartésien à *n-1 dimensions*

Nous allons développer une série de classes ayant pour but d'aider à la représentation informatique de points (classe `Point`) et de formes (classe `Forme`). On appelle un ensemble de fonctions et/ou de classes sans exécutable une librairie.

> Dans le cadre du cours, nous n'allons pas créer de manière formelle la libraire, toutefois *Visual Studio* permet la création de projet de type librarie (bibliothèque) alors que d'autres IDE nécessitent la configuration adéquate du projet. Cela ne sera pas obligatoire dans le présent cours.

L'objectif est d'implémenter l'ensemble de ces classes au cours des laboratoires 3, 4 et 5, c'est-à-dire tout au long du prochain mois. Pour le présent laboratoire, on se concentre sur `Point` et sur `Triangle`.

```plantuml
@startuml

Triangle o-- Point
Cercle o-- Point
Quadrilatere o-- Point
Sphere o-- Point
Hexahedron o-- Point
Hexahedron <-- Quadrilatere


class Point {
    - double *_dimensions
    - size_t _nbDimensions

    + Point()
    + Point(size_t dimension)
    + Point(const Point &point)
    + ~Point()

    + Point &operator=(cont Point &point)

    + void setCoordonnee(size_t dimension, double valeur)

    + double getCoordonnee(size_t dimension) const
    + double getDistance(const Point &point) const

    + std::string toString() const
}

class Triangle {
    - Point *_points
    
    - Triangle()
    - Triangle(Point a, Point b, Point c)
    + Triangle(const Triangle &triangle)
    + ~PoiTrianglent()

    + Triangle &operator=(cont Triangle &triangle)

    + double getAire() const
    + double estInterieur(Point point) const
    + bool estValide() const

    + bool estTriangleRectangle() const
    + bool estIsocele() const
    + bool estEquilateral() const
}

class Cercle {
    - Point _centre
    - double _radius

    + Cercle()
    + Cercle(Point centre, double radius)

    + double getAire() const
    + double estInterieur(Point point) const
}

class Quadrilatere {
    - Point *_points
    
    + Quadrilatere()
    + Quadrilatere(Point a, Point b, Point c, Point d)

    + double getAire() const
    + double estInterieur(Point point) const
    + bool estValide() const

    + bool estCarre() const
    + bool estRectangle() const
}

class Sphere {
    - Point _centre
    - double radius

    + Sphere()
    + Sphere(Point centre, double radius)

    + double getAire() const
    + double getVolume() const
    + double estInterieur(Point point) const
}

class Hexahedron {
    - Point *_points
    
    + Hexahedron()
    + Hexahedron(Quadrilatere 1, Quadrilatere 2)

    + double getAire() const
    + double getVolume() const
    + double estInterieur(Point point) const
    + bool estValide() const

    + bool estCube() const
    + bool estPrismeRectangulaire() const
}

@enduml
```

### Classe Point

La classe `Point` doit permettre la création d'un point sur *n-dimension*. Chaque point `P` est décrit tel que :

$$
\begin{equation}
    P = (x_0, x_1, \dots, x_{n-1})
\end{equation}
$$

Voici les directives pour l'implémentation de votre classe `Point` :

* définir le nombre de dimensions à la construction.
  * le constructeur par défaut définit le nombre de dimensions à 2.
  * chaque dimension est initialisée à la valeur `0.0`.
* configurer chaque valeur scalaire par dimension via `setDimension`.
* **ne pas créer** le constructeur avec un `Point` comme paramètre.
* **ne pas créer** la méthode `operator=`.
* faire les accesseurs `getCoordonnee` et `getDistance`.
* une méthode `toString` doit retourner `(x_0, x_1, ..., x_n)` sans saut de ligne.

Pour le calcul de la distance, prenons deux instances `Point` définies tel que

$$
    P_0 = (x_{00}, x_{01}, \dots, x_{0n-1}) \\
    P_1 = (x_{10}, x_{11}, \dots, x_{1n-1})
$$

On calcule la distance selon :

$$
    D = \sqrt{\sum_{i=0}^{n-1}(x_{1i} - x_{0i})^2}
$$


#### Scénario 1 - Instancier un Point avec un Point

1. Dans votre `main`, instanciez un objet de la classe `Point` nommé `ancienPoint` avec la valeur `3` comme nombre de dimensions.
2. Changez les valeurs de chaque dimension pour des valeurs différentes et non-nulles.
3. Instanciez un nouveau Point de cette façon: `Point nouveauPoint(ancienPoint);`.
4. Modifiez la première dimension de votre `nouveauPoint` avec une valeur différente.
5. Affichez les points `ancienPoint` et `nouveauPoint` dans votre `main`.

Exécutez votre code. Voyez-vous un problème?

Nous n'avons pas défini de constructeur de copie. Celui-ci est défini par défaut et fait un *shallow copy* de notre objet, c'est-à-dire qu'il copie la valeur de chaque attribut, même les adresses référées par les pointeurs. On doit donc définir un constructeur de copie.

```
Point::Point(const Point &point) {
    // On copie le nomre de dimensions de `point` vers `this`

    // On aloue un tableau de _nbDimensions emplacements pour _coordonnee

    // On copie les coordonnées de `point` vers `this`
}
```

Retestez les mêmes étapes du scénario 1.

#### Scénario 2 - Assigner un Point à un Point

1. Dans votre `main`, instanciez un objet de la classe `Point` nommé `ancienPoint` avec la valeur `3` comme nombre de dimensions.
2. Changez les valeurs de chaque dimension pour des valeurs différentes et non-nulles.
3. Instanciez un nouveau Point `nouveauPoint` avec 2 dimensions.
3. Changez les valeurs de chaque dimension pour des valeurs différentes et non-nulles.
3. Assignez `nouveauPoint` à `ancienPoint`.
    * `ancienPoint = nouveauPoint`
4. Modifiez la première dimension de votre `nouveauPoint` avec une valeur différente.
5. Affichez les points `ancienPoint` et `nouveauPoint` dans votre `main`.

Exécutez votre code. Voyez-vous un problème ?

L'assignation s'effectue via l'opérateur d'assignation `=`. Lorsque nous ne définissons pas son comportement, C++ en définit un par défaut. Cela pose problème car il va, de manière *stupide*, copier l'adresse du pointeur. Nos deux objets possèdent le même pointeur de dimensions. Pour définir le bon comportement, nous devons faire :

```
Point &Point::&operator=(const Point &point) {
    // Si `this` et `point` pointent à la même adresse:
    
        // retourner *this

    // Si les nbDimension de `this` et `point` sont égaux:

        // alors on copie les coordonnées de `point` dans `this`

    // sinon:

        // on doit désallouer les coordonnées de `this`

        // assigner le nombre de dimensions de `point` à `this`

        // alouer un nouveau tableau de double avec la bonne quantité d'emplacements

        // copier les coordonnées de `point` dans `this`

    // retourner `this`
}
```

Retester les mêmes étapes du scénario 2.

> Question ? Pourquoi l'`operator=` retourne une référence à lui-même ?

Vous avez maintenant l'ensemble des outils requis pour gérer efficacement une classe qui utilise des pointeurs. En effet, pour chaque classe avec des pointeurs, il faut **obligatoirement** définir :

* Un constructeur de copie ;
* L'opérateur d'assignation ;
* Un destructeur.

La stabilité de votre application C++ va grandement en dépendre.

### Forme à deux dimensions

#### Triangle

Voici les lignes directrices concernant l'implémentation de la classe `Triangle`.

* Vos constructeurs doivent s'assurer d'allouer 3 instances de `Point`
* Vos constructeurs doivent s'assurer que les `Point` sont seulement en 2D
* Assurez-vous de désallouer vos pointeurs dans le destructeur
* Assurez-vous que le constructeur de copie ne fasse pas de *shallow copy*
* Assurez-vous que l'opérateur d'assignation ne fasse pas de *shallow copy*

#### Méthode `getAire`

La méthode `getAire` doit calculer puis retourner l'aire du triangle.

Soit trois points `P_0`, `P_1` et `P_2` définis comme ceci :

$$
    P_0 = (x_{00}, x_{01}) \\
    P_1 = (x_{10}, x_{11}) \\
    P_2 = (x_{20}, x_{21})
$$

L'aire de notre triangle se calcule selon l'expression suivante :

$$
A = 0.5 (|x_{00}(x_{11} - x_{21}) + x_{10}(x_{21} - x_{01}) + x_{20}(x_{01} - x_{11})|)
$$

> Observation : si la parenthèse est 0, l'aire est 0.

> Note : Si l'aire est 0, le triangle n'est pas valide.

* Tester si le triangle est valide ou non

#### Méthode `estInterieur`

La méthode `estInterieur` doit tester si le point reçu en paramètre est à l'intérieur du Triangle.

Soit trois points `P_0`, `P_1` et `P_2` tels que définis précédement et un point `p` défini :

$$
p = (x_0, x_1)
$$

On doit faire le produit croisé de toutes les combinaisons de vecteurs créées par P_0 et P_1 sur P_0 et p, P_1 et P_2 sur sur P_1 et p, etc.

$$ 
C_0(P_0, P_1, p) = (x_{10} - x_{00})(x_1 - x_{01}) - (x_{11} - x_{01})(x_0 - x_{00}) \\
C_1(P_1, P_2, p) = (x_{20} - x_{10})(x_1 - x_{11}) - (x_{21} - x_{11})(x_0 - x_{10}) \\
C_2(P_2, P_0, p) = (x_{00} - x_{20})(x_1 - x_{21}) - (x_{01} - x_{21})(x_0 - x_{20})
$$ 

> Observation : Il est tout à fait possible de se créer une méthode privée pour ce calcul.

Une fois les produits croisés complétés, il faut s'assurer qu'ils ont tous le même signe (tous négatif ou tous positif) pour que le point soit à l'intérieur.

#### Méthode `estTriangleRectangle`

Prenons la définition de trois points `P_0`, `P_1` et `P_2` mentionnée précédemment. On définit des vecteurs `A`, `B` et `C` suivants :

$$
    \vec{u} = \overrightarrow{P_0P_1} = (x_{10} - x_{00}, x_{11} - x_{01}) \\
    \vec{v} = \overrightarrow{P_1P_2} = (x_{20} - x_{10}, x_{21} - x_{11}) \\
    \vec{w} = \overrightarrow{P_2P_0} = (x_{00} - x_{20}, x_{01} - x_{21})
$$

> Observation : Nous pourrions probablement avoir une méthode quelque part pour ça ? Où ? Que retourne-t-elle ?

Par la suite on veut faire le produit croisée suivant :

$$
    \vec{u} \cdot \vec{w} = (x_{10} - x_{00})(x_{00} - x_{20}) + (x_{11} - x_{01})(x_{01} - x_{21}) \\
    \vec{u} \cdot \vec{v} = (x_{10} - x_{00})(x_{20} - x_{10}) + (x_{11} - x_{01})(x_{21} - x_{11}) \\
    \vec{v} \cdot \vec{w} = (x_{20} - x_{10})(x_{00} - x_{20}) + (x_{21} - x_{11})(x_{01} - x_{21})
$$

## Partie 3 - Retour sur la table périodique des éléments

Maintenant que vous avez vu les requis nécessaire à suivre lorsqu'une classe à un pointeur, assurez-vous de respecter les obligations qu'un pointeur requiert dans une classe.
