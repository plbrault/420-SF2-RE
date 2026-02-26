Étapes à inclure dans le lab 05-A:

0 - Expliquer qu'on va faire un refactor, et ce que ça veut dire

1 - Changer private pour public dans Duration
2 - Faire hériter Time de Duration

Étapes à faire au complet avant de pouvoir compiler à nouveau:

3 - Retirer les trois attributs (_hours, _minutes, _seconds) de Time.
4 - Retirer l'implémentation du constructeur avec paramètres et appeler celui de Duration
5 - Retirer les getters getHours, getMinutes et getSeconds
6 - Retirer aussi les setters (nous allons les réimplémenter dans Duration dans une étape ultérieure)
7 - Retirer toString, print et read
8 - Retirer tous les opérateurs de comparaison
9 - Mettre en commentaires les opérateurs arithmétiques pour le moment
10 - Retirer les surcharges d'opérateurs << et >>
11 - Vérifier que le programme fonctionne encore comme avant (on devrait encore pouvoir faire afficher une température à un moment précis)

Remarquer que suite à ces étapes, il n'y a plus rien dans Time.cpp (sauf du code commenté)

