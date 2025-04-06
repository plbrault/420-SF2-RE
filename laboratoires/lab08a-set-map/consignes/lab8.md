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

## *Parser* JSON

Allez-y, codez un *parser* JSON!

Mais non, c'est une blague!

Vous trouverez un fichier « Parser JSON.zip » sur Moodle. Vous devez le télécharger et placer les fichiers C++ qu'il contient dans votre projet. Les fichiers `JSONParser.h` et `JSONParser.cpp` vous permettent d'utiliser un *parser* JSON qui hérite de la classe *Parser* du laboratoire 6. Si vous ouvrez ces fichiers, vous constaterez qu'ils ne font pas grand-chose. Ils utilisent en fait une bibliothèque (fichier `json.h`) dont la documentation se trouve [ici](https://github.com/nlohmann/json). C'est elle qui fait tout le travail.

La méthode `getData` de `JSONParser` retourne un objet de type `json`. Cette classe provient de la bibliothèque et n'est donc pas un type natif de C++. Elle permet d'extraire les données « parsées » sous forme de conteneurs de la STL.

Supposons que nous avons le fichier JSON suivant:

```json
[
    "ceci",
    "est",
    "un",
    "tableau"
]
```

On peut voir que nous sommes en présence d'un tableau ou d'une liste de chaîne de caractères. Voici comment on s'y prendrait pour « parser » ces données et les convertir en vecteur de *string*:

```cpp
// `flux` est un flux de fichier (ifstream)
// `parser` est une instance de JSONParser
parser.parse(flux); 
vector<string> vecteur = parser.getData().template get<vector<string>>();
```

Si on voulait, on pourrait aussi extraire les données sous forme de `list<string>` plutôt que de `vector<string>`:

```cpp
list<string> liste = parser.getData().template get<list<string>>();
```

On pourrait même extraire les données dans un `set<string>`:

```cpp
set<string> ensemble = parser.getData().template get<set<string>>();
```

Supposons maintenant que nous avons un fichier JSON contenant un dictionnaire:

```json
{
    "201-SF3-RE": "Calcul intégral",
    "203-SF1-RE": "Mécanique",
    "202-SF1-RE": "Chimie générale",
    "420-SF2-RE": "Structure de données et programmation orientée objet"
}
```

En C++, cette structure de données correspond à un `map<string, string>`. On extrairait donc les données de cette façon:

```cpp
map<string, string> dictionnaire = parser.getData().template get<map<string, string>>();
```
