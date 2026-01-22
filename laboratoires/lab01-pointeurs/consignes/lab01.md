# Laboratoire 01

## Objectif

Mettre en pratique les notions en lien avec les pointeurs et les tableaux dynamiques.

## Parties

Ce laboratoire est divisé en trois parties:

* Laboratoire 01-A: Manipulation de pointeurs
* Laboratoire 01-B: Manipulation de tableaux dynamiques
* Laboratoire 01-C: Intégration d'un tableau dynamique dans la liste de températures du laboratoire 0

## Laboratoire 01-A

Cette partie a pour but de vous faire explorer les notions d'adresse mémoire, de pointeur et de tableau dynamique. Commencez par créer un nouveau projet avec une fonction `main` vide.

### Étape 1

Dans votre `main`, déclarez une variable en allocation statique (donc PAS un pointeur) de type `int`, que vous nommerez `nombre`, puis faites afficher à l'écran l'adresse mémoire de cette variable à l'aide de l'opérateur `&`.

Résultat attendu (**l'adresse mémoire que vous obtiendrez sera probablement différente**):

```
L'adresse de la variable "nombre" est: 0x7fff3ec0da54
```

### Étape 2

À la suite de votre code de l'étape 1, déclarez un pointeur d'entier que vous nommerez `pointeurNombre` et que vous initialiserez à `nullptr`.

Sous votre déclaration, ajoutez la ligne de code suivante:

```
std::cout << "pointeurNombre contient l'adresse: " << pointeurNombre << endl;
```

Exécutez votre code. Vous devriez obtenir le résultat suivant:

```
pointeurNombre contient l'adresse: 0
```

Cela s'explique par le fait que `nullptr` correspond à l'adresse mémoire 0. Celle-ci n'est pas accessible aux programmes autres que le système d'exploitation, et est donc utilisée en C++ pour représenter un pointeur nul (donc qui ne pointe sur rien). L'adresse 0 indique que le pointeur ne pointe sur rien.

Retirez l'initialisation de votre pointeur à `nullptr` et ré-exécutez votre programme pour voir ce qui se passe. Vous constaterez que votre pointeur contient maintenant une adresse aléatoire. On veut éviter cela, car cette adresse pourrait correspondre à une donnée existante en mémoire. Pour des raisons de sécurité, on doit **toujours** initialiser nos pointeurs.

Modifiez à nouveau votre code pour initialiser plutôt votre pointeur à `NULL`. Ré-exécutez votre code. Vous constaterez que la valeur `NULL` correspond elle aussi à l'adresse 0.

Remplacez ensuite `NULL` par la valeur `0` directement. L'exécution devrait vous donner le même résultat.

La différence entre `nullptr`, `NULL` et `0` est que `nullptr` indique plus explicitement au compilateur qu'il s'agit d'un pointeur nul et non d'un simple nombre entier de valeur 0. Dans certains cas, cela peut vous éviter des problèmes de compilation. Il est donc recommandé d'utiliser `nullptr` dans le cadre du cours. Remettez donc votre initialisation à cette valeur avant de poursuivre.

Ajoutez maintenant la ligne de code suivante:

```
std::cout << "La valeur de pointeurNombre est: " << *pointeurNombre << endl;
```

Si vous exécutez votre code, vous obtiendrez une erreur, parce que vous essayez de **déréférencer** un pointeur qui ne pointe vers aucune adresse! Retirez ou commentez cette ligne de code pour le moment.

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

Suite à cette déclaration, utilisez l'opérateur `new` pour allouer une nouvelle chaîne de caractères qui sera référée par votre pointeur.

Dans la chaîne de caractères, insérez la valeur `"Bonjour le monde!"`.

Faites afficher la valeur de la chaîne de caractères à l'écran. 

Désallouez ensuite la mémoire allouée à votre pointeur.

Testez votre code (il devrait afficher « Bonjour le monde! »).

Suite à votre désallocation de mémoire, essayez d'afficher à nouveau la valeur pointée par `pointeurString`. Cela ne fonctionnera pas, car le pointeur pointe maintenant sur de la mémoire désallouée! Retirez donc cette ligne de code et réinitialisez le pointeur à `nullptr` à la place.

### Étape 6

Dans de nouveaux fichiers `fonctions.h` et `fonctions.cpp`, créez une fonction `afficherValeurPointeur` de type de retour `void`.

Cette fonction doit:

* Prendre un pointeur de `string` en paramètre.
* Si le pointeur est nul, afficher « Le pointeur est nul ».
* Sinon, afficher la valeur du pointeur.

Appelez la nouvelle fonction dans votre `main` en lui passant `pointeurString` dans son état actuel. Cela devrait afficher « Le pointeur est nul ».

Allouez ensuite une nouvelle chaîne de caractères à `pointeurString`, à laquelle vous donnerez la valeur `"Hello World!"`. Appelez de nouveau la fonction `afficherValeurPointeur` avec le pointeur en paramètre. Cela devrait afficher « Hello World! ».

Désallouez la mémoire du pointeur et réinitialisez-le à `nullptr`.

### Étape 7

Déclarez deux nouveaux pointeurs de type `string`, que vous nommerez `prenom` et `nom`.

Ajoutez le code nécessaire pour demander à l'utilisateur son prénom et son nom, les stocker à l'aide des pointeurs, puis afficher le nom complet à l'écran. N'oubliez pas ensuite de désallouer la mémoire.

Exemple d'exécution:

```
Votre prénom: Lisa
Votre nom: Simpson
Votre nom complet est Lisa Simpson.
```

### Étape 8

Créez maintenant deux pointeurs de caractères (`char`), que vous nommerez `caractere1` et `caractere2`.

Ajoutez le code nécessaire pour que le premier caractère soit `'A'` et que le deuxième soit `'B'`. Faites afficher les deux caractères à l'écran.

Échangez ensuite **les adresses** vers lesquelles pointent les deux pointeurs, puis faites afficher les valeurs de nouveau. Elles devraient maintenant être inversées.

N'oubliez pas de désallouer la mémoire.

**⚠️ Faites valider votre laboratoire 01-A par l'enseignant.**

## Laboratoire 01-B

Cette partie vous permettra de vous familiariser avec la manipulation d'un tableau alloué dynamiquement.

Le programme à créer permettra à l'utilisateur d'insérer des nombres dans un tableau alloué dynamiquement, puis calculera la moyenne de ces nombres. Il permettra ensuite à l'utilisateur d'agrandir le tableau en y ajoutant des valeurs supplémentaires, avant de calculer la moyenne à nouveau.

Voici un exemple d'exécution du programme attendu:

```
Combien de nombres voulez-vous entrer? 5
Entrez le nombre #1: 20
Entrez le nombre #2: 17.54
Entrez le nombre #3: 12
Entrez le nombre #4: 13
Entrez le nombre #5: 9
La moyenne des 5 nombres est 14.308.
Voulez-vous ajouter d'autres nombres? (o/n) o
Combien de nouveaux nombres voulez-vous ajouter? 3
Entrez le nombre #6: 101.28
Entrez le nombre #7: 17.11
Entrez le nombre #8: 1024
La moyenne des 8 nombres est 151.741.
```

Référez-vous au document « **Les pointeurs** » disponible sur Moodle pour réaliser les étapes ci-dessous.
Commencez avec un nouveau projet contenant une fonction `main` vide.

### Étape 1

En vous basant sur l'exemple d'exécution, ajoutez le code nécessaire pour demander à l'utilisateur combien de nombres il souhaite entrer. Stockez sa réponse dans un `size_t`.

Si le nombre saisi est supérieur à 0, utilisez un pointeur pour allouer dynamiquement un tableau contenant le nombre de valeurs demandé.

Ajoutez ensuite le code nécessaire pour demander des nombres à l'utilisateur et les stocker dans le tableau. Vous pouvez pour cela créer une fonction `demanderNombres`. Puisque le nom d'un tableau correspond en réalité à l'adresse de son premier élément, votre fonction peut soit prendre en paramètre un pointeur de float (`float *nombres`) ou un tableau de float (`float nombres[]`). Dans les deux cas, vous serez en mesure de passer votre pointeur à votre fonction, et le résultat sera le même.

> 🤔 Est-ce que la fonction `demanderNombres` doit prendre d'autres paramètres?

Testez votre code avant de continuer. À la fin de cette étape, l'exécution de votre programme devrait ressembler à ceci:

```
Combien de nombres voulez-vous entrer? 3
Entrez le nombre #1: 14
Entrez le nombre #2: 108
Entrez le nombre #3: 32
```

### Étape 2

Ajoutez le code nécessaire pour calculer la moyenne des valeurs du tableau et l'afficher à l'écran. Pour cela, vous pourriez par exemple créer des fonctions `calculerMoyenne` et `afficherMoyenne`. À vous de déterminer les paramètres que doivent prendre ces fonctions.

Voici à quoi devrait ressembler l'exécution de votre programme après cette étape:

```
Combien de nombres voulez-vous entrer? 3
Entrez le nombre #1: 14
Entrez le nombre #2: 108
Entrez le nombre #3: 32
La moyenne des 3 nombres est 51.3333.
```

### Étape 3

On veut maintenant demander à l'utilisateur s'il souhaite ajouter de nouvelles valeurs. S'il répond oui, il faudra agrandir le tableau.

On ne peut cependant pas directement changer la taille d'un tableau, même alloué dynamiquement. Il faudra donc plutôt suivre les étapes suivantes:

1. Allouer un nouveau tableau avec la taille mise à jour, dans un nouveau pointeur
2. Copier les éléments de l'ancien tableau vers le nouveau tableau
3. Désallouer le tableau d'origine avec `delete[]`
4. Faire pointer le pointeur d'origine vers la même adresse que le nouveau pointeur

Voici un exemple de code effectuant ces opérations avec un tableau d'entiers:

```c++
// Allocation d'un tableau de 5 éléments
int* monTableau = new int[5];

// Insertion de données dans monTableau
for (size_t i = 0; i < 5; i++) {
    monTableau[i] = i * i;
}

// Allocation du nouveau tableau de 10 éléments
int* nouveauTableau = new int[10];

// Copie des éléments de l'ancien tableau vers le nouveau tableau
for (int i = 0; i < 5; i++) {
    nouveauTableau[i] = monTableau[i];
}

// Désallocation de l'ancien tableau
delete[] monTableau;

// Mise à jour de l'adresse pointée par monTableau
monTableau = nouveauTableau;

// Réinitialisation du pointeur nouveauTableau (nous n'en avons plus besoin)
nouveauTableau = nullptr;
/* Ici, nous effaçons l'adresse stockée dans nouveauTableau, mais 
cela ne désalloue pas la mémoire. Le tableau stocké dans celle-ci
est toujours accessible via le pointeur monTableau. */
```

Inspirez-vous de ce code pour demander à l'utilisateur s'il souhaite ajouter de nouvelles valeurs au tableau, et, le cas échéant, agrandir le tableau du nombre demandé. **Faites l'ajout de ce code directement dans le `main`** (ne créez pas de nouvelle fonction pour cette étape).

Voici à quoi devrait ressembler l'exécution de votre programme à la fin de cette étape:

```
Combien de nombres voulez-vous entrer? 2
Entrez le nombre #1: 8
Entrez le nombre #2: 14
La moyenne des 2 nombres est 11.
Voulez-vous ajouter d'autres nombres? (o/n) o
Combien de nouveaux nombres voulez-vous ajouter? 3
Entrez le nombre #3: 10
Entrez le nombre #4: 15
Entrez le nombre #5: 25.74
```

### Étape 4

Ajoutez finalement le code nécessaire pour recalculer la moyenne sur le tableau complet et l'afficher à l'écran.

Voici à quoi devrait ressembler l'exécution de votre programme à la fin de cette étape:

```
Combien de nombres voulez-vous entrer? 4
Entrez le nombre #1: 10
Entrez le nombre #2: 20
Entrez le nombre #3: 30
Entrez le nombre #4: 40
La moyenne des 4 nombres est 25.
Voulez-vous ajouter d'autres nombres? (o/n) o
Combien de nouveaux nombres voulez-vous ajouter? 5
Entrez le nombre #5: 50
Entrez le nombre #6: 60
Entrez le nombre #7: 70
Entrez le nombre #8: 80
Entrez le nombre #9: 90
La moyenne des 9 nombres est 50.
```

### Étape 5

Testez les cas limites suivants:

1) Entrer 0 valeurs, puis agrandir le tableau de 0 valeurs
2) Entrer 0 valeurs, puis agrandir le tableau de plusieurs valeurs
3) Entrer plusieurs valeurs, puis agrandir le tableau de 0 valeurs

Si un de ces cas ne fonctionne pas correctement, modifiez votre code en conséquence.

**⚠️ Faites valider votre laboratoire 01-B par l'enseignant.**

## Laboratoire 01-C

Dans cette partie, vous allez repartir du code de votre laboratoire 0. Vous allez ensuite l'adapter pour que la taille de la liste de températures soit dynamique.

Commencez donc par copier votre projet du laboratoire 0. Utilisez la nouvelle copie pour réaliser les étapes suivantes.

### Étape 1

Dans votre fonction `main`, remplacez la déclaration de votre tableau `temperatures` par celle d'un pointeur de `double` initialisé à `nullptr`. Retirez aussi la constante `CAPACITE_TEMPERATURES`, puisque vous n'en aurez plus besoin.

Changez ensuite le prototype de votre fonction `chargerTemperatures` pour celle-ci:

```cpp
double* chargerTemperatures(std::string nomFichier, size_t &nbTemperatures);
```

Remarquez que les paramètres `temperatures` et `capaciteTableau` ont disparu.

Voici la nouvelle logique que vous devez maintenant implémenter dans cette fonction:

- Déclarer un pointeur de `double` nommé `temperatures` initialisé à `nullptr`
- Réinitialiser `nbTemperatures` à 0
- Ouvrir le fichier `nomFichier`
- Si l'ouverture du fichier a échoué:
    - **Retourner** `temperatures` (qui contient présentement `nullptr`)
- Tant qu'on n'a pas atteint la fin du fichier:
    - Lire un nombre dans le fichier et le stocker dans une nouvelle variable de type `double`
    - Déclarer un nouveau pointeur `temporaire` et y copier l'adresse de `temperatures`
    - Allouer (avec `new`) un nouveau tableau de `nbTemperatures + 1` éléments et assigner son adresse à `temperatures`
    - À l'aide d'une boucle, copier tous les éléments de `temporaire` vers `temperatures`
    - Affecter la nouvelle température lue dans le fichier à `*(temperaturesAjouts + nbTemperatures)`
    - Désallouer (avec `delete[]`) le tableau sur lequel pointe `temporaire`
    - Incrémenter `nbTemperatures`
- Fermer le fichier
- Retourner `temperatures`

> 🤔 Que fait cette nouvelle logique au juste? Ajoutez un commentaire au-dessus de chaque ligne qui manipule les pointeurs pour expliquer dans vos mots ce que fait cette ligne.

Ensuite, remplacez la condition du `main` qui appelle la fonction `chargerTemperatures` par le code suivant:

```cpp
temperatures = chargerTemperatures(nbTemperatures, "temperatures.txt");
if (temperatures == nullptr) {
    std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
    return 1;
}
```

Observez bien la première ligne. La nouvelle version de la fonction `chargerTemperatures` retourne l'adresse d'un tableau contenant toutes les températures lues dans le fichier, ou `nullptr` si l'ouverture du fichier a échoué. C'est pourquoi on assigne le résultat de la fonction à la variable `temperatures`. Vous saviez sans doute déjà qu'une fonction ne peut pas retourner un tableau. Vous savez maintenant qu'une fonction peut cependant retourner l'*adresse* d'un tableau alloué dynamiquement!

Commentez ensuite l'appel de la fonction `ajouterTemperature` dans le `case 4` de votre `switch`. Si tout va bien, votre code devrait compiler de nouveau. Si ce n'est pas le cas, apportez les correctifs nécessaires.

Utilisez l'option 1 du menu (*Afficher les températures en degrés Celsius*) pour valider que la lecture du fichier fonctionne toujours correctement. Vous devriez voir les mêmes valeurs que dans le fichier `temperatures.txt`.

> Remarquez que la fonction `chargerTemperatures`, sous sa forme actuelle, n'est pas particulièrement efficace: pour chaque température lue dans le fichier, elle copie un par un tous les éléments du tableau vers un nouveau tableau. Pour $n$ températures, on obtiendrait $n(n + 1) / 2$ copies.
Imaginez si $n$ valait 1 milliard. On aurait alors $5 \times 10^{17}$ copies! Pourrait-on changer notre algorithme pour éviter de faire autant de copies? 🤔 Ne changez pas votre code, contentez-vous d'y penser pour le moment.

### Étape 2

Votre code lit maintenant le contenu du fichier dans un tableau de taille dynamique. Nous avons cependant fait un oubli important: nous ne désallouons jamais le tableau! Avec l'allocation dynamique, le programmeur doit impérativement gérer également la désallocation. Ajoutez donc un `delete[] temperatures` à la fin de votre `main`.

### Étape 3

Il reste maintenant à mettre à jour la fonction `ajouterTemperature`. Voici son nouveau prototype:

```cpp
double* ajouterTemperature(double* temperatures, size_t &nbTemperatures)
```

La fonction reçoit l'adresse du tableau `temperatures` actuel, et doit retourner l'adresse d'un nouveau tableau contenant toutes les températures existantes, suivies de la nouvelle température ajoutée par l'utilisateur. Si la température saisie par l'utilisateur est invalide, la fonction doit retourner l'adresse de l'ancien tableau (et non `nullptr`).

Il faut aussi bien sûr modifier la ligne de code qui appelle cette fonction dans le `main` afin d'assigner l'adresse du nouveau tableau à `temperatures`. Assurez-vous que votre fonction désalloue l'ancien tableau!

Faites les modifications nécessaires dans votre code (elles devraient normalement être assez simples).

Testez votre programme au complet. Normalement, tout devrait maintenant fonctionner comme avant.

**⚠️ Faites valider votre laboratoire 01-C par l'enseignant.**
