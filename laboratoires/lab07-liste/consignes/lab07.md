# Laboratoire 07

## Objectif

Mettre en pratique l'utilisation d'une liste de la STL.

## Introduction

Ce laboratoire comprend une seule partie. Elle consiste à reprendre votre programme du Laboratoire 05 qui gère une liste de températures, et à le modifier afin de remplacer le tableau dynamique actuel par une liste de la STL. Certaines améliorations au fonctionnement du programme seront également apportées.

La première étape du laboratoire rendra impossible la compilation du programme jusqu'à ce que la plupart des étapes suivantes soient complétées. N'hésitez pas à mettre du code en commentaire afin d'être en mesure de tester vos modifications au fur et à mesure.

## Étape 1

Dans la classe `TemperatureHistory`, remplacez le pointeur `_datapoints` par une liste. Retirez également les attributs `_size` et `_capacity`, puisqu'ils ne seront plus nécessaires.

## Étape 2

Puisque la classe ne gère plus de pointeur directement, il n'est plus nécessaire d'y implémenter les membres suivants:

- Le constructeur de copie
- Le destructeur
- L'opérateur `=`

Retirez donc ces membres.

Par ailleurs, si vous observez l'implémentation du constructeur sans paramètre, vous constaterez que celui-ci ne fait rien d'autre qu'initialiser les attributs en lien avec l'ancien pointeur de `TemperatureDatapoint`. Maintenant que ces attributs ont été remplacés par une liste, il n'y a plus rien à faire dans le constructeur. Vous pouvez donc simplement l'enlever! En effet, puisqu'il n'y a pas d'autre constructeur, le constructeur par défaut n'est pas désactivé, et il n'est donc pas nécessaire de définir le constructeur sans paramètre.

## Étape 3

La présence de surcharges de l'opérateur `[]` était appropriée lorsque le conteneur utilisé était un tableau, mais ne l'est plus avec une liste. Il faut donc retirer toutes les versions de cet opérateur. Pour rappel, cet opérateur a deux versions constantes et deux versions non constantes. **Si vous ne vous souvenez plus pourquoi, retournez voir l'explication à l'étape 9 du Laboratoire 04-A. Cela est important pour la suite!**

## Étape 4

Adaptez les méthodes `getSize` et `clear` à la nouvelle structure de données.

## Étape 5

La méthode `findDatapoint` actuelle retourne la position de l'élément recherché, ce qui n'est pas approprié pour une liste. Nous voulons donc plutôt retourner un itérateur. Si l'élément est trouvé, l'itérateur retourné doit pointé sur cet élément. Sinon, il doit pointer sur la fin de la liste. De plus, il serait intéressant de créer deux versions de cette méthode:

- une qui prend en paramètre un itérateur vers le point de départ de la recherche
- une qui fait la recherche à partir du début de la liste

Naturellement, une de ces versions pourra appeler l'autre.

![](images/bob_leponge_reutilisation.jpg)

**Bien que les itérateurs soient des objets, il est habituel de toujours les passer ou les retourner par valeur.** Faire autrement risquerait de vous causer des problèmes. Par ailleurs, vos méthodes qui retournent des `iterator` ne pourront pas être `const` (nous y reviendrons à l'étape suivante). Les signatures des deux méthodes `findDatapoint` seront donc les suivantes:

- `std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::iterator start);`
- `std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment);`

Finalement, sachez que les données seront toujours stockées dans la liste en ordre croissant de date et heure. À vous de trouver quoi faire avec cette information, mais n'essayez surtout pas d'implémenter la recherche dichotomique, car celle-ci est beaucoup trop inefficace sur une liste chaînée.


--


- Adapter findDatapoint pour retourner un itérateur au lieu d'un size_t, doit être retourné par valeur avec méthode non const. Faire deux versions dont une qui prend en paramètre la position de départ de la recherche. Penser à la réutilisation. Si introuvable, retourner end(). Assumer que les valeurs sont en ordre, mais ne surtout pas faire de recherche dichotomique (il y a quand même une optimisation possible, à vous d'y penser).
- Faire deux versions const avec exactement le même code, mais le type de retour est const_iterator
- Adapter addDatapoint, doit ajouter le datapoint au bon endroit pour respecter l'ordre de date. S'il y a déjà un datapoint avec la même datetime, il faut le remplacer. L'insertion devient donc idempotente. Retourner un itérateur vers le Datapoint qui vient d'être ajouté.
- Retirer void deleteDatapoint(size_t index) et adapter l'autre version
- Enlever le clear dans readFromFile, car on veut maintenant pouvoir lire plusieurs fichiers de suite. L'utilisation de la méthode addDatapoint s'assure que les données sont toujours insérées au bon endroit dans la liste.
- Ajouter une méthode `deleteRange` qui prend un moment de début et un moment de fin
- Ajouter méthodes begin() et end() en version const et non const (nécessaire pour adaptation du main)
- Apporter modifications nécessaires dans le `main` pour que le programme marche comme avant. Bien tester avec exemple d'exécution ci-dessous (toujours avec le fichier temperatures.txt du lab 4):

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

- Modifier main pour remplacer l'option 1 par "Importer les données d'un fichier" puis demander à l'utilisateur le nom du fichier à charger. Tester avec temperatures1.txt et temperatures2.txt fournis sur Moodle.

Test: vous devriez avoir 717 entrées au total
```text
Entrez le moment de début (format AAAA-MM-DDTHH:MM:SS): 2026-01-01T15:00:00
Entrez le moment de fin (format AAAA-MM-DDTHH:MM:SS): 2026-01-31T06:00:00
La température moyenne entre 2026-01-01T15:00:00 et 2026-01-31T06:00:00 est: -9.42678
```

- Améliorer l'efficacité de readFromFile en évitant de chercher à partir du début à chaque ajout (sachant que données sont probablement en ordre, mais pas toujours). Créer ou modifier d'autres méthodes au besoin.
