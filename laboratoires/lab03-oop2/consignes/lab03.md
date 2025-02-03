# Laboratoire 03

## Objectif

Approfondir les notions de POO avec les concepts d'accesseurs et mutateurs, constructeur de copie et opérateur d'assignation. Nous allons également comprendre les concepts d'agrégations et de compositions.

## Le plan cartésien à N dimension

Nous allons développer une série de classes qui a pour but d'aider à la représentation informatique de `Point` et de `Forme`. On appelle un ensemble de fonction et/ou de classe sans exécutable une librairie.

> Dans le cadre du cours, nous n'allons pas créer de manière formelle la libraire, toutefois *Visual Studio* permet la création de projet de type librarie (bibliothèque) alors que d'autres IDE nécessite probablement la configuration adéquate du projet. Cela ne sera pas obligatoire dans le présent cours.

L'objectif est de créer l'ensemble de ces classes-ci.

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
    + double getDistance() const

    + std::string toString() const
}

class Triangle {
    - Point *_pointA
    
    - Triangle()
    - Triangle(Point a, Point b, Point c)
    + Triangle(const Triangle &point)
    + ~PoiTrianglent()

    + Triangle &operator=(cont Triangle &point)

    + double getAire() const
    + double estInterieur(Point point) const

    + bool estTriangleRectangle() const
    + bool estIsocele() const
    + bool estEquilaterale() const
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
    - Point *_pointA
    
    + Quadrilatere()
    + Quadrilatere(Point a, Point b, Point c, Point d)

    + double getAire() const
    + double estInterieur(Point point) const

    + bool estCarree() const
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

    + bool estCube() const
    + bool estPrismeRectangulaire() const
}

@enduml
```

### Classe Point

La classe `Point` doit permettre la création d'un point sur *N-dimension*. Chaque point *P* est décrit tel que :

$$
\begin{equation}
    P = \{{x_i} | x_i \in \mathbb{R}^N, i \in {0, 1, \dots N}\}
\end{equation}
$$

En d'autres mots, 

$$
\begin{equation}
    P = (x_0, x_1, \dots, x_N)
\end{equation}
$$

Voici les directives pour l'implémentation de votre classe `Point` :

* définir le nombre de dimension à la construction.
  * le constructeur par défaut défini le nombre de dimension à 2.
  * chaque dimension est initialisé à 0.0.
* configurer chaque valeur scalaire par dimension via `setDimension`.
* **ne pas faire** le constructeur avec un `Point` comme paramètre
* **ne pas faire** la ligne avec `operator=`
* faire les accesseurs `getCoordonnee` et `getDistance`
* méthode `toString` doit retourner `(x_0, x_1, ..., x_N)` sans saut de ligne.

Pour le calcul de la distance, nous avons deux instances `Point` définit tel que

$$
    P_0 = (x_{00}, x_{01}, \dots, x_{0N}) \\
    P_1 = (x_{10}, x_{11}, \dots, x_{1N})
$$

On calcul la distance selon :

$$
    D = \sqrt{\sum_{i=0}^N(x_{1i} - x_{0i})^2}
$$


### Scénario 1 - Instantier un Point avec un Point

1. Dans votre `main`, instantier un objet de la classe Point (`ancientPoint`) avec 3 comme nombre de dimensions.
2. Changer les valeurs de chaque dimension pour des valeurs différentes et non-nulle.
3. Instantier un nouveau Point tel que `Point nouveauPoint(ancientPoint);`.
4. Modifier la première dimension de votre `nouveauPoint` avec une valeur différente
5. Afficher les points `ancientPoint` et `nouveauPoint` dans votre `main`.

Avons-nous un problème ?

Nous n'avons pas défini de constructeur de copie. Celui-ci est définit par défaut et fait un *shalow copy* de notre objet, c'est-à-dire qu'il copie chaque attributs, même les pointeurs et leurs internes. On doit donc définir un constructeur de copie.

```
Point::Point(const Point &point) {
    // On mets les _nbDimension de this et point égaux

    // On aloue _nbDimensions cases pour _coordonnee

    // On copie les coordonnees de point dans this
}
```

Retester les mêmes étapes du scénario 1

### Scénario 2 - Assigner un Point à un Point

1. Dans votre `main`, instantier un objet de la classe Point (`ancientPoint`) avec 3 comme nombre de dimensions.
2. Changer les valeurs de chaque dimension pour des valeurs différentes et non-nulle.
3. Instantier un nouveau Point `nouveauPoint` avec 2 dimensions.
3. Changer les valeurs de `nouveauPoint` - doit avoir tous des valeurs différentes
3. Assigner `nouveauPoint` a `ancienPoint`
4. Modifier la première dimension de votre `nouveauPoint` avec une valeur différente
5. Afficher les points `ancientPoint` et `nouveauPoint` dans votre `main`.

Avons-nous un problème ?

L'assignation s'effectue via l'opérateur d'assignation `=`. Lorsque nous ne définissons pas son comportement, C++ en définie un par défaut. Cela pose problème car il va, de manière *stupide*, copier l'adresse du pointeur. Nos deux classes possède le même pointeur de dimensions. Pour définir le bon comportement, nous devons faire :

```
Point &Point::&operator=(const Point &point) {
    // Si les this et point pointe a la même place, retourner *this

    // Si les nbDimension de this et point sont égaux

    // alors on copie les coordonne de point dans this

    // sinon

    // on doit désalouer les coordonner de this

    // assigner le nombre de dimension de point à this

    // alouer un nouveau tableau de double avec la bonne quantité de case

    // copier les coordonner de point dans this

    // fin si

    // retourner this
}
```

Retester les mêmes étapes du scénario 2.

> Question ? Pourquoi l'`operator=` retourne une référence à lui-même ?

Vous avez maintenant l'ensemble de tous les outils requis pour gérer efficacement une classe qui utilise des pointeurs. En effet, pour chaque classe avec des pointeurs, vous devez **obligatoirement** définir :

* Un constructeur de copie ;
* L'opérateur d'assignation ;
* Un destructeur.

La stabilité de votre application C++ va grandement en dépendre.

## Forme à deux dimension

### Triangle

Voici les lignes directrices concernant l'implémentation de la classe `Triangle`.

* Vos constructeurs doivent s'assurer d'instantier 

---

À venir

**Équation de l'aire d'un triangle avec trois points**

Trois points en 2 dimensions définit :

$$
    P_0 = (x_{00}, x_{01}) \\
    P_1 = (x_{10}, x_{11}) \\
    P_2 = (x_{20}, x_{21})
$$

$$
A = 0.5 (|x_{00}(x_{11} - x_{21}) + x_{10}(x_{21} - x_{01}) + x_{20}(x_{01} - x_{11})|)
$$

Si *A* est égale à 0, ce n'est pas un triangle valide.

**Équations pour définir si un point est à l'intérieur d'un triangle**

Trois points en 2 dimensions définit :

$$
    P_0 = (x_{00}, x_{01}) \\
    P_1 = (x_{10}, x_{11}) \\
    P_2 = (x_{20}, x_{21})
$$

et un Point supplémentaire à valider :

$$ 
p = (x_0, x_1) 
$$

Ont doit faire trois produit croisée tel que :

$$ 
C_0(P_0, P_1, p) = (x_{10} - x_{00})(x_1 - x_{01}) - (x_{11} - x_{01})(x_0 - x_{00})
C_1(P_1, P_2, p) = (x_{20} - x_{10})(x_1 - x_{11}) - (x_{21} - x_{11})(x_0 - x_{10})
C_2(P_2, P_0, p) = (x_{00} - x_{20})(x_1 - x_{21}) - (x_{01} - x_{21})(x_0 - x_{20})
$$ 

Puis on s'assure que le signe de chaque C_x est le même.

**Équations pour définir si un triangle est un triangle rectangle**

$$
    P_0 = (x_{00}, x_{01}) \\
    P_1 = (x_{10}, x_{11}) \\
    P_2 = (x_{20}, x_{21})
$$

On définit les vecteurs suivants :

$$
    \vec{A} = (x_{10} - x_{00}, x_{11} - x_{01}) \\
    \vec{B} = (x_{20} - x_{10}, x_{21} - x_{11}) \\
    \vec{C} = (x_{00} - x_{20}, x_{01} - x_{21})
$$

Puis on fait les *dot product* suivant :

$$
    \vec{A} \dot \vec{C} = (x_{10} - x_{00})(x_{00} - x_{20}) + (x_{11} - x_{01})(x_{01} - x_{21}) \\
    \vec{A} \dot \vec{B} = (x_{10} - x_{00})(x_{20} - x_{10}) + (x_{11} - x_{01})(x_{21} - x_{11}) \\
    \vec{B} \dot \vec{C} = (x_{20} - x_{10})(x_{00} - x_{20}) + (x_{21} - x_{11})(x_{01} - x_{21})
$$

Si un de ces *dot products* est égale à 0, on a un triangle rectangle.
