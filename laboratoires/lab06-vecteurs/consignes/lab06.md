# Laboratoire 06

## Objectifs

* Mettre en pratique la manipulation des vecteurs de la STL pour gérer des tableaux à une ou deux dimensions
* Se familiariser avec le format de données CSV et sa manipulation
* Expérimenter quelques algorithmes de tri et de recherche
* Mobiliser toutes les notions de Programmation orientée objet vues durant la session, incluant l'héritage

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
2 Afficher les elements
3 Trier les éléments par nom
4 Trier les éléments par numéro atomique
5 Rechercher un élément
6 Quitter

Choisir une option: 
```

Créez donc un projet de base avec un `main` contenant une boucle qui affiche ce menu et lit l'option saisie.

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
