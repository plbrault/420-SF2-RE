# Laboratoire de préparation d'examen

Durant votre parcours en *SIM*, vous avez eu la chance de programmer en **C++** et utiliser la classe `std::string`. Sans le savoir, vous utilisiez la *POO* avec des objets d'instance `std::string`, les construisaient (constructeur), les concaténaient (`+`), les assignaient (`=`), les affichaient (`<<`), etc. Vous vous doutez bien que la classe `std::string` utilise un tableau de charactère (`char`) et doit suivre les mêmes règles que nous avons vue en classe.

Pour votre préparation à l'examen, on vous demande de faire une classe `String` dans votre propre `namespace` que l'on nomera `sim`. Cette classe devra offrir quelques éléments de base important calqué du comportement de `std::string`. On peut enfin avoir une idée de son fonctionnement interne.

## Étape 1 : Créer son propre `namespace`

Cette étape est raisonnablement trivial, il faut simplement entourer, dans notre `string.h` et `string.cpp`, nos déclarations de classes et implémentations de nos différentes méthodes et fonctions amies. Voici un exemple.

```cpp
// Fichier maclasse.h
#ifndef __MACLASSE_H
#define __MACLASSE_H

namespace sim {

    class MaClasse {
    // ...
    };

}

#endif

// Fichier maclasse.cpp
#include "maclasse.h"

namespace sim {

    MaClasse::MaClasse() {
        // ...
    }

}
```

Et voilà, si vous utilisez `using namespace std` dans votre code, vous pouvez toujours faire référence à notre classe à nous en instanciant notre objet avec `sim::String maString;`.

## Étape 2 - Règles à suivre pour notre classe

Voici une liste de règles à garder en mémoire lors de l'élaboration de notre classe `String`. Nous allons y référer tout au long du laboratoire, il est donc important de vous y familiariser.

1. Une chaine de caractères doit se terminer par le charactère nulle (`'\0'`). Cela signifie que, pour la chaîne `"Allo"`, notre tableau de charactères doit avoir 5 cases : `['A', 'l', 'l', 'o', '\0']`.
1. On ne vas pas gérer de capacité. Cela signifie que la majorité des interactions nécessite de créer un nouveau tableau et détruire l'ancien.
1. On ne peut pas changer un caractère individuellement. Cela implique de réfléchir aux accès de chaque caractère.
1. On doit supporter les `char *` et les `sim::String`. Cela signifie que plusieurs membres (constructeur, surcharge d'opérateur) devront être doublés.
1. On ne doit pas faire un tableau de charactère si la chaine est vide. Cela signifie que l'on doit porter une attention particulière lors de l'allocation du pointeur et sa désallocation.

> Prenez note qu'une seule règle n'est plus respecté dans la classe `std::string`, mais pour vous donner un défi intéressant a été conservé. Pouvez-vous identifier laquelle ?

## Étape 3 - Les attributs et les constructeurs

Nous allons commencer tranquillement et implémenter la classe avec les membres suivantes :

```plantuml
@startuml
class sim::String {
    - char *_str
    - size_t _length

    + String()
    + String(const char *c_str)
    + String(const String &str)
    + String(size_t repetition, char chr)
    + ~String()

    + friend std::ostream &operator<<(std::ostream &os, const sim::String &str)
}
@enduml
```

L'objectif est de s'assurer que nos constructeurs fonctionnent adéquatement avant de passer à autre chose. Nous pouvons tester de cette manière :

```cpp
// main.cpp
#include <iostream>
#include "string.h"

int main () {
    sim::String emptyString;

    // devrait afficher 'Chaine vide : '
    std::cout << "Chaine vide : " << emptyString << std::endl;

    sim::String myString("Bien le bonjour SIM.");

    // devrait afficher 'Ma chaine : Bien le bonjour SIM.'
    std::cout << "Ma chaine : " << myString << std::endl;   

    sim::String myCopy(myString);

    // devrait afficher 'Ma chaine : Bien le bonjour SIM.'
    std::cout << "Ma chaine : " << myCopy << std::endl;

    sim::String myDashes(15, '-');

    // devrait afficher 'Ma chaine : ---------------'
    std::cout << "Ma chaine : " << myDashes << std::endl;

    return 0;
}
```

## Étape 4 - Ajout du membre manquant lors de la manipulation de pointeur dans une classe

Nous savons que l'élaboration d'une classe qui possède un pointeur à l'intérieur requiert minimalement trois éléments : la définition d'un *constructeur de copie* et d'un *destructeur*. Quel est le troisième membre manquant ? N'oubliez-pas de respecter la règle #4.

## Étape 5 - Rendre l'attribut `_length` accessible en lecture seulement.

Il est très pertinent, dans une application utilisant des chaînes, qu'on ait besoins d'en connaître sa taille. Il faut donc permettra sa lecture.

## Étape 6 - Opérateur d'indexation

Nous aimerions être en mesure de regarder les charactères une à une. Pour ce faire, il faut surcharger l'opérateur `operator[]` de manière adéquate tout en respecter la règle #3.

## Étape 7 - Concaténation de chaine

Une des actions les plus triviales est de concaténer deux chaines ensembles, par exemple un `prénom` et un `nom`. Il faut surcharger les opérateurs `+=` et `+` en tenant compte des règles #2 et #3.

## Étape 8 - (Avancé) Amélioration du code

Il y a de bonne chance que votre code ait plusieurs composantes utilisant les mêmes bout de code, par exemple la gestion de la désallocation (règle #2). En plus de cette dernière, vous devriez être en mesure d'en identifier deux autres.
