# Laboratoire 07

## Objectif

Mettre en pratique l'utilisation d'une liste de la STL.

## Introduction

Ce laboratoire comprend une seule partie. Elle consiste à reprendre votre programme du Laboratoire 05 qui gère une liste de températures, et à le modifier afin de remplacer le tableau dynamique actuel par une liste de la STL. Certaines améliorations au fonctionnement du programme seront également apportées.

La première étape du laboratoire rendra impossible la compilation du programme jusqu'à ce que la plupart des étapes suivantes soient complétées. N'hésitez pas à mettre du code en commentaire afin d'être en mesure de tester vos modifications au fur et à mesure.

La [documentation de std::list](https://en.cppreference.com/w/cpp/container/list.html) vous sera utile pour faire ce laboratoire.

## Étape 1

Dans la classe `TemperatureHistory`, remplacez le pointeur `_datapoints` par une liste. Retirez également les attributs `_size` et `_capacity`.

## Étape 2

Puisque la classe ne gère plus de pointeur directement, il n'est plus nécessaire d'y implémenter les membres suivants:

- Le constructeur de copie
- Le destructeur
- L'opérateur `=`

Retirez donc ces membres.

Par ailleurs, si vous observez l'implémentation du constructeur sans paramètre, vous constaterez que celui-ci ne fait rien d'autre qu'initialiser les attributs en lien avec l'ancien pointeur de `TemperatureDatapoint`. Maintenant que ces attributs ont été remplacés par une liste, il n'y a plus rien à faire dans le constructeur. Vous pouvez donc simplement l'enlever! En effet, puisqu'il n'y a pas d'autre constructeur, le constructeur par défaut n'est pas désactivé, et il n'est donc pas nécessaire de définir notre propre constructeur sans paramètre.

## Étape 3

La présence de surcharges de l'opérateur `[]` était appropriée lorsque le conteneur utilisé était un tableau, mais ne l'est plus avec une liste. Il faut donc retirer toutes les versions de cet opérateur. Pour rappel, cet opérateur a deux versions constantes et deux versions non constantes avec le même code que les versions constantes. **Si vous ne vous souvenez plus pourquoi, retournez voir l'explication à l'étape 9 du Laboratoire 04-A. Cela est important pour la suite!**

## Étape 4

Adaptez les méthodes `getSize` et `clear` à la nouvelle structure de données.

## Étape 5

La méthode `findDatapoint` actuelle retourne la position de l'élément recherché, ce qui n'est pas approprié pour une liste. Nous voulons donc plutôt retourner un itérateur. Si l'élément est trouvé, l'itérateur retourné doit pointer sur cet élément. Sinon, il doit pointer sur la fin de la liste. De plus, il serait intéressant de créer deux versions de cette méthode:

- une qui prend en paramètre un itérateur vers le point de départ de la recherche
- une qui fait la recherche à partir du début de la liste

Naturellement, une de ces versions pourra appeler l'autre.

![](images/bob_leponge_reutilisation.jpg)

**Bien que les itérateurs soient des objets, il est habituel de toujours les passer ou les retourner par valeur.** Faire autrement risquerait de vous causer des problèmes. Par ailleurs, vos méthodes qui retournent des `iterator` ne pourront pas être `const` (nous y reviendrons à l'étape suivante). Les signatures des deux méthodes `findDatapoint` seront donc les suivantes:

- `std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::iterator start);`
- `std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment);`

Finalement, sachez que les données seront toujours stockées dans la liste en ordre croissant de date et heure. À vous de trouver quoi faire avec cette information, mais n'essayez surtout pas d'implémenter la recherche dichotomique, car celle-ci est beaucoup trop inefficace sur une liste chaînée.

## Étape 6

Vous venez d'implémenter deux versions de `findDatapoint`, et les deux sont non constantes, même si elles ne modifient pas l'objet `TemperatureHistory`. De manière générale, une méthode qui retourne un `iterator` n'est pas constante, et si vous tentez d'en faire une méthode constante, il est possible que vous ne puissiez plus compiler (c'est le cas si la méthode retourne un itérateur `begin()` ou `end()`).

Cela est problématique puisque, comme vous l'avez vu dans le laboratoire 4, une méthode non-constante ne peut pas être appelée par une méthode constante. Heureusement, il existe une façon pour une méthode constante de retourner un itérateur: il faut changer son type de retour pour `const_iterator`. Un `const_iterator` est un itérateur qui ne permet pas de modifier la valeur retournée lorsqu'on déréférence l'itérateur. C'est-à-dire qu'on ne pourrait pas faire quelque chose comme ceci:

```cpp
std::list<TemperatureDatapoint>::const_iterator it = this->_datapoints.begin();

it->setTemperature(25);
```

Dans le cas de `findDatapoint`, il peut être utile de pouvoir modifier cette valeur, par exemple si on a saisi la mauvaise température pour un moment et qu'on veut la corriger. Pour cette raison, nous allons dédoubler les deux versions de `findDatapoint`, comme nous l'avions fait pour l'opérateur `[]`. Voici les signatures des deux versions constantes à ajouter:

- `std::list<TemperatureDatapoint>::const_iterator findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::const_iterator start) const;`
* `std::list<TemperatureDatapoint>::const_iterator findDatapoint(const DateTime& moment) const;`

Les implémentations de ces méthodes sont simplement un copier-coller de leurs versions non-constantes. Tout comme pour l'opérateur `[]`, on ne peut malheureusement pas faire de réutilisation ici... sauf du GIF animé de circonstance!

![](./images/crying-spongebob.gif)

## Étape 7

Adaptez maintenant la méthode `addDatapoint`. **Celle-ci doit insérer la donnée à l'endroit approprié pour que la liste demeure en ordre croissant de date et heure**. Par ailleurs, si le moment de la donnée existe déjà dans la liste, il faut la remplacer.

La méthode doit retourner un itérateur pointant sur la donnée qui vient d'ajouter.

## Étape 8

Retirez la méthode `deleteDatapoint(size_t index)` et modifiez l'autre version de `deleteDatapoint` pour la rendre fonctionnelle.

Je laisse ça ici pour aucune raison particulière:

![](./images/bob_leponge_reutilisation.jpg)

## Étape 9

Retirez l'appel à la méthode `clear` qui est présentement fait dans la méthode `readFromFile`, car on veut désormais pouvoir charger les données de plusieurs fichiers dans le même `TemperatureHistory`. Il n'y a normalement aucune autre modification à apporter à cette méthode.

## Étape 10

Ajoutez une méthode `deleteRange` qui prend un moment de début et un moment de fin et supprime toutes les données incluses entre ces deux moments.

## Étape 11

Ajoutez des méthodes `begin()` et `end()` qui retournent les itérateurs correspondant de la liste. Vous devez créer une version constante et une version constante de chaque méthode.

## Étape 12

Apportez maintenant les modifications nécessaires au `main` d'origine pour le rendre fonctionnel comme avant. Testez bien le résultat à l'aide de l'exemple d'exécution ci-dessous (toujours en utilisant le fichier `temperatures.txt` du laboratoire 5):

```text
MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 1

Historique chargé avec succès.

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 2

Entrez le moment (format AAAA-MM-DDTHH:MM:SS): 2026-01-12T17:00:00
La température au moment 2026-01-12T17:00:00 était: -3.08348

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 2

Entrez le moment (format AAAA-MM-DDTHH:MM:SS): 2026-01-12T17:15:00
Aucune lecture trouvée pour la date et heure saisies.

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 3

Entrez le moment de début (format AAAA-MM-DDTHH:MM:SS): 2026-01-15T02:00:00
Entrez le moment de fin (format AAAA-MM-DDTHH:MM:SS): 2026-01-16T04:00:00
La température moyenne entre 2026-01-15T02:00:00 et 2026-01-16T04:00:00 est: -4.89881

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 3

Entrez le moment de début (format AAAA-MM-DDTHH:MM:SS): 2026-01-16T04:30:00
Entrez le moment de fin (format AAAA-MM-DDTHH:MM:SS): 2026-01-16T05:00:00
L'une des dates et heures saisies n'est pas présente dans l'historique.

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 4

Entrez le moment de la lecture à supprimer (format AAAA-MM-DDTHH:MM:SS): 2026-01-12T17:00:00
Lecture supprimée avec succès.

MENU
====================
1. Charger l'historique
2. Afficher la température à un moment précis
3. Calculer la température moyenne entre deux moments
4. Supprimer une lecture
5. Quitter

Entrez un choix entre 1 et 5: 2

Entrez le moment (format AAAA-MM-DDTHH:MM:SS): 2026-01-12T17:00:00
Aucune lecture trouvée pour la date et heure saisies.

Entrez un choix entre 1 et 5: 5

Au revoir!
```

---

## Étape 13

Dans le `main`, modifiez l'option 1 du menu afin qu'elle demande à l'utilisateur le nom du fichier à charger. Le nom de l'option sera désormais « Importer les données d'un fichier », et pourra être sélectionnée plusieurs fois de manière successive afin de charger les données de plusieurs fichiers.

Testez ensuite l'importation des fichiers `t1.txt` et `t2.txt` disponibles sur Moodle, dans cet ordre. Vous devriez avoir 717 entrées au total. Par ailleurs, si vous faites calculer la moyenne entre les moments `2026-01-01T15:00:00` et `2026-01-31T06:00:00`, vous devriez obtenir `-9.42678`.

## Étape 14

Finalement, améliorez l'efficacité de la méthode `readFromFile` en évitant de chercher la position d'insertion à partir du début de la liste à chaque ajout, sachant que les données d'un même fichier sont probablement en ordre (mais pas toujours). Libre à vous de créer ou modifier d'autres méthodes au besoin.

**⚠️ Faites valider votre laboratoire 07 par l'enseignant.**

🎉 Félicitations, vous avez terminé le laboratoire!
