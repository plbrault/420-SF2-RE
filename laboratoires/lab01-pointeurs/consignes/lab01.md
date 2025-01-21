# Laboratoire 01

## Objectif

Mettre en pratique les notions en lien avec les pointeurs et les tableaux dynamiques.

## Parties

Ce laboratoire est divisé en deux parties:

* Laboratoire 01-A: Introduction aux pointeurs
* Laboratoire 01-B: Intégration dans la liste de tâches

## Laboratoire 01-A

Cette partie a pour but de vous faire explorer les notions d'adresse mémoire, de pointeur et de tableau dynamique.

## Étape 1

Dans Visual Studio, créez un nouveau projet nommé `lab01a`. Créez les fichiers `main.cpp`, `fonctions.h` et `fonctions.cpp`. Dans le fichier `main.cpp`, ajoutez une fonction `main` vide. Assurez-vous que votre programme compile.

## Étape 2

Dans votre `main`, déclarez une variable en allocation statique (donc PAS un pointeur) de type `int`, que vous nommerez `nombre`, puis faites afficher à l'écran l'adresse mémoire de cette variable à l'aide de l'opérateur `&`.

Résultat attendu (l'adresse mémoire sera différente):

```
L'adresse de la variable "nombre" est: 0x7fff3ec0da54
```

## Étape 3

À la suite de votre code de l'étape 2, déclarez un pointeur d'entier que vous nommerez `pointeurNombre` et que vous initialiserez à `nullptr`.

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

La différence entre `nullptr`, `NULL` et `0` est que `nullptr` indique plus explicitement au compilateur qu'il s'agit d'un pointeur nul et non d'un simple nombre entier de valeur 0. Dans certains cas, cela peut vous éviter des problèmes de compilation. Nous vous recommandons donc d'utiliser `nullptr` dans le cadre du cours. Remettez donc votre initialisation à cette valeur avant de poursuivre.

Ajoutez maintenant la ligne de code suivante:

```
cout << "La valeur de pointeurNombre est: " << *pointeurNombre << endl;
```

Si vous exécutez votre code, vous obtiendrez une erreur, parce que vous essayez de déréférencer un pointeur qui ne pointe vers aucune adresse! Retirez donc cette ligne de code avant de poursuivre.
