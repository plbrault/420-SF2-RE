# Laboratoire 08

## Objectifs

* Se familiariser avec l'utilisation des ensembles (*set*) et des dictionnaires (*map*).
* Utiliser le format de données *JSON*.
* Mobiliser toutes les notions vues depuis le début de la session.

## Format de données JSON

[JSON](https://fr.wikipedia.org/wiki/JavaScript_Object_Notation), pour *JavaScript Object Notation*, est un format de données textuel permettant de représenter des listes, des dictionnaires et des types scalaires. Voici à quoi ressemble ce format (exemple tiré de Wikipédia):

```json
{
    "menu": {
        "id": "file",
        "value": "File",
        "popup": {
            "menuitem": [
                { "value": "New", "onclick": "CreateNewDoc()" },
                { "value": "Open", "onclick": "OpenDoc()" },
                { "value": "Close", "onclick": "CloseDoc()" }
            ]
        }
    }
}
```

Dans cet exemple, on trouve un dictionnaire avec une clé `menu` contenant elle-même un dictionnaire avec les clés `id`, `value` et `popup`. La clé `popup` contient un autre dictionnaire, dont la clé `menuItem` contient une liste (ou tableau) de trois autres dictionnaires.

Comme son nom l'indique, le format JSON est basé sur la façon dont sont représentés les objets dans le langage [JavaScript](https://fr.wikipedia.org/wiki/JavaScript). Les éléments qu'on a appelés « dictionnaires » dans les explications ci-dessus sont en fait des objets du point de vue de JavaScript. Ils deviendront cependant des dictionnaires (*map*) lorsqu'on importera des données JSON en C++.

Quand on y pense, les objets et les dictionnaires sont des structures qui se ressemblent: les deux associent des clés (attributs dans le contexte des objets) à des valeurs. Dans un langage à typage statique comme C++, la principale différence entre un objet et un dictionnaire est qu'on ne peut pas ajouter dynamiquement d'attributs à un objet (dont les attributs sont définis dans une classe) durant l'exécution du programme, alors qu'on peut dynamiquement ajouter des clés à un dictionnaire. Dans des langages plus dynamiques comme JavaScript, la différence entre un objet et un dictionnaire est plus subtile.
