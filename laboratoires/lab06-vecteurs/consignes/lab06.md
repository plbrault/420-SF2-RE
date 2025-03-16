# Laboratoire 06

## Objectifs

* Mettre en pratique la manipulation des vecteurs de la STL pour gérer des tableaux à une ou deux dimensions.
* Se familiariser avec le format de données CSV et sa manipulation.
* Expérimenter quelques algorithmes de tri et de recherche.
* Mobiliser toutes les notions de Programmation orientée objet vues durant la session, incluant l'héritage.

## Partie 1 - CSV et Tableau périodique

[CSV](https://fr.wikipedia.org/wiki/Comma-separated_values), pour *Comma-separated values* (« valeurs séparées par des virgules ») est un format de données courramment utilisé pour représenter des données tabulaires dans un fichier texte. Ce format est surtout utilisé pour importer et exporter des données entre des logiciels. Dans cette partie du laboratoire, vous allez créer un programme en C++ qui fait la lecture d'un fichier CSV et le convertit en matrice (vecteur de vecteurs) d'objets.

Sur Moodle, vous trouverez un fichier `elements.csv`. Téléchargez-le, puis double-cliquez dessus. Si un tableur tel que *Microsoft Excel* ou *LibreOffice Calc* est installé sur votre ordinateur, il est fort probable que le fichier s'ouvrira dans ce logiciel et s'affichera sous forme de chiffrier.

![Capture d'écran du fichier `elements.csv` ouvert dans un tableur](images/chiffrier.png)

Comme vous pouvez le constater, ce fichier contient des informations sur les éléments du tableau périodique.

> NOTE: Le contenu du fichier a été généré par ChatGPT. L'exactitude des informations qu'il contient n'est donc pas garantie.

Contrairement à ce que vos yeux vous laissent croire, un fichier CSV n'est pas un fichier Excel! Fermez donc votre tableur, puis ouvrez maintenant le fichier dans un éditeur de texte tel que *Bloc-Notes* ou *Notepad++*. Vous verrez que le véritable contenu du fichier ressemble à ceci:

```csv
Nom;Symbole;Numero atomique;Groupe;Nombre de trous
Hydrogene;H;1;Alcalins;0
Helium;He;2;Gaz nobles;0
Lithium;Li;3;Alcalins;1
Beryllium;Be;4;Alcalino-terreux;2
Bore;B;5;Autres metaux;3
Carbone;C;6;Non-metaux;4
Azote;N;7;Non-metaux;3
Oxygene;O;8;Non-metaux;2
Fluor;F;9;Halogenes;1
(...)
```

Un fichier CSV est donc un simple fichier texte, contrairement aux formats de fichiers de tableur tels que `.xlsx` et `.ods` qui eux sont des fichiers binaires. Si vous ouvriez un fichier de tableur dans un éditeur de texte, ce que vous y trouveriez ne serait pas intelligible.

Décortiquons le contenu du fichier:

* La première ligne contient les noms des colonnes. La présence de cette ligne dans un fichier CSV n'est pas obligatoire.
* Chacune des lignes suivantes contient les valeurs de chaque colonne pour un élément du tableau périodique. Les valeurs sont séparées par des points-virgules (`;`).

> 🤔 Wô menute. On avait pas dit que *CSV* voulait dire *Comma-separated values*, donc que les valeurs devraient être séparées par des virgules?

En effet, au sens strict du terme, un fichier CSV devrait contenir des valeurs séparées par des virgules (`,`) et non des points-virgules (`;`). Cependant, il faut savoir que le format CSV n'est pas vraiment standardisé, et que d'autres **séparateurs** (***delimiters*** en anglais) sont parfois utilisés selon les logiciels et leurs configurations. Par ailleurs, lorsqu'Excel est configuré en français, il utilise par défaut le point-virgule comme séparateur dans les fichiers CSV, puisqu'il réserve l'usage des virgules à la représentation des nombres décimaux (tandis que le point (`.`) est utilisé à cet effet lorsqu'Excel est configuré en anglais). Le fichier `elements.csv` ne s'afficherait donc pas correctement dans Excel en français s'il utilisait des virgules comme séparateurs.

Maintenant que vous comprenez comment interpréter un fichier CSV, voyons à quoi ressemblera le programme que vous devez créer. On veut d'abord afficher le menu suivant:

```
Tableau périodique

1 Charger le tableau périodique
2 Afficher les éléments
3 Trier les éléments par nom
4 Trier les éléments par numéro atomique
5 Rechercher un élément
6 Quitter

Choisir une option: 
```

Créez donc un projet de base avec un `main` contenant une boucle qui affiche ce menu et lit l'option saisie. Ajoutez la structure de base pour traiter les options, et faites fonctionner l'option 6.

> 🤔 Pourriez-vous réutiliser une classe d'un laboratoire précédent pour faire cela?

Ajoutez à votre projet votre classe `Element` du laboratoire 3 (prenez celle de la solution au besoin). Assurez-vous que la classe fonctionne dans le projet en instanciant un `Element` dans votre `main` pour voir si le projet compile toujours.

Attaquons-nous maintenant à l'implémentation de l'option 1.

### La fonction `split`

La fonction `split` est une fonction qui existe nativement dans de nombreux langages de programmation, mais malheureusement pas en C++. Elle prend en paramètres une chaîne de caractères et un séparateur, puis retourne un tableau contenant les sous-chaînes résultantes. Par exemple, si la chaîne de caractères est `"Bonjour le monde!"` et que le séparateur est le caractère espace (`' '`), la fonction `split` produira le tableau `["Bonjour", "le", "monde!"]`. De la même façon, si la chaîne de caractères est `Hydrogene;H;1;Alcalins;0` et que le séparateur est `;`, la fonction retournera le tableau `["Hydrogene", "H", "1", "Alcalins", "0"]`. Vous aurez donc compris que cette fonction serait très utile pour séparer les valeurs d'une ligne de notre fichier CSV. C'est pourquoi vous allez l'implémenter!

La fonction à créer doit avoir la signature suivante:

```cpp
std::vector<std::string> split(const std::string& str, char delimiter);
```

> 🤔 Pourquoi retourne-t-on le vecteur par valeur?

Pensez à comment vous pourriez faire fonctionner cette fonction (il existe plusieurs solutions possibles), puis implémentez-la. Testez votre fonction rigoureusement avant de continuer.

### Les classes `Parser` et `CSVParser`

À l'étape précédente, vous avez créé une fonction qui sera utile pour convertir une ligne du fichier CSV en `vector<string>`. Un fichier CSV peut être représenté par une matrice de `string`. Puisqu'une matrice est essentiellement un tableau de tableaux, on pourra la représenter sous forme de `vector<vector<string>>`.

Ce que nous voulons ici, c'est créer ce qu'on appelle un ***parser***. En informatique, le verbe anglais ***parse*** décrit l'opération qui interprète des données textuelles pour les convertir en données exploitables par un programme. Dans notre cas, on cherche à « parser » du CSV. Vous créerez donc une classe `CSVParser`. Voici la définition de cette classe:

```cpp
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

class CSVParser : public Parser {
private:
    char _delimiter;
    bool _readsColumnNames;
    std::vector<std::vector<std::string>> _data;
    std::vector<std::string> _columnNames;
public:
    CSVParser(char delimiter=',', bool readColumnNames = true);

    char getDelimiter() const;
    void setDelimiter(char delimiter);
    bool readsColumnNames() const;
    void setReadsColumnNames(bool readsColumnNames);

    void parse(std::istream& in) override;
    const std::vector<std::vector<std::string>>& getData() const;
    const std::vector<std::string>& getColumnNames() const;
    int getColumnIndex(const std::string& columnName) const;
    const std::vector<std::string>& getRow(size_t index) const;

    const std::string& getString(size_t row, size_t column) const;
    const std::string& getString(size_t row, const std::string& columnName) const;
    int getInt(size_t row, size_t column) const;
    int getInt(size_t row, const std::string& columnName) const;
    double getDouble(size_t row, size_t column) const;
    double getDouble(size_t row, const std::string& columnName) const;

    const size_t getNumRows() const;
    const size_t getNumColumns() const;
};
```

Remarquez que `CSVParser` hérite d'une classe `Parser`. C'est qu'il existe d'autres formats de données (ex: JSON, XML, etc) pour lesquels on pourrait éventuellement vouloir créer des *parsers*. On peut aussi s'imaginer que tout *parser* aura une méthode `parse` avec la même signature. Voici donc la classe abstraite `Parser`:

```cpp
#pragma once

#include <iostream>

class Parser {
public:
    virtual void parse(std::istream& in) = 0;
};
```

Remarquez que la méthode `parse` prend en paramètre un `istream`. Vous savez déjà que `cin` est un `istream`, mais vous ne savez peut-être pas que la classe `ifstream` (qui, pour rappel, sert à lire dans un fichier) hérite d'`istream`! En prenant en paramètre un `istream`, la méthode `parse` pourra lire ses données d'entrée soit à partir d'un fichier, soit à partir d'une saisie au clavier, et ce sans devoir changer l'implémentation de la méthode. Voilà toute la puissance de l'héritage!

Remarquez également que la classe `CSVParser` ne définit pas de destructeur, d'opérateur = et de constructeur de copie, même si elle comprend un tableau alloué dynamiquement. C'est parce que ce dernier est encapsulé dans la classe `vector`, et donc géré par celle-ci. Voilà pourquoi les vecteurs sont beaucoup plus pratiques à utiliser que les pointeurs de tableaux!

Observons plus attentivement les attributs de la classe `CSVParser`:

* `_delimiter` contient le caractère utilisé pour séparer les valeurs d'une même ligne dans un fichier CSV. Sa valeur par défaut (définie dans le prototype du constructeur) est `,`.
* `_readsColumnNames` indique si les valeurs de la première ligne du fichier CSV doivent être interprétée comme des noms de colonnes. Sa valeur par défaut est `true`.
* `_data` est la matrice dans laquelle les données « parsées » seront stockées.
* `_columnNames` est le vecteur dans lequel seront stockés les noms des colonnes, si `_readsColumnNames` est à `true`.

Penchons-nous maintenant sur les méthodes. En plus du constructeur et des accesseurs et mutateurs pour les deux attributs scalaires, la classe `CSVParser` offre les méthodes suivantes:

* `parse`: lit le flux d'entrée et le convertit en matrice de `string` qu'il stockera dans `_data`. La fonction `split` créée précédemment sera utile à l'implémentation de cette méthode. Il ne faudra par ailleurs pas oublier de vider les vecteurs `_data` et `_columnNames` avant de procéder, et de stocker les nouveaux noms de colonnes dans `_columnNames` si la configuration du *parser* l'exige.
* `getData`: retourne la matrice au complet.
* `getColumnNames`: retourne les noms de colonnes. Si `readsColumnNames` était à `false` au moment du *parsing*, le vecteur retourné devrait être vide.
* `getRow`: retourne la ligne de la matrice correspondant à l'indice reçu en paramètre.
* `getColumnIndex`: retourne l'indice de la colonne correspondant au nom reçu en paramètre.
* `getString`: retourne la **chaîne de caractères** présente à la ligne et la colonne spécifiés. Cette méthode existe en deux versions: une qui reçoit l'indice de la colonne, et une autre qui reçoit plutôt le nom de la colonne.
* `getInt`: retourne le **nombre entier** présent à la ligne et la colonne spécifiés. La fonction `stoi` de C++ sera utile à l'implémentation de cette méthode.
* `getDouble`: retourne le **nombre à virgule** présent à la ligne et la colonne spécifiés. La fonction `stod` de C++ sera utile à l'implémentation de cette méthode.
* `getNumRows`: retourne le nombre de lignes.
* `getNumColumns`: retourne le nombre de colonnes. **Attention: doit retourner le bon résultat même s'il n'y a pas de noms de colonnes!**

Implémentez toutes les méthodes de la classe. Référez-vous à [la documentation de std::vector](https://en.cppreference.com/w/cpp/container/vector) au besoin. N'oubliez pas de penser aux cas limites et à comment vous devriez les gérer.

Testez rigoureusement votre *parser* sur le fichiers `elements.csv`.

### Conversion de la matrice de `string` en vecteur d'`Element`

> Pour la suite du laboratoire, n'hésitez pas à modifier au besoin la classe `Element`.

Vous êtes maintenant en mesure d'importer les données d'un fichier CSV dans votre programme. Une matrice de `string` n'est cependant pas idéale pour travailler sur les éléments du tableau périodique. Vous allez donc convertir cette matrice en vecteur d'`Element`!

Pour ce faire, vous allez créer une nouvelle classe `TableauPeriodique` qui vous accompagnera pour toute la suite de cette partie du laboratoire. Voici la définition de cette classe:

```cpp
#pragma once

#include <iostream>
#include <vector>
#include "CSVParser.h"
#include "Element.h"

class TableauPeriodique {
private:
    CSVParser _parser;
    std::vector<Element> _elements;
    bool _estTrieParNom;
public:
    TableauPeriodique();
    void charger(const std::string& nomFichier);
    // void afficher(std::ostream& sortie);
    // void trierParNom();
    // void trierParNumeroAtomique();
    // const Element* getElementParNom(const std::string& nom) const;
};

std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
```

La plupart des méthodes sont commentées, car vous allez les implémenter dans les étapes ultérieures. Pour le moment, implémentez seulement le constructeur et la méthode `charger`. Celle-ci doit ouvrir le fichier CSV, utiliser `_parser` pour récupérer ses données, puis insérer tous les éléments dans `_elements`. N'oubliez pas de fermer le fichier!

Appelez la méthode `charger` dans votre `main` et utilisez le débogueur pour vérifier que le tableau d'éléments est rempli correctement.

### Affichage des éléments

Implémentez maintenant la méthode `afficher`. Celle-ci doit afficher chacun des éléments du vecteur à l'aide de la méthode `toString` déjà existante dans la classe `Element`.

Vous avez maintenant ce qu'il faut pour faire fonctionner les options 1 et 2 du menu du programme. Testez le tout rigoureusement.

### Tri à bulles

Vous allez maintenant implémenter la méthode `trierParNom`, qui, comme son nom l'indique, doit ordonner les `Element` du vecteur en ordre alphabétique de nom. Pour ce faire, vous allez utiliser l'algorithme du [Tri à bulles](https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles) ([vidéo explicative](https://www.youtube.com/embed/LTN97u8rSY0?si=H-FMr9doEaZ3CT1A)).

Voici du pseudocode décrivant le tri à bulles (tiré de Wikipédia):

```
tri_à_bulles(Tableau T)
   pour i allant de (taille de T)-1 à 1
       pour j allant de 0 à i-1
           si T[j+1] < T[j]
               (T[j+1], T[j]) ← (T[j], T[j+1])
```

Utilisez votre méthode pour implémenter l'option 3 du menu. Validez que votre tri fonctionne correctement avant de continuer.

> ℹ️ Le tri à bulles n'est pas un algorithme de tri particulièrement efficace. On dit que sa **complexité en temps** est en moyenne $ O(n^2) $, c'est-à-dire que le temps d'exécution est proportionnel au carré du nombre d'éléments en entrée. C'est généralement le cas des algorithmes basés sur deux boucles *for* imbriquées.

### Tri par insertion

Vous allez maintenant implémenter la méthode `trierParNumeroAtomique`. Cette fois-ci, vous allez utiliser l'algorithme du [Tri par insertion](https://fr.wikipedia.org/wiki/Tri_par_insertion) ([vidéo explicative](https://www.youtube.com/watch?v=bRPHvWgc6YM)).

Voici du pseudocode décrivant le tri par insertion (tiré de Wikipédia):

```
tri_insertion(Tableau T)

    pour i de 1 à taille(T) - 1

        # mémoriser T[i] dans x
        x ← T[i]                            

        # décaler les éléments T[0]..T[i-1] qui sont plus grands que x, en partant de T[i-1]
        j ← i                               
        tant que j > 0 et T[j - 1] > x
            T[j] ← T[j - 1]
            j ← j - 1

        # placer x dans le "trou" laissé par le décalage
        T[j] ← x                            

```

Utilisez votre méthode pour implémenter l'option 4 du menu. Validez que votre tri fonctionne correctement avant de continuer.

> ℹ️ Le tri par insertion est celui que la plupart des gens appliquent instinctivement pour trier des cartes à jouer dans leurs mains. Comme pour le tri à bulles, sa complexité en temps est $ O(n^2) $ en moyenne, mais peut être $ O(n) $ sur des tableaux de petite taille ou qui sont presque triés. Il existe des algorithmes de tri plus efficaces dans le cas général, tels que le [Tri rapide](https://fr.wikipedia.org/wiki/Tri_rapide) et le [Tri fusion](https://fr.wikipedia.org/wiki/Tri_fusion), mais nous ne les implémenterons pas dans ce laboratoire.

### Recherche séquentielle et dichotomique

Vous allez maintenant implémenter la méthode `getElementParNom`. Il s'agit d'une méthode de recherche, qui trouve dans le vecteur l'`Element` correspondant au nom reçu en paramètre, puis le retourne.

L'algorithme de recherche le plus simple est la [recherche séquentielle](https://fr.wikipedia.org/wiki/Recherche_s%C3%A9quentielle) ou linéaire. Elle consiste simplement à itérer sur les éléments du tableau jusqu'à ce qu'on ait trouvé celui qui correspond à l'objet recherché. Vous avez déjà utilisé cet algorithme à plusieurs reprises sans le savoir, notamment dans la méthode `getColumnIndex` de votre classe `CSVParser`. Sa complexité en temps est $ O(n) $.

Dans le cas où le tableau est trié, on peut utiliser un algorithme de recherche plus efficace, soit la [recherche dichotomique](https://fr.wikipedia.org/wiki/Recherche_dichotomique), avec une complexité de $ O(\log n) $. Le principe de cet algorithme est de vérifier d'abord si l'item recherché se trouve au milieu du tableau, puis, si ce n'est pas le cas, de vérifier le milieu de la première ou la deuxième moitié du tableau selon que l'item est plus petit ou plus grand que celui qu'on vient d'observer, et ainsi de suite. C'est l'algorithme qu'on applique instinctivement lorsqu'on cherche un mot dans un dictionnaire.

> NOTE: quand on parle d'une complexité de $ O(\log n) $, on fait généralement référence à un logarithme en base 2. On trouve cette complexité dans les algorithmes de type **Diviser pour mieux régner**, qui découpent l'entrée en plusieurs parties de manière successive.

Remarquez que la classe `TableauPeriodique` possède un attribut booléen `_estTrieParNom`. Si ce n'est pas déjà fait, ajoutez le code nécessaire pour mettre à jour cet attribut aux endroits appropriés.

L'algorithme de haut niveau de la méthode `getElementParNom` sera le suivant:

```
Si le tableau est trié par nom:
    Utiliser la recherche dichotomique
Sinon:
    Utiliser la recherche séquentielle
```

La méthode retourne un `const Element*`. Souvenez-vous qu'on peut utiliser l'opérateur `&` pour obtenir l'adresse d'une variable. Dans le cas où l'élément recherché est absent du tableau, retournez `nullptr`.

Voici du pseudocode pour la recherche dichotomique (tiré de Wikipédia):

```
//déclarations
 début, fin, val, mil, N : Entiers
 t : Tableau [0..N] d'entiers classé
 trouvé : Booléen
 
//initialisation
 N = taille(t)-1
 début ← 0 
 fin ← N
 trouvé ← faux
 Saisir val

//Boucle de recherche
 // La condition début inférieur ou égal à fin permet d'éviter de faire
 // une boucle infinie si 'val' n'existe pas dans le tableau.
  Tant que trouvé != vrai et début <= fin:
      mil ← partie entière((début + fin)/2)
      si t[mil] == val:
         trouvé ← vrai
      sinon:
         si val > t[mil]:
            début ← mil+1
         sinon:
            fin ← mil-1
```

Utilisez votre méthode pour implémenter l'option 5 du menu. Validez que votre tri fonctionne correctement avant de continuer.

🎉 Félicitations, vous avez terminé la partie 1 du laboratoire!

## Partie 2 - Carte topographique

La [Sépaq](https://www.sepaq.com/organisation/) fait appel à vos talents en algorithmie pour l'assister dans la création d'un nouveau parc national. À l'aide d'une [carte topographique](https://fr.wikipedia.org/wiki/Carte_topographique) d'un terrain montagneux, elle vous demande d'identifier l'emplacement de fin d'un futur sentier pédestre. La carte topographique est représentée par une matrice d'entiers dont chaque valeur représente une altitude. On vous demande de trouver **l'altitude du plus haut sommet pouvant être atteint par une pente graduelle à partir d'un point d'altitude 0**. On vous précise que par « pente graduelle », on entend un trajet dont l'altitude de chaque point est **exactement 1 de plus** que celle du point précédent. Chaque point $ p + 1 $ du trajet est adjacent à un point $ p $ soit horizontalement, verticalement ou en diagonal.
