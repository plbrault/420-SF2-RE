# Laboratoire 02

## Objectif

Débuter l'intégration des concepts de base de la programmation orientée objet en créant nos premières classes pour ensuite les utiliser dans notre code.

## Pourquoi les classes ?

Si nous regardons les deux derniers laboratoires, nous avons codé une petite application qui gère une liste de tâches. Une tâche est définie par sa description et par sa complétion (est-ce que la tâche a été complétée ou non). On pourrait donc dire qu'une tâche possède deux variables : `description` et `estCompletee`. Si nous voulons gérer plus d'une tâche, nous allons donc utiliser deux tableau : `taches` qui contient les description et `tacheCompletee` qui contient la completion. Regardons ensemble les prototypes de nos fonction du laboratoire #1 :

```cpp
void afficherMenu();
int demanderChoix(int max);
void afficherListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void ajouterTache(std::string taches[], int nombreTaches);
int demanderNumeroTache(std::string texte, int nombreTaches);
void marquerFaite(std::string taches[], bool tacheCompletee[], int nombreTaches);
void echangerTaches(std::string taches[], bool tacheCompletee[], int nombreTaches);
void supprimerTache(std::string taches[], bool tacheCompletee[], int &nombreTaches);
void sauvegarderListe(std::string taches[], bool tacheCompletee[], int nombreTaches);
void chargerListe(std::string taches[], bool tacheCompletee[], int& nombreTaches);
```

Le fait d'avoir deux tableaux à gérer alourdit déjà considérablement les paramètres de nos fonctions. Imaginez maintenant si on voulait qu'une tâche ait en plus une date de création, une date limite, un titre (plus cours que la description) et une priorité (basse, moyenne, haute). Voici à quoi ressembleraient nos prototypes:

```cpp
void afficherListe(std::string taches[], bool tacheCompletee[], std::string dateCree[], std::string dateLimite[], std::string titre[], int priorite[], int nombreTaches);
```

Cela commence à faire beaucoup !

> NOTE - On devrait essayer de limiter le nombre de paramètres à 4 dans un prototype, si possible.

À mesure que les besoins de l'application évolueront, on risque de se retrouver avec encore plus de variables. Le code deviendra donc de plus en plus difficile à maintenir si on doit ajouter à chaque fois un nouveau tableau à toutes nos méthodes.

Existe-t-il une méthode plus adéquate pour gérer cette situation? Eh oui, il s'agit bien entendu de la **Programmation orientée objet**!

## Création d'une classe `Tache`

Créez un nouveau projet contenant seulement un `main` vide. Suivez ensuite les étapes suivantes pour créer et utiliser votre première classe dans ce projet.

Nous savons qu'une `Tache` se définit par sa `description` et par sa complétion (`estCompletee`). On pourrait donc représenter graphiquement cette **entité** de cette façon:

```plantuml
@startuml
class Tache {
    std::string description
    bool estCompletee
}
@enduml
```

En C++, on peut décrire cette entité à l'aide d'une **classe**. Créez un fichier `tache.h` et ajoutez-y la définition de la classe:

```cpp
#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
public:
    std::string description;
    bool estCompletee;
};

#endif
```

> Ignorez pour l'instant les lignes 1, 2 et la dernière ligne, elles font à peu près la même chose que `#pragma once`. Notre classe commence à la ligne 6 et se termine avant le `#endif`. Remarquez que la définition d'une classe doit se terminer par un `;`.

Nous avons deux variables qui représentent notre tâche. Dans le contexte d'une classe, une variable se nomme **un attribut**. Pour l'instant, le terme `public` signifie que l'on peut manipuler les attributs définis en-dessous.

Utilisez maintenant votre nouvelle classe dans le `main` :

```cpp
#include <iostream>

#include "tache.h"

int main () {
    std::locale::global(std::locale{ "" });

    Tache maTache;
    maTache.description = "Compléter le laboratoire 2";
    maTache.estCompletee = false;

    std::cout << "[" << (maTache.estCompletee ? 'X' : ' ') << "] " << maTache.description << std::endl;

    return 0;
}
```

Ici, `maTache` est un **objet** qui est une **instance** de la classe `Tache`, et il peut être conceptualisé comme une variable qui contient des variables liées entre elles.

On peut également créer un tableau d'objets de la classe `Tache`. Ce tableau aura l'avantage de remplacer les deux tableaux `taches` et `tacheCompletee`. Modifiez votre `main` de cette façon:

```cpp
#include <iostream>

#include "tache.h"

int main () {
    std::locale::global(std::locale{ "" });

    Tache taches[100];

    int quantite = 0;
    bool terminee = false;

    std::string description;
    std::string reponseCompletee;

    do {
        std::cout << "Décrivez votre tâche : ";
        std::getline(std::cin, taches[quantite].description);
        std::cout << std::endl;
        std::cout << "Est-elle complétée ? [O|N] ";
        std::getline(std::cin, reponseCompletee);
        taches[quantite].estCompletee = reponseCompletee.compare("O") == 0;

        std::cout << "Voulez vous continuez ? [O|N] ";
        std::getline(std::cin, reponseCompletee);
        terminee = reponseCompletee.compare("O") != 0;
        quantite++;

    } while(quantite < 100 && !terminee);

    for (int i = 0; i < quantite; i++) {
        std::cout << "[" << (taches[i].estCompletee ? 'X' : ' ') << "] " << taches[i].description << std::endl;
    }

    return 0;
}
```

Ainsi, nous pourrions remplacer les prototypes de fonctions du laboratoire 1 avec ceux-ci (**Ne le faites pas, il s'agit d'un exemple**) :

```cpp
void afficherMenu();
int demanderChoix(int max);
void ajouterTache(Tache taches[], int nombreTaches);
int demanderNumeroTache(std::string texte, int nombreTaches);
void marquerFaite(Tache taches[], int nombreTaches);
void echangerTaches(Tache taches[], int nombreTaches);
void supprimerTache(Tache taches[], int &nombreTaches);
void sauvegarderListe(Tache taches[], int nombreTaches);
void chargerListe(Tache taches[], int& nombreTaches);
```

Dans le contexte du laboratoire 1, on peut voir deux avantages à utiliser les objets:

- On peut utiliser un seul tableau au lieu de deux.
- Si on doit ajouter plus tard d'autres attibuts à notre classe `Tache`, **nous n'aurons pas besoin de changer nos prototypes**.

### Peut-on créer une tâche d'un seul coup ?

Regardons comment nous avons instancié notre classe et initialisé les attributs de notre objet :

```cpp
    Tache maTache;
    maTache.description = "Compléter le laboratoire 2";
    maTache.estCompletee = false;
```

C'est agréable, mais si nous ajoutions plusieurs autres attributs, il pourrait devenir un peu fastidieux de faire toutes les assignations une par une. Heureusement pour nous, il existe le concept de **constructeur** qui nous permet d'initialiser nos attributs à la déclaration de l'objet

Retournons dans notre fichier `tache.h` et ajoutons-y deux constructeurs : un constructeur par défaut et un constructeur qui, dans notre présent cas, recevra les paramètres `description` et `estCompletee`.

```cpp
#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
public:
    std::string description;
    bool estCompletee;

    Tache();
    Tache(std::string description, bool estCompletee);
};

#endif
```

Un constructeur **doit** toujours avoir le même nom que la classe. Il s'agit d'une méthode spéciale qui est appelée lors de l'instanciation d'un objet de notre classe. Dans notre cas, nous avons deux constructeurs : un constructeur par défaut (sans paramètre) et un constructeur qui nous permet d'initialiser tous les attributs de notre instance. Toutefois, dans notre fichier d'en-tête `.h`, nous avons seulement ajouté les prototypes des constructeurs. Il nous reste maintenant à les implémenter (c'est-à-dire, écrire le code de nos constructeurs) pour initialiser notre objet. 

Créez un fichier `tache.cpp` avec le code suivant :

```cpp
#include "tache.h"

Tache::Tache() {
    this->description = "";
    this->estCompletee = false;
}

Tache::Tache(std::string description, bool estCompletee) {
    this->description = description;
    this->estCompletee = estCompletee;
}

```

> Concept : `this` - Comme nous l'avons déjà dit, la classe est une description : si je n'instancie pas d'objet de cette classe dans mon code, ce code ne sera jamais exécuté. Mais si j'instancie deux instances, comment faire la distinction entre les deux ? Voici un exemple :
> ```cpp
> int main () {
>     std::locale::global(std::locale{ "" });
> 
>     Tache premiere("Comprendre les classes", false);
>     Tache seconde("Comprendre les constructeurs", false);
> 
>     return 0;
> }
> ```
> En plus d'initialiser notre tâche d'un coup, il faut comprendre que chacun des objets (`premiere` et `seconde`) est dans un espace mémoire distinct, et qu'il a ses propres valeurs de `description` et `estComplette`. Toutefois, on ne peut pas connaître d'avance le nom de toutes les instances de notre classe. C++ nous offre donc `this`, qui est **un pointeur** vers l'instance en cours. Donc, quand je suis dans le constructeur de `seconde`, `this` pointe à la même case mémoire que `seconde` et peut donc accéder aux attributs `description` et `estCompletee` de celui-ci!

> Pour vous convaincre que `this` est un pointeur, sachez qu'on peut réécrire notre constructeur de cette façon :
> ```cpp
> #include "tache.h"
> 
> Tache::Tache(std::string description, bool estCompletee) {
>     *this.description = description;
>     *this.estCompletee = estCompletee;
> }
> 
> ```
> Ici, on utilise le déréférencement (`*this`) et on obtient donc un objet de l'instance `Tache`. On peut donc utiliser le `.` au lieu de `->`.

Voici un *diagramme de classe* qui représente notre `Tache` :

```plantuml
@startuml
class Tache {
    std::string description
    bool estCompletee

    Tache();
    Tache(std::string description, bool estCompletee)
}
@enduml
```

### Les méthodes

Donc, maintenant que nous avons une classe qui contient des attributs (variables) liés entre eux - une sorte de contenant qui définit une **entité** -, qu'est-ce que la **Programmation orientée objet** nous offre pour nous aider ? Elle nous offre entre autres le concept de **méthode**.

Pour comprendre ce qu'est une **méthode**, il faut se poser la question suivante : quelles sont les actions que je veux poser sur une instance de ma classe considérant ses attributs ? Par exemple, un objet de classe `Tache` pourrait posséder les actions suivantes :

* marquer comme complétée (« cocher ») ;
* marquer comme non complétée (« décocher ») ;
* changer la description (et valider que la longueur est au maximum 32 caractères) ;
* afficher la tâche à l'utilisateur (selon notre modèle `numéro [X] description`).

Comme ce sont des actions que l'on peut faire sur une tâche, on va vouloir créer des fonctions dans la classe : on les appelle les **méthodes**.

Modifiez le code de votre fichier `tache.h` de cette façon:

```cpp
#ifndef TACHE_H
#define TACHE_H

#include <string>

/* 
   On ajoute une constante ici pour définir le nombre de caractères maximal
   d'une description de tâche. Cette constante sera accessible dans le
   fichier .cpp.
*/
#define DESCRIPTION_CARACTERE_LIMITE 32

class Tache {
public:
    std::string description;
    bool estCompletee;
    Tache() : Tache("", false) { };
    Tache(std::string description, bool estCompletee);

    void marquerCompletee();
    void marquerNonCompletee();
    void changerDescription(const std::string &);
    std::string obtenirChaine(int indiceTache);
};

#endif
```

> Remarquez que notre constructeur par défaut utilise maintenant le second constructeur, ce qui réduit le code et le potentiel d'erreurs.

Donc notre classe `Tache` se conceptualise comme ceci :

```plantuml
@startuml
class Tache {
    std::string description
    bool estCompletee

    Tache();
    Tache(std::string description, bool estCompletee)

    void marquerCompletee()
    void marquerNonCompletee()
    void changerDescription(const std::string &description)
    std::string obtenirChaine(int indiceTache)
}
@enduml
```

On doit maintenant implémenter nos méthodes dans le fichier `tache.cpp`. Remplacez le contenu de ce fichier par celui-ci:


```cpp
#include "tache.h"

#include <sstream>

Tache::Tache(std::string description, bool estCompletee) {
    this->description = description;
    this->estCompletee = estCompletee;
}

void Tache::marquerCompletee() {
    this->estCompletee = true;
}

void Tache::marquerNonCompletee() {
    this->estCompletee = false;
}

void Tache::changerDescription(const std::string &description) {
    // On s'assure que la chaine ne sera pas trop longue
    if (description.length() < DESCRIPTION_CARACTERE_LIMITE) {
        this->description = description;
    } else {
        this->description = description.substr(0, DESCRIPTION_CARACTERE_LIMITE);
    }
}

std::string Tache::obtenirChaine(int indiceTache) {
    /*
    Un `ostringstream` permet de construire une chaîne de caractères en concaténant
    des données qui peuvent être de différents types. Il s'utilise de façon similaire
    à l'objet `cout`. On obtient la chaîne de caractères finale avec la méthode `str()`.
    */
    std::ostringstream flux;

    flux << indiceTache << " [" << (this->estCompletee ? 'X' : ' ') << "] " << this->description;

    return flux.str();
}

```

Modifiez ensuite le contenu de votre `main` de cette façon.

```cpp
int main () {
    std::locale::global(std::locale{ "" });

    Tache *taches;
    taches = new Tache[100];

    int quantite = 0;
    bool terminee = false;

    std::string description;
    std::string reponseCompletee;
    bool estCompletee;

    do {
        std::cout << "Décrivez votre tâche : ";
        std::getline(std::cin, description);
        std::cout << std::endl;
        std::cout << "Est-elle complétée ? [O|N] ";
        std::getline(std::cin, reponseCompletee);
        estCompletee = reponseCompletee.compare("O") == 0;

        Tache courante(description, estCompletee);
        taches[quantite] = courante;

        std::cout << "Voulez vous continuer ? [O|N] ";
        std::getline(std::cin, reponseCompletee);
        terminee = reponseCompletee.compare("O") != 0;
        quantite++;

    } while(quantite < 100 && !terminee);

    for (int i = 0; i < quantite; i++) {
        std::cout << taches[i].obtenirChaine(i + 1) << std::endl;
    }

    delete [] taches;

    return 0;
}
```

Donc alors qu'avant nous avions des fonctions qui recevait un ou des objets en paramètres, l'objet lui-même sera **responsable** de faire ses actions car la classe est le **propriétaire de ses attributs**.

> Il y a, dans notre classe `Tache`, une incongruité concernant la limite de 32 caractères. Avec ce code, il y a deux manière de changer la `description` et mettre plus de 32 caractères dedans. Pouvez-vous les identifier ?

### On veut protéger nos données

Parlons maintenant du mot clé `public` que nous avons laissé un peu à lui-même et qui fait que tout ce qui se trouve en-dessous est accessible dans tout le code. Il s'agit d'un problème si on veut s'assurer que les programmeurs utilisent la bonne méthode pour mettre à jour `description` et ne pas mettre plus de 32 caractères à l'intérieur. Nous avons besoin d'une manière pour cacher, ou rendre *privés*, nos attributs.

C++ nous offre un mot-clé pour cela, `private`, qui nous permet de cacher (**encapsuler**) nos attributs pour que seules les méthodes publiques puissent les manipuler, et ainsi s'assurer que nos *validations* soient toujours prise en compte.

Modifiez donc le fichier `tache.h` de cette façon:

```cpp
class Tache {
private:
    std::string _description;
    bool _estCompletee;
public:
    Tache(std::string description, bool estCompletee);

    void marquerCompletee();
    void marquerNonCompletee();
    void changerDescription(const std::string &)
    std::string obtenirChaine(int indiceTache);
};

#endif
```

> Le mot-clé `private` va cacher les attributs et seules les méthodes de la classe pourront y accéder et les modifier. Notez que dans le manuel utilisé pour le cours, les attributs privés ont un préfixe `m_` alors qu'ici, nous utilisons uniquement le `_`. Sachez qu'il s'agit d'une convention et qu'elle peut différer d'un projet à l'autre, d'un cours à l'autre ou d'une entreprise à l'autre. Nous pourrions également ne rien mettre comme préfix. On vous demande cependant, dans le cadre du cours, de suivre la nomenclature décrite dans les standards de programmation sur la page *Moodle*.

Changez maintenant le contenu de votre fichier `tache.cpp` par celui-ci:

```cpp
#include "tache.h"

#include <sstream>

Tache::Tache(std::string description, bool estCompletee) {
    this->_description = description;
    this->_estCompletee = estCompletee;
}

void Tache::marquerCompletee() {
    this->_estCompletee = true;
}

void Tache::marquerNonCompletee() {
    this->_estCompletee = false;
}

void Tache::changerDescription(const std::string &description) {
    if (description.length < DESCRIPTION_CARACTERE_LIMITE) {
        this->_description = description;
    } else {
        this->_description = description.substr(0, DESCRIPTION_CARACTERE_LIMITE);
    }
}

std::string Tache::obtenirChaine(int indiceTache) {
    std::ostringstream flux;

    flux << indiceTache << " [" << (this->_estCompletee ? 'X' : ' ') << "] " << this->_description;

    return flux.str();
}

```

**Rien n'a changé**, à l'exception de la *refactorisation* de notre code avec les nouveaux noms d'attributs. Puisque nos méthodes ont accès a nos attributs privés, rien d'autre ne change.

> Le terme « refactorisation » désigne une modification du code qui ne change pas son comportement externe.

Regardons ce qui se passe dans notre fonction `main` quand on veut compiler le code suivant :

```cpp
#include <iostream>

#include "tache.h"

int main () {
    std::locale::global(std::locale{ "" });

    Task maTache;
    maTache._description = "Compléter le laboratoire 2";
    maTache._estCompletee = false;

    std::cout << "[" << (maTache._estCompletee ? 'X' : ' ') << "] " << maTache._description << std::endl;

    return 0;
}
```

Si vous essayez de compiler ce code, vous obtiendrez sans doute une erreur, parce que le `main` tente d'accéder à (et même modifier) des membres privés de la classe `Tache`. Cela est interdit.

Voici à quoi `Tache` ressemble dans un diagramme de classe en tenant compte des modificateurs d'accès `private` et `public`.

```plantuml
@startuml
class Tache {
    - std::string _description
    - bool _estCompletee

    + Tache(std::string description, bool fait)

    + void marquerCompletee()
    + void marquerNonCompletee()
    + void changerDescription(const std::string &description)
    + std::string obtenirChaine(int indiceTache)
}
@enduml
```

Félicitations, vous avez maintenant une classe `Tache` solide qui cache ses attributs afin de gérer et valider le contenu qu'on leur assigne - on dit que la classe **encapsule** ses attributs. Nous sommes en mesure de créer une tâche vide, mais également de créer une tâche en spécifiant la valeur de chaque attribut, et nous avons 4 méthodes qui manipulent nos attributs ou les utilisent.

## Création d'une classe `Personne`

Nous voulons maintenant ajouter à notre programme le concept d'une personne qui possède un prénom, un nom et une liste de tâches à réaliser. Puisque nous ne savons pas combien de tâches notre personne aura, nous allons utiliser un tableau dynamique à l'aide d'un pointeur. Nous allons voir que cela va apporter son lot de défis dus à l'allocation de mémoire (`new`) et la désallocation de mémoire (`delete`).

Voici un diagramme de classe qui représente notre `Personne`.

```plantuml
@startuml
Personne *-- Tache

class Tache {
    - std::string _description
    - bool _estCompletee

    + Tache()
    + Tache(std::string description, bool estCompletee)

    + void marquerCompletee()
    + void marquerNonCompletee()
    + bool estFait()
    + void changerDescription(const std::string &description)
    + std::string obtenirDescription()
    + std::string obtenirChaine(int indiceTache)
}

class Personne {
    - std::string _prenom
    - std::string _nom

    - size_t _quantite;
    - size_t _taille;
    - Tache *_taches

    + Personne()
    + Personne(const std::string &prenom, const std::string &nom);
    + ~Personne()

    + void changerPrenom(const std::string &prenom);
    + void changerNom(const std::string &nom);

    + void ajouterTache(const Tache &tache)
    + Tache *obtenirTache(size_t indiceTache)
    
    + size_t obtenirNombreTache();

    + void echangerTache(size_t tacheA, size_t tacheB);
    + void supprimerTache(size_t indiceTache);

    + std::string obtenirChaine()

    - _agrandirTableauTaches();
}
@enduml
```

On voit que notre classe `Tache` est maintenant liée à une nouvelle classe `Personne`. Le losange noir signifie que la relation entre les deux en est une de **composition** : on dit que la `Personne` est composée (au moins) d'une `Tache`. Pour ceux qui on l'oeil du Lynx, vous remarquerez qu'un drôle de "constructeur" avec une `~` a été ajouté. On va regarder tout ça de près.

### Étape 1 - Créer la classe Personne

Dans cette étape, il faut créer une classe `Personne` avec seulement :

* les attributs `_nom` et `_prenom`
* les deux constructeurs
* les méthodes `changerPrenom`, `changerNom`, `obtenirNomComplet` et `obtenirChaine`
  * **Référez-vous au diagramme de la classe pour connaître les types de retour et les paramètres attendus pour ces méthodes.**
  * `obtenirChaine` doit retourner la chaîne « *Liste de tâches de `prénom nom` :* », sans saut de ligne.

Tester votre classe dans le `main`.

### Étape 2 - Le destructeur

Nous avons vu dans le laboratoire #1 que les pointeurs sont importants mais un peu dangereux. Si on ne fait pas attention, on peut essayer d'accéder à de la mémoire qui n'est pas valide, ou pire encore perdre l'accès a une zone mémoire complète. Lorsqu'on mélange les classes et les pointeurs, le potentiel d'erreur similaires augmente rapidement. En d'autres mots, il faut être très consciencieux concernant les pointeurs dans une classe.

Reprenons notre classe et ajoutons notre attribut privé `_taches`. On se rend rapidement compte que nous allons avoir besoin d'instancier cet attribut. Il semble évident que les constructeurs seront l'endroit logique pour cette tâche.

Notre fichier `personne.h`:
```cpp
#ifndef __PERSONNE_H
#define __PERSONNE_H

#include <string>
#include <stddef.h>

#include "tache.h"

#define TAILLE_LISTE_TACHE_INC 10

class Personne {
private:
    std::string _prenom;
    std::string _nom;
    Tache *_taches;
    
    size_t _capaciteTableauTaches;
    size_t _quantiteTaches;
    
public:
    Personne() : Personne("", "") { }
    Personne(std::string prenom, std::string nom);

}

#endif
```

Notre fichier `personne.cpp`:

```cpp
#include "personne.h"

Personne::Personne(std::string prenom, std::string nom) {
    this->_prenom = prenom;
    this->_nom = nom;
    
    this->_quantiteTaches = 0;
    this->_capaciteTableauTaches = TAILLE_LISTE_TACHE_INC;
    this->_taches = new Tache[this->_taille];
}
```

Maintenant, nous arrivons à une situation ambigüe : à quel moment allons-nous pouvoir désallouer notre mémoire ?

C++ nous offre une solution: en plus d'avoir la possitilité de créer des constructeurs, on peut aussi ajouter un **destructeur** à notre classe. Celui-ci est appelé automatiquement à la destruction de l'objet (soit à la fin de sa portée en allocation statique, ou lors du `delete` avec l'allocation dynamique).

Pour ajouter un destructeur, ajoutez d'abord un prototype `~Personne()`, sans type de retour, dans la partie `public` de votre fichier `.h`.

Dans votre fichier `.cpp`, ajoutez l'implémentation du destructeur, comme ceci:

```cpp
Personne::~Personne() {
    if (this->_taches != nullptr) {
        delete [] this->_taches;
    }
}
```

On remarque que le destructeur porte le même nom que la classe, préfixé d'un tilde (`~`). Le destructeur ne prendra jamais de paramètres et devra généralement s'acquiter de tâches de libération de ressources, telles que désallouer un pointeur, fermer un fichier, etc.

### Étape 3 - Gérer les tâches

Implémentez maintenant la méthode `ajouterTache` afin de pouvoir ajouter des tâches à une `Personne`. Pour l'instant, assurez-vous que vous êtes en mesure d'en ajouter le nombre défini par `#TAILLE_LISTE_TACHE_INC`.

**N'oubliez pas de vous référer au diagramme pour connaître la signature de la méthode. Cela est vrai pour les étapes subséquentes également.**

Assurez-vous de bien tester votre code avant de passer à l'étape suivante.

### Étape 4 - Agrandir la liste des tâches

Implémentez la méthode `agrandirTableauTache` selon la règle suivante : chaque agrandissement se fait par incrément de `#TAILLE_LISTE_TACHE_INC`. Utilisez cette méthode pour qu'`ajouterTache` l'utilise adéquatement. Assurez-vous de tester votre code avant de passer à l'étape suivante.

> Pourquoi avons-nous mis cette méthode *privée* ?

### Étape 5 - Obtenir la `Tache`

Implémentez la méthode `obtenirTache` qui permet de recevoir une tâche selon son indice. Si l'indice spécifié n'est pas valide, cette méthode doit retourner `nullptr`, sinon elle retourne un pointeur à la `Tache` spécifiée. 

Assurez-vous de tester votre code avant de passer à l'étape suivante. Une technique a prendre est d'essayer, dans votre `main`, d'appeler `marquerCompletee` dans votre instance reçue.

### Étape 6 - Obtenir la chaine

Implémentez la méthode `obtenirChaine` qui affichera la `Personne` suivant ce modèle : 

```
Tâches de André Jacques

1 [ ] Terminer le laboratoire 5
2 [X] Boire de l'eau
3 [ ] Faire la vaiselle
```

Assurez-vous de tester votre code avant de le faire valider par l'enseignant.

## Création d'une classe `Menu`

Voici un diagramme présentant un défi pour la création d'une classe `Menu` qui sera utilisée en continuation au laboratoire #1.

```plantuml
@startuml
class Menu {
    - std::string _titre
    - std::string _question
    - int _selection
    - bool _peutQuitter

    - std::string _options[18]
    - size_t _quantiteOptions

    + Menu(const std::string &titre, const std::string &question)
    + Menu(const std::string &titre, const std::string &question, bool peutQuitter)
    + void ajouterOption(const std::string &option)
    + bool validerSelection(int indiceOption)
    + int obtenirSelection()
    + int valeurMaximale(void)
    + std::string obtenirChaine()
}
@enduml
```

### Étape 1 - Implémenter la classe `Menu`

* Les constructeurs doivent initialiser `_titre`, `_question` et `_peutQuitter` selon les paramètres reçus (le premier constructeur considère `_peutQuitter` à `false`). Réfléchissez à `_selection` et `_quantiteOptions`.
* `ajouterOption` doit ajouter une option au menu et ne doit pas dépasser 18 (ce n'est pas un un tableau dynamique)
* `validerSelection` doit regarder l'`indiceOption` reçu et s'assurer que c'est une option valide. Retourne `true` si valide, `false` sinon. N'oubliez-pas que la taille du tableau ne sera pas la bonne valeur si `_peutQuitter` est `true`.
* `obtenirSelection` retourne `-1` si pas de sélection valide, sinon retourne le dernier `indiceOption` reçu par `validerSelection`.
* `valeurMaximale` retourne la valeur maximal d'options possible.
* `obtenirChaine` reproduit le menu avec le titre, les items avec numéro, ainsi que la question **sans saut de ligne à la fin**.

### Étape 2 - Modifier le laboratoire #1

Reprenez vos fonctions du laboratoire 1, puis changez-les de telle sorte que les prototypes dans `fonctions.h` soient :

```cpp
Menu construireMenuPrincipal(void);
void afficherMenu(Menu &);
int demanderChoix(Menu &menu);
void afficherListe(Personne &);
void ajouterTache(Personne &);
int demanderNumeroTache(std::string, Personne &);
void marquerFaite(Personne &);
void echangerTaches(Personne &);
void sauvegarderListe(Personne &);
void chargerListe(Personne &);
void supprimerTache(Personne &);
```

Remarquez qu'une nouvelle fonction, `construireMenuPrincipal()`, doit être implémentée. Celle-ci doit créer un objet `Menu` avec le même menu qu'au laboratoire #1.
