# Laboratoire 05-B

## Objectif

On poursuit notre quête d'héritage et de polymophisme en ajoutant les concepts surcharge de méthode et méthode abstraite.

## Problème avec `Forme2D`

Récapitulons la situation. Nous avons deux classes filles `Triangle` et `Quadrilatere` qui hérite de `Forme2D`. Prenons le code suivant :

```cpp
Forme2D &Forme2D::operator=(const Forme2D &forme) {
    if (this == &forme) {
        return *this;
    }

    delete this->_points;
    this->_nbPoints = forme._nbPoints;
    for (size_t i = 0; i < this->_nbPoints) {
        this->_points[i] = forme._points[i];
    }

    return *this;
}
```

Nous pourrions avoir dans notre `main` :

```cpp

void assigner(Forme2D &cible, const Forme2D &source) {
    cible = source;
}

int main() {
    Triangle a;
    Quadrilatere b;

    assigner(a, b);

    std::cout << "Nombre de points : " << a.getNbPoint() << std::endl;

    return 0;
}
```

Ce code compilera sans problème. Toutefois, sémantiquement notre instance `a`, qui est un `Triangle`, contient 4 points et une nombre de points à 4. Cela pourra occasionné des problèmes logiques car `Triangle` n'a pas accès au méthodes `estCarré` et `estRectangle`.

Plusieurs approchent sont possible, mais nous allons utiliser le concept de fonction virtuelle pure.