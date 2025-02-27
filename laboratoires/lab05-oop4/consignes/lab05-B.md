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
int main() {
    Triangle a;
    Quadrilatere b;

    a = b;

    return 0;
}
```

Ce code compilera sans problème. Toutefois, sémantiquement notre instance `a`, qui est un `Triangle`, contient 4 points et une nombre de points à 4. Cela pourra occasionné des problèmes logiques car `Triangle` n'a pas accès au méthodes `estCarré` et `estRectangle`.

Une des solution sera d'utiliser une méthode abstraite. Il s'agit d'une méthode dans une classe mère qui ne sera pas implémenter : toutes les classes filles doivent absolument l'implémenter