# Laboratoire 09

## Objectif

Mettre en pratique l'utilisation de toutes les structures de données vues dans le cours, et plus particulièrement des files et des piles.

## Mise en situation

L'été approche, et le Cégep a décidé d'installer des glissades d'eau dans la colline près du pavillon 4 afin de rentabiliser ses espaces durant la saison estivale! Le fonctionnement des glissades d'eau sera le suivant:

- Les visiteurs accéderont tous aux glissades d'eau par la même **file d'entrée** au bas de la colline.
- À l'avant de la file d'entrée, il y aura une **pile des tubes disponibles**. Un visiteur arrivant à l'avant de la file pourra donc prendre un tube s'il y en a au moins un de disponible, puis entrer dans la **file de montée** permettant d'avancer vers le haut de la colline.
- Une fois en haut de la colline, le visiteur pourra entrer dans un des **toboggans**. Il faudra cependant laisser s'écouler 10 secondes entre chaque glisseur dans un même toboggan.
- Tous les toboggans mèneront à la même **zone d'arrivée** au bas de la colline. On estime qu'il faudra 30 secondes à un glisseur pour atteindre le bas de la colline.
- Une fois un glisseur rendu à la zone d'arrivée, il déposera son tube dans une **pile de dépôt**. On estime qu'il faudra en moyenne 15 secondes avant qu'un glisseur arrivé en bas de la colline dépose son tube puis quitte la zone d'arrivée.
- Chaque fois que la **pile des tubes disponibles** sera vide, un employé y transférera tous les tubes se trouvant dans la **pile de dépôt**.


---
À faire dans CLion:

> ... > Edit > cocher "Emulate terminal..."


Le map n'a pas d'opérateur [] constant, donc si vous avez une erreur "No viable function" il faut utiliser .at() à la place
