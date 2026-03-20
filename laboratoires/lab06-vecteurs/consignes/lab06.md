# Laboratoire 06

## Objectifs

* Mettre en pratique la manipulation des vecteurs de la STL pour gérer des tableaux à une ou deux dimensions.
* Se familiariser avec le format de données CSV et sa manipulation.
* Expérimenter quelques algorithmes de tri et de recherche.
* Mobiliser toutes les notions de Programmation orientée objet vues durant la session, incluant l'héritage.

## Parties

Ce laboratoire comprend trois parties:

* **Partie 06-A** (***préalable à un laboratoire en chimie***): CSV et Tableau périodique
* **Partie 06-B**: Algorithmes de tri et de recherche sur le tableau périodique
* **Partie 06-C**: Algorithme récursif dans une matrice

## Laboratoire 06-A - Importation de fichiers CSV et tableau périodique

[CSV](https://fr.wikipedia.org/wiki/Comma-separated_values), pour *Comma-separated values* (« valeurs séparées par des virgules ») est un format de données couramment utilisé pour représenter des données tabulaires dans un fichier texte. Ce format est surtout utilisé pour importer et exporter des données entre des logiciels. Dans cette partie du laboratoire, vous allez créer un programme en C++ qui fait la lecture d'un fichier CSV et le convertit en matrice (vecteur de vecteurs) d'objets.

Sur Moodle, vous trouverez un fichier `elements.csv`. Téléchargez-le, puis double-cliquez dessus. Si un tableur tel que *Microsoft Excel* ou *LibreOffice Calc* est installé sur votre ordinateur, il est fort probable que le fichier s'ouvrira dans ce logiciel et s'affichera sous forme de chiffrier.

![Capture d'écran du fichier `elements.csv` ouvert dans un tableur](images/chiffrier.png)

Comme vous pouvez le constater, ce fichier contient des informations sur les éléments du tableau périodique.

Contrairement à ce que vos yeux vous laissent croire, un fichier CSV n'est pas un fichier Excel! Fermez donc votre tableur, puis ouvrez maintenant le fichier dans un éditeur de texte tel que *Bloc-Notes* ou *Notepad++*. Vous verrez que le véritable contenu du fichier ressemble à ceci:

```csv
Nom de l'element;Numero atomique;Symbole;Masse atomique
Hydrogene;1;H;1.007975
Helium;2;He;4.002602
Lithium;3;Li;6.9395
Beryllium;4;Be;9.012183
Bore;5;B;10.8135
Carbone;6;C;12.0106
Azote;7;N;14.006855
Oxygene;8;O;15.9994
Fluor;9;F;18.998403
(...)
```

Un fichier CSV est donc un simple fichier texte, contrairement aux formats de fichiers de tableur tels que `.xlsx` et `.ods` qui eux sont des fichiers binaires. Si vous ouvriez un fichier de tableur dans un éditeur de texte, ce que vous y trouveriez ne serait pas intelligible.

Décortiquons le contenu du fichier:

* La première ligne contient les noms des colonnes. La présence de cette ligne dans un fichier CSV n'est pas obligatoire.
* Chacune des lignes suivantes contient les valeurs de chaque colonne pour un élément du tableau périodique. Les valeurs sont séparées par des points-virgules (`;`).

> 🤔 Wô menute. On avait pas dit que *CSV* voulait dire *Comma-separated values*, donc que les valeurs devraient être séparées par des virgules?

En effet, au sens strict du terme, un fichier CSV devrait contenir des valeurs séparées par des virgules (`,`) et non des points-virgules (`;`). Cependant, il faut savoir que le format CSV n'est pas vraiment standardisé, et que d'autres **séparateurs** (***delimiters*** en anglais) sont parfois utilisés selon les logiciels et leurs configurations. Par ailleurs, lorsqu'Excel est configuré en français, il utilise par défaut le point-virgule comme séparateur dans les fichiers CSV, puisqu'il réserve l'usage des virgules à la représentation des nombres décimaux. Le fichier `elements.csv` ne s'afficherait donc pas correctement dans Excel en français s'il utilisait des virgules comme séparateurs.

> Note: le fichier CSV du tableau périodique utilise le `;` comme délimiteur, mais utilise tout de même le point (`.`) pour les valeurs décimales, et ce pour vous simplifier la vie en C++.

Attaquons-nous donc à la lecture d'un fichier CSV!

### Étape 1 - La fonction `split`

La fonction `split` est une fonction qui existe nativement dans de nombreux langages de programmation, mais malheureusement pas en C++. Elle prend en paramètres une chaîne de caractères et un séparateur, puis retourne un tableau contenant les sous-chaînes résultantes. Par exemple, si la chaîne de caractères est `"Bonjour le monde!"` et que le séparateur est le caractère espace (`' '`), la fonction `split` produira le tableau `["Bonjour", "le", "monde!"]`. De la même façon, si la chaîne de caractères est `"Hydrogene;1;H;1.007975"` et que le séparateur est `;`, la fonction retournera le tableau `["Hydrogene", "1", "H", "1.007975"]`. Vous aurez donc compris que cette fonction serait très utile pour séparer les valeurs d'une ligne de notre fichier CSV. C'est pourquoi vous allez l'implémenter!

La fonction à créer doit avoir la signature suivante:

```cpp
std::vector<std::string> split(const std::string& str, char delimiter);
```

> 🤔 Pourquoi retourne-t-on le vecteur par valeur?

Pensez à comment vous pourriez faire fonctionner cette fonction (il existe plusieurs solutions possibles), puis définissez-la dans un fichier `fonctions.h` et implémentez-la dans un fichier `fonctions.cpp`. Testez votre fonction rigoureusement avant de continuer.

### Étape 2 - Les classes `Parser` et `CSVParser`

À l'étape précédente, vous avez créé une fonction qui sera utile pour convertir une ligne du fichier CSV en `vector<string>`. Un fichier CSV peut être représenté par une matrice de `string`. Puisqu'une matrice est essentiellement un tableau de tableaux, on pourra la représenter sous forme de `vector<vector<string>>`.

Ce que nous voulons ici, c'est créer ce qu'on appelle un ***parser***. En informatique, le verbe anglais ***parse*** décrit l'opération qui interprète des données textuelles pour les convertir en données exploitables par un programme. Dans notre cas, on cherche à « parser » du CSV. Vous créerez donc une classe `CSVParser`. Voici la définition de cette classe, avec des commentaires expliquant chacun de ses membres:

```cpp
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

class CSVParser : public Parser {
private:
    // Caractère utilisé pour séparer les valeurs d'une même ligne dans le fichier CSV (ex: ',' ou ';').
    char _delimiter;

    // Indique si les valeurs de la première ligne du fichier CSV doivent être interprétées comme des noms de colonnes.
    bool _readsColumnNames;

    /*
     * Les données du CSV une fois "parsées", stockées sous forme de tableau 2D de chaînes de caractères
     * (vecteur de vecteurs de string). Chaque ligne du CSV correspond donc à un vecteur de string,
     * et chaque string représente une cellule de la ligne.
     */
    std::vector<std::vector<std::string>> _data;

    /* Les noms des colonnes, donc le contenu de la première ligne du tableau si `_readsColumnNames` est à `true`.
     * Si `_readsColumnNames` est à `false`, ce vecteur doit rester vide. */
    std::vector<std::string> _columnNames;
public:
    /* Constructeur avec paramètres.
     *
     * Des valeurs par défaut sont données aux paramètres.
     * On peut donc appeler le constructeur en lui passant soit 0, 1 ou 2 paramètres.
     * Si on ne lui passe aucun paramètre, ce sont les valeurs par défaut qui seront utilisées.
     * Si on lui en passe un seul, il s'appliquera à `delimiter`, et `readsColumnNames` prendra sa valeur par défaut.
     *
     * Autrement dit, c'est comme si on définissait les trois constructeurs suivants d'un seul coup:
     *
     * CSVParser() : CSVParser(',', true) {}
     * CSVParser(char delimiter) : CSVParser(delimiter, true) {}
     * CSVParser(char delimiter, bool readColumnNames);
     *
     * Les valeurs par défaut ne doivent pas être incluses dans l'implémentation (fichier .cpp). */
    CSVParser(char delimiter=',', bool readColumnNames = true);

    // Accesseurs et mutateurs d'attributs
    char getDelimiter() const;
    void setDelimiter(char delimiter);
    bool readsColumnNames() const;
    void setReadsColumnNames(bool readsColumnNames);
    const std::vector<std::vector<std::string>>& getData() const;
    const std::vector<std::string>& getColumnNames() const;

    /* Méthode qui lit le flux d'entrée et le convertit en matrice de `string` qu'il stocke dans `_data`.
     * La fonction `split` créée précédemment sera utile à l'implémentation de cette méthode.
     * Il ne faudra par ailleurs pas oublier de vider les vecteurs `_data` et `_columnNames` avant de procéder,
     * et de stocker les nouveaux noms de colonnes dans `_columnNames` si `_readsColumnNames` est à `true`.
     * ATTENTION: il ne faut PAS stocker les noms de colonnes dans `_data`!
     */
    void parse(std::istream& in) override;

    /* Retourne l'indice de la colonne correspondant au nom donné en paramètre, ou lance une exception
     * `std::invalid_argument` si aucune colonne ne correspond au nom donné. */
    int getColumnIndex(const std::string& columnName) const;

    /* Retourne la ligne de la matrice correspondant à l'indice reçu en paramètre, ou lance une exception
     * `std::out_of_range` si l'indice est invalide. */
    const std::vector<std::string>& getRow(size_t index) const;

    /* Retourne la chaîne de caractères présente à la ligne et la colonne spécifiés.
     * Cette méthode existe en deux versions: une qui reçoit l'indice de la colonne, et une autre qui reçoit plutôt
     * le nom de la colonne. Lance une exception `std::out_of_range` au besoin. */
    const std::string& getString(size_t row, size_t column) const;
    const std::string& getString(size_t row, const std::string& columnName) const;

    /* Retourne la valeur présente à la ligne et la colonne spécifiée, en la convertissant d'abord en `int`.
     * Utilisez la fonction `std::stoi` pour convertir la chaîne de caractères en `int`.
     */
    int getInt(size_t row, size_t column) const;
    int getInt(size_t row, const std::string& columnName) const;

    /* Retourne la valeur présente à la ligne et la colonne spécifiée, en la convertissant d'abord en `double`.
     * Utilisez la fonction `std::stod` pour convertir la chaîne de caractères en `double`.
     */
    double getDouble(size_t row, size_t column) const;
    double getDouble(size_t row, const std::string& columnName) const;

    // Accesseur du nombre de lignes présentes dans `_data`
    size_t getNumRows() const;

    /* Accesseur du nombre de colonnes.
     * Attention: doit retourner le bon résultat même s'il n'y a pas de noms de colonnes! */
    size_t getNumColumns() const;
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

Remarquez également que la méthode `parse` prend en paramètre un `istream`. Vous savez déjà que `cin` est un `istream`, mais vous ne savez peut-être pas que la classe `ifstream` (qui, pour rappel, sert à lire dans un fichier) hérite d'`istream`! En prenant en paramètre un `istream`, la méthode `parse` pourra lire ses données d'entrée soit à partir d'un fichier, soit à partir d'une saisie au clavier, et ce sans devoir changer l'implémentation de la méthode. Voilà toute la puissance de l'héritage et du polymorphisme!

Par ailleurs, la classe `CSVParser` ne définit pas de destructeur, d'opérateur `=` et de constructeur de copie, même si elle comprend un tableau alloué dynamiquement. C'est parce que ce dernier est encapsulé dans la classe `vector`, et donc géré par celle-ci. Voilà pourquoi les vecteurs sont beaucoup plus pratiques à utiliser que les pointeurs de tableaux!

Implémentez toutes les méthodes de la classe en vous basant sur les explications fournies dans les commentaires. Référez-vous à [la documentation de std::vector](https://en.cppreference.com/w/cpp/container/vector) au besoin. N'oubliez pas de penser aux cas limites et à comment vous devriez les gérer. En implémentant les méthodes, pensez aussi aux endroits où vous pourriez faire de la...

![](./images/bob_leponge_reutilisation.jpg)

Voici du code à placer dans votre fichier `main.cpp` pour tester votre *parser* avec le tableau périodique:

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include "CSVParser.h"

#define COL_WIDTH 16

int main() {
    std::ifstream file;
    file.open("../elements.csv");
    if (!file.is_open()) {
        std::cerr << "L'ouverture du fichier a échoué." << std::endl;
        return 1;
    }

    CSVParser parser(';', true);

    parser.parse(file);

    std::cout << "| ";
    for (size_t i = 0; i < parser.getNumColumns(); i++) {
        std::cout << std::left << std::setw(COL_WIDTH) << parser.getColumnNames()[i] << " | ";
    }

    std::cout << std::endl;
    for (size_t i = 0; i < parser.getNumColumns(); i++) {
        std::cout << "|" << std::string(COL_WIDTH + 2, '-');
    }
    std::cout << "|" << std::endl;

    for (size_t i = 0; i < parser.getNumRows(); i++) {
        std::cout << "| " << std::left << std::setw(COL_WIDTH) << parser.getString(i, "Nom de l'element");
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << parser.getInt(i, "Numero atomique");
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << parser.getString(i, "Symbole");
        std::cout << " | " << std::right << std::setw(COL_WIDTH) << parser.getDouble(i, "Masse atomique");

        std::cout << " | " << std::endl;
    }

    std::cout << std::string((COL_WIDTH + 3) * parser.getNumColumns() + 1, '-') << std::endl;

    return 0;
}
```

Ce code devrait afficher les éléments du tableau périodique. Voici un extrait du résultat attendu:

```text
| Nom de l'element | Numero atomique  | Symbole          | Masse atomique   |
|------------------|------------------|------------------|------------------|
| Hydrogene        | 1                | H                |          1.00798 |
| Helium           | 2                | He               |           4.0026 |
| Lithium          | 3                | Li               |           6.9395 |
| Beryllium        | 4                | Be               |          9.01218 |
| Bore             | 5                | B                |          10.8135 |
| Carbone          | 6                | C                |          12.0106 |
| Azote            | 7                | N                |          14.0069 |
| Oxygene          | 8                | O                |          15.9994 |
| Fluor            | 9                | F                |          18.9984 |
```

### Étape 3 - Conversion de la matrice de `string` en vecteur d'`Element`

Vous êtes maintenant en mesure d'importer les données d'un fichier CSV dans votre programme. Une matrice de `string` n'est cependant pas idéale pour travailler sur les éléments du tableau périodique. Vous allez donc convertir cette matrice en vecteur d'`Element`!

Voici le code de la classe `Element` à utiliser. Elle diffère légèrement de celle que vous avez implémentée dans le Laboratoire 03.

**Fichier `Element.h`**

```cpp
#pragma once

#include <string>

class Element {
private:
    std::string _nom;
    int _numeroAtomique;
    std::string _symbole;
    double _masseAtomique;

public:
    Element() : Element("", 0, "", 0) {}
    Element(const std::string& nom, int numeroAtomique, const std::string& symbole, double masseAtomique);

    const std::string& getNom() const;
    int getNumeroAtomique() const;
    const std::string& getSymbole() const;
    double getMasseAtomique() const;

    void setNom(const std::string& nom);
    void setNumeroAtomique(int numeroAtomique);
    void setSymbole(const std::string& symbole);
    void setMasseAtomique(double masseAtomique);

    bool operator==(const Element& other) const;
};
```

**Fichier `Element.cpp`**

```cpp
#include "Element.h"

Element::Element(const std::string& nom, int numeroAtomique, const std::string& symbole, double masseAtomique) {
    this->_nom = nom;
    this->_numeroAtomique = numeroAtomique;
    this->_symbole = symbole;
    this->_masseAtomique = masseAtomique;
}

const std::string& Element::getNom() const {
    return this->_nom;
}

int Element::getNumeroAtomique() const {
    return this->_numeroAtomique;
}

const std::string& Element::getSymbole() const {
    return this->_symbole;
}

double Element::getMasseAtomique() const {
    return this->_masseAtomique;
}

void Element::setNom(const std::string& nom) {
    this->_nom = nom;
}

void Element::setNumeroAtomique(int numeroAtomique) {
    this->_numeroAtomique = numeroAtomique;
}

void Element::setSymbole(const std::string& symbole) {
    this->_symbole = symbole;
}

void Element::setMasseAtomique(double masseAtomique) {
    this->_masseAtomique = masseAtomique;
}

bool Element::operator==(const Element& other) const {
    return this->_symbole == other._symbole
        && this->_numeroAtomique == other._numeroAtomique
        && this->_nom == other._nom
        && this->_masseAtomique == other._masseAtomique;
}
```

Vous devez maintenant créer une nouvelle classe `TableauPeriodique`. Voici la définition de cette classe:

```cpp
#pragma once

#include <vector>
#include "CSVParser.h"
#include "Element.h"
// #include "Molecule.h"

class TableauPeriodique {
private:
    CSVParser _parser;
    std::vector<Element> _elements;
    // bool _estTrieParNom;
public:
    TableauPeriodique();
    void charger(const std::string& nomFichier);
    //void afficher(std::ostream& sortie);
    // void trierParNom();
    // void trierParNumeroAtomique();
    const Element& trouverElementParSymbole(const std::string& symbole) const;
    // const Element& trouverElementParNom(const std::string& nom) const;
    // const Element& trouverElementParNumeroAtomique(int numeroAtomique) const;
    // Molecule creerMolecule(const std::string& formule) const;
};

// std::ostream& operator<<(std::ostream& sortie, TableauPeriodique& tableauPeriodique);
```

Plusieurs lignes sont commentées, vous les décommenterez lors d'étapes ultérieures.

Pour le moment, implémentez seulement le constructeur et la méthode `charger`. Le constructeur doit configurer le `parser` selon les caractéristiques du fichier `elements.csv`. La méthode `charger` doit pour sa part ouvrir le fichier CSV correspondant à `nomFichier`, utiliser `_parser` pour récupérer ses données, puis insérer tous les éléments dans `_elements`. N'oubliez pas de fermer le fichier!

Appelez la méthode `charger` dans votre `main` et utilisez le débogueur pour vérifier que le tableau d'éléments est rempli correctement.

### Étape 4 - Méthode `trouverElementParSymbole`

Implémentez maintenant la méthode `trouverElementParSymbole`. Celle-ci doit retourner l'`Element` correspondant au symbole reçu en paramètre, ou lancer une exception `std::invalid_argument` si ce symbole est introuvable.

Pour ce faire, vous implémenterez un algorithme dit de [recherche séquentielle](https://fr.wikipedia.org/wiki/Recherche_s%C3%A9quentielle) ou linéaire. Cet algorithme, le plus simple des algorithmes de recherche, consiste simplement à itérer sur les éléments du tableau jusqu'à ce qu'on ait trouvé celui qui correspond à l'objet recherché. Vous avez déjà utilisé cet algorithme à plusieurs reprises sans le savoir, notamment dans la méthode `getColumnIndex` de votre classe `CSVParser`.

### Étape 5 - Classe `Molecule` et méthode `creerMolecule`

Voici une classe `Molecule` à ajouter à votre projet. Celle-ci permet de représenter une molécule constituée de plusieurs éléments avec le nombre d'atomes pour chacun.

**Fichier `Molecule.h`**

```cpp
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Element.h"

class Molecule
{
private:
    struct ElementMolecule
    {
        Element element;
        int _nombreAtomes;
    };

    std::vector<ElementMolecule> _elements;
    std::string _formule;
public:
    Molecule() : Molecule("", std::vector<Element>(), std::vector<int>()) {}
    Molecule(const std::string& formule, const std::vector<Element>& elements, const std::vector<int>& nombreAtomes);

    const std::string& getFormule() const;
    size_t getNombreElements() const;

    const Element& getElement(size_t indice) const;
    int getNombreAtomes(size_t indice) const;
    int getNombreAtomes(const std::string& symbole) const;
    int getNombreAtomes(const Element& element) const;
};

std::ostream& operator<<(std::ostream& output, const Molecule& molecule);
```

**Fichier `Molecule.cpp`**

```cpp
#include "Molecule.h"

Molecule::Molecule(const std::string& formule, const std::vector<Element>& elements, const std::vector<int>& nombreAtomes) {
    this->_formule = formule;
    for (size_t i = 0; i < elements.size(); ++i) {
        ElementMolecule elementMolecule;
        elementMolecule.element = elements[i];
        elementMolecule._nombreAtomes = nombreAtomes[i];
        this->_elements.push_back(elementMolecule);
    }
}

const std::string& Molecule::getFormule() const {
    return this->_formule;
}

size_t Molecule::getNombreElements() const {
    return this->_elements.size();
}

const Element& Molecule::getElement(size_t indice) const {
    return this->_elements[indice].element;
}

int Molecule::getNombreAtomes(size_t indice) const {
    return this->_elements[indice]._nombreAtomes;
}

int Molecule::getNombreAtomes(const std::string& symbole) const {
    for (const auto& elementMolecule : this->_elements) {
        if (elementMolecule.element.getSymbole() == symbole) {
            return elementMolecule._nombreAtomes;
        }
    }
    return 0;
}

int Molecule::getNombreAtomes(const Element& element) const {
    return this->getNombreAtomes(element.getSymbole());
}

std::ostream& operator<<(std::ostream& output, const Molecule& molecule) {
    output << molecule.getFormule();
    return output;
}
```

Dans le fichier `TableauPeriodique.h`, décommentez la ligne `#include "Molecule.h"` de même que la définition de la méthode `creerMolecule`. Voici l'implémentation à ajouter dans `TableauPeriodique.cpp`:

```cpp
Molecule TableauPeriodique::creerMolecule(const std::string& formule) const {
    vector<Element> elements;
    vector<int> nombreAtomes;

    size_t i = 0;
    while (i < formule.size())
    {
        if (isalpha(formule[i])) {
            string symbole(1, formule[i]);
            i++;
            if (i < formule.size() && isalpha(formule[i]) && islower(formule[i])) {
                symbole += formule[i];
                i++;
            }
            const Element& element = this->trouverElementParSymbole(symbole);
            elements.push_back(element);

            int nombre = 0;
            while (i < formule.size() && isdigit(formule[i])) {
                nombre = nombre * 10 + (formule[i] - '0');
                i++;
            }
            if (nombre == 0) {
                nombre = 1;
            }
            nombreAtomes.push_back(nombre);
        } else {
            throw invalid_argument("Formule chimique invalide.");
        }
    }

    return Molecule(formule, elements, nombreAtomes);
}
```

Voici un exemple d'utilisation de cette méthode. Ajoutez-le dans le `main` et assurez-vous que vous obtenez le bon résultat.

```cpp
TableauPeriodique tableauPeriodique;
tableauPeriodique.charger("../elements.csv");

Molecule eau = tableauPeriodique.creerMolecule("H2O");
std::cout << "Une molécule d'eau contient "
            << eau.getNombreAtomes("H") << " atomes d'" << eau.getElement(0).getNom() << " et "
            << eau.getNombreAtomes("O") << " atome d'" << eau.getElement(1).getNom() << "."
            << std::endl;
```

Pour vous assurer que vous comprenez comment utiliser la classe `Molecule` et la méthode `creerMolecule`, créez un programme qui demande à l'utilisateur d'entrer la formule d'une molécule, puis qui affiche, pour chaque élément de la molécule, son numéro atomique, son nom et le nombre d'atomes de cet élément dans la molécule.

**⚠️ Faites valider votre laboratoire 06-A par l'enseignant.**

## Laboratoire 06-B - Algorithmes de tri et de recherche

Cette partie se fait dans le même projet que la partie A. **Il est cependant recommandé d'en effectuer une copie pour vous assurer de conserver une version fonctionnelle en vue du laboratoire de chimie.**

Dans cette partie, vous implémenterez différents algorithmes de tri et de recherche sur le tableau périodique.

### Étape 1 - Ajout d'un menu

En utilisant votre classe `Menu` des laboratoires précédents, générez le menu suivant dans le `main`:

```text
Tableau périodique

MENU
====================
1. Charger le tableau périodique
2. Afficher le tableau périodique
3. Trier le tableau périodique par nom
4. Trier le tableau périodique par numéro atomique
5. Trouver un élément par son symbole
6. Trouver un élément par son nom
7. Trouver un élément par son numéro atomique
8. Quitter

Choisir une option:
```

Faites en sorte que l'option 1 appelle la méthode `charger` du tableau périodique.

Voici le code de la méthode `afficher` à implémenter dans `TableauPeriodique` pour faire fonctionner l'option 2. Vous devez aussi ajouter `#define COL_WIDTH 16` au début du fichier, et inclure `iomanip`.

```cpp
void TableauPeriodique::afficher(std::ostream& sortie) {
    for (Element element : this->_elements) {
        std::cout << "| " << std::left << std::setw(COL_WIDTH) << element.getNom();
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << element.getNumeroAtomique();
        std::cout << " | " << std::left << std::setw(COL_WIDTH) << element.getSymbole();
        std::cout << " | " << std::right << std::setw(COL_WIDTH) << element.getMasseAtomique();

        std::cout << " | " << std::endl;
    }
}
```

## Laboratoire 06-C - Algorithme récursif dans une matrice

À venir
