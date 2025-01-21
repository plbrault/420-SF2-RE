# Laboratoire 01

## Objectif

Mettre en pratique les notions en lien avec les pointeurs et les tableaux dynamiques.

## Parties

Ce laboratoire est divisé en deux parties:

* Laboratoire 01-A: Introduction aux pointeurs
* Laboratoire 01-B: Intégration dans la liste de tâches

## Laboratoire 01-A

Cette partie a pour but de vous faire explorer les notions d'adresse mémoire, de pointeur et de tableau dynamique. Commencez le laboratoire dans un nouveau projet contenant un `main` vide.

### Étape 1

Dans votre `main`, déclarez une variable en allocation statique (donc PAS un pointeur) de type `int`, que vous nommerez `nombre`, puis faites afficher à l'écran l'adresse mémoire de cette variable à l'aide de l'opérateur `&`.

Résultat attendu (l'adresse mémoire sera différente):

```
L'adresse de la variable "nombre" est: 0x7fff3ec0da54
```

### Étape 2

À la suite de votre code de l'étape 1, déclarez un pointeur d'entier que vous nommerez `pointeurNombre` et que vous initialiserez à `nullptr`.

Sous votre déclaration, ajoutez la ligne de code suivante:

```
cout << "pointeurNombre contient l'adresse: " << pointeurNombre << endl;
```

Exécutez votre code. Vous devriez obtenir le résultat suivant:

```
pointeurNombre contient l'adresse: 0
```

Cela s'explique par le fait que `nullptr` correspond à l'adresse mémoire 0. Celle-ci n'est pas une véritable adresse, car les adresses mémoire commencent à 1. L'adresse 0 indique que le pointeur ne pointe sur rien.

Retirez l'initialisation de votre pointeur à `nullptr` et ré-exécutez votre programme pour voir ce qui se passe. Vous constaterez que votre pointeur contient maintenant une adresse aléatoire. On veut éviter cela, car cette adresse pourrait correspondre à une donnée existante en mémoire. Pour des raisons de sécurité, on doit **toujours** initialiser nos pointeurs.

Modifiez à nouveau votre code pour initialiser plutôt votre pointeur à `NULL`. Ré-exécutez votre code. Vous constaterez que la valeur `NULL` correspond elle aussi à l'adresse 0.

Remplacez ensuite `NULL` par la valeur `0` directement. L'exécution devrait vous donner le même résultat.

La différence entre `nullptr`, `NULL` et `0` est que `nullptr` indique plus explicitement au compilateur qu'il s'agit d'un pointeur nul et non d'un simple nombre entier de valeur 0. Dans certains cas, cela peut vous éviter des problèmes de compilation. Nous vous recommandons ainsi d'utiliser `nullptr` dans le cadre du cours. Remettez donc votre initialisation à cette valeur avant de poursuivre.

Ajoutez maintenant la ligne de code suivante:

```
cout << "La valeur de pointeurNombre est: " << *pointeurNombre << endl;
```

Si vous exécutez votre code, vous obtiendrez une erreur, parce que vous essayez de déréférencer un pointeur qui ne pointe vers aucune adresse! Retirez ou commentez cette ligne de code pour le moment.

### Étape 3

Assignez maintenant la valeur 42 à la variable `nombre` créée à l'étape 1.

À la suite de cette affectation, assignez **l'adresse** de la variable `nombre` à votre pointeur `pointeurNombre`.

Affichez ensuite, successivement:

* **L'adresse** de la variable `nombre`
* **La valeur** de la variable `nombre`
* **L'adresse** sur laquelle pointe `pointeurNombre`
* **La valeur** sur laquelle pointe `pointeurNombre`

Vous devriez obtenir un résultat semblable à celui-ci (avec une adresse différente):

```
Adresse de nombre: 0x7ffd8efcf318
Valeur de nombre: 42
Adresse pointée par pointeurNombre: 0x7ffd8efcf318
Valeur pointée par pointeurNombre: 42
```

Validez que l'adresse pointée par `pointeurNombre` est la même que l'adresse de `nombre`. Autrement, il y a forcément une erreur dans votre code!

Si vous observez l'exécution de votre programme complet, vous constaterez que l'adresse de `nombre` n'a pas changé depuis l'étape 1. C'est normal, car changer la valeur d'une variable ne change pas son adresse.

### Étape 4

Ajoutez la ligne de code suivante:

```
cout << "&pointeurNombre = " << &pointeurNombre << endl;
```

Exécutez votre code. Vous devriez obtenir une adresse différente que celle affichée précédemment. C'est parce que cette fois-ci, vous n'affichez pas l'adresse **pointée par** le pointeur, vous affichez plutôt l'adresse de la case mémoire qui **contient** le pointeur. En effet, un pointeur est lui-même stocké en mémoire, et a donc lui-même une adresse. On peut même créer un pointeur de pointeur! Cela est utile dans certains cas, mais nous ne le ferons pas dans le cours.

Ça va, pas trop mal à la tête?

### Étape 5

Déclarez maintenant un nouveau pointeur, cette fois-ci de type `string`, que vous appellerez `pointeurString`. N'oubliez pas d'initialiser votre pointeur à `nullptr`.

Suite à cette déclaration, utilisez l'opérateur `new` pour allouer une nouvelle chaîne de caractère qui sera référée par votre pointeur.

Dans la chaîne de caractères, insérez la valeur `"Bonjour le monde!"`.

Faites afficher la valeur de la chaîne de caractères à l'écran. 

Désallouez ensuite la mémoire allouée à votre pointeur.

Testez votre code (il devrait afficher « Bonjour le monde! »).

Suite à votre désallocation de mémoire, essayez d'afficher à nouveau la valeur pointée par `pointeurString`. Cela ne fonctionnera pas, car le pointeur pointe maintenant sur de la mémoire désallouée! Retirez donc cette ligne de code et réinitialisez le pointeur à `nullptr` à la place.

### Étape 6

Dans de nouveaux fichiers `fonctions.h` et `fonctions.cpp`, créez une fonction `afficherValeurPointeur` de type de retour `void`.

Cette fonction doit:

* Prendre un pointeur de `string` en paramètre
* Si le pointeur est nul, afficher « Le pointeur est nul. »
* Sinon, afficher la valeur du pointeur.

Appelez la nouvelle fonction dans votre `main` en lui passant `pointeurString` dans son état actuel. Cela devrait afficher « Le pointeur est nul. ».

Allouez ensuite une nouvelle chaîne de caractères à `pointeurString`, à laquelle vous donnerez la valeur `"Hello World!"`. Appelez de nouveau la fonction `afficherValeurPointeur` avec le pointeur en paramètre. Cela devrait afficher « Hello World! ».

Désallouez la mémoire du pointeur et réinitialisez-le à `nullptr`.
