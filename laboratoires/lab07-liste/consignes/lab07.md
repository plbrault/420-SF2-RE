- Remplacer _pointeur de datapoints par une liste
- Retirer _size et _capacity
- Ne pas hésiter à commenter les méthodes et le main pour pouvoir tester au fur et à mesure
- Retirer constructeurs et destructeurs
- Retirer opérateur =
- Retirer opérateur [], et noter qu'il existe en deux versions (const et non-const)
- Adapter getSize et clear
- Adapter findDatapoint pour retourner un itérateur au lieu d'un size_t, doit être retourné par valeur avec méthode non const. Faire deux versions dont une qui prend en paramètre la position de départ de la recherche. Penser à la réutilisation. Si introuvable, retourner end(). Assumer que les valeurs sont en ordre, mais ne surtout pas faire de recherche dichotomique (il y a quand même une optimisation possible, à vous d'y penser).
- Faire deux versions const avec exactement le même code, mais le type de retour est const_iterator
- Adapter addDatapoint, doit ajouter le datapoint au bon endroit pour respecter l'ordre de date. S'il y a déjà un datapoint avec la même datetime, il faut le remplacer. L'insertion devient donc idempotente.
- Retirer void deleteDatapoint(size_t index) et adapter l'autre version
- Enlever le clear dans readFromFile, car on veut maintenant pouvoir lire plusieurs fichiers de suite. L'utilisation de la méthode addDatapoint s'assure que les données sont toujours insérées au bon endroit dans la liste.
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
- Améliorer l'efficacité de readFromFile (données sont probablement en ordre)
- Ajouter une méthode delete qui prend un début et une fin
