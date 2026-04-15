# Laboratoire 09

## Objectif

Mettre en pratique l'utilisation de toutes les structures de données vues dans le cours, et plus particulièrement des files et des piles.

## Mise en situation

L'été approche, et le Cégep a décidé d'installer des glissades d'eau dans la colline près du pavillon 4 afin de rentabiliser ses espaces durant la saison estivale! Le fonctionnement prévu des glissades d'eau est le suivant:

- Les visiteurs accèdent tous aux glissades d'eau par la même **file d'entrée** au bas de la colline.
- À l'avant de la file d'entrée se trouve la **pile des tubes disponibles**. Un visiteur arrivant à l'avant de la file prend un tube, puis entre dans la **file de montée** permettant d'avancer vers le haut de la colline.
- Une fois en haut de la colline, le visiteur entre dans un des **toboggans**. Il faut cependant laisser s'écouler 10 secondes entre chaque glisseur dans un même toboggan.
- Tous les toboggans mènent à la même **zone d'arrivée** au bas de la colline. On estime qu'il faut 30 secondes à un glisseur pour atteindre le bas de la colline.
- Une fois un glisseur rendu à la zone d'arrivée, il dépose son tube dans une **pile de dépôt**. On estime qu'il faut en moyenne 15 secondes avant qu'un glisseur arrivé en bas de la colline dépose son tube puis quitte la zone d'arrivée.
- Chaque fois que la **pile des tubes disponibles** est vide, un employé y transfère tous les tubes se trouvant dans la **pile de dépôt**.

Les responsables du projet de glissades d'eau se demandent cependant combien il faut prévoir de toboggans et de tubes pour que le tout soit fluide. Ils font donc appel à vous pour simuler le tout à l'aide d'un programme C++!

## Démarrage

Récupérez les fichiers de départ sur Moodle, puis ajoutez-les à votre projet.

**IMPORTANT:** Avant de lancer le programme, vous devez modifier les options d'exécution dans CLion. Cliquez sur l'icône représentant trois points verticaux près du bouton `Run`, puis cliquez sur `Edit`.

![](images-readme/clion_edit.png)

Dans la fenêtre `Run/Debug Configurations`, cochez `Emulate terminal in the output console`. Faites ensuite `Apply` puis `OK`.

![](images-readme/clion_option_a_cocher.png)

Si vous exécutez ensuite le projet, vous devriez voir ceci dans la console:

![](images-readme/apercu_execution.gif)

La touche `+` du clavier vous permet d'augmenter la vitesse de la simulation. Comme vous pouvez le voir, des visiteurs arrivent au fil du temps, mais n'entrent jamais dans la file d'entrée. La simulation s'arrête à 17h00.

Le fichier `configuration.json` vous permet de changer le nombre de toboggans, le nombre de tubes, de même que la température. Plus la température est élevée, plus il y a de visiteurs dans la journée.

## Implémentation

Voici le diagramme de classes du projet:

```plantuml
@startuml

interface ISOFormatEntity {
    + std::string toISOString() const
}

class Duration {
    # unsigned long int _totalSeconds
    --
    + Duration()
    + Duration(unsigned long int totalSeconds)
    + Duration(unsigned int hours, unsigned int minutes, unsigned int seconds)
    + unsigned long int getTotalSeconds() const
    + unsigned int getHours() const
    + unsigned int getMinutes() const
    + unsigned int getSeconds() const
    + void setTotalSeconds(unsigned long int totalSeconds)
    + void setHours(unsigned int hours)
    + void setMinutes(unsigned int minutes)
    + void setSeconds(unsigned int seconds)
    + Duration& addHours(unsigned int hours)
    + Duration& addMinutes(unsigned int minutes)
    + Duration& addSeconds(unsigned long int seconds)
    + Duration& subtractHours(unsigned int hours)
    + Duration& subtractMinutes(unsigned int minutes)
    + Duration& subtractSeconds(unsigned long int seconds)
    + std::string toISOString() const
    + void print(std::ostream& output) const
    + void read(std::istream& input)
    + bool operator==(const Duration& other) const
    + bool operator!=(const Duration& other) const
    + bool operator<(const Duration& other) const
    + bool operator<=(const Duration& other) const
    + bool operator>(const Duration& other) const
    + bool operator>=(const Duration& other) const
    + Duration& operator+=(const Duration& other)
    + Duration operator+(const Duration& other) const
    + Duration& operator-=(const Duration& other)
    + Duration operator-(const Duration& other) const
    + Duration& operator*=(double factor)
    + Duration operator*(double factor) const
    + Duration& operator/=(double divisor)
    + Duration operator/(double divisor) const
    + double operator/(const Duration& divisor) const
}

class Time {
    --
    + Time()
    + Time(unsigned int hours, unsigned int minutes, unsigned int seconds)
    + void setTotalSeconds(unsigned long int totalSeconds)
    + void setHours(unsigned int hours)
    + Time& addHours(unsigned int hours)
    + Time& addMinutes(unsigned int minutes)
    + Time& addSeconds(unsigned long int seconds)
    + void read(std::istream& input)
    + Time& operator+=(const Duration& duration)
    + Time operator+(const Duration& duration) const
    + Time& operator-=(const Duration& duration)
    + Time operator-(const Duration& duration) const
    + Duration operator-(const Time& other) const
}

class Tube {
}

class Visiteur {
    - Tube* _tube
    --
    + void prendreTube(Tube* tube)
    + Tube* retournerTube()
    + bool aUnTube() const
}

class Toboggan {
    - std::queue<Visiteur*> _glisseurs
    - std::map<Visiteur*, Time> _heureEntree
    --
    + bool accepteGlisseur(const Time& heureActuelle) const
    + void ajouterGlisseur(Visiteur* visiteur, const Time& heure)
    + Visiteur* traiterSortie(const Time& heureActuelle)
    + size_t getNombreGlisseurs() const
}

class GlissadeEau {
    - Time _heureActuelle
    - int _totalVisiteursJournee
    - std::list<Tube> _tubes
    - std::stack<Tube*> _tubesDisponibles
    - std::stack<Tube*> _depotTubes
    - std::vector<Toboggan> _toboggans
    - std::queue<Visiteur*> _fileEntree
    - std::queue<Visiteur*> _fileMontee
    - std::map<Visiteur*, Time> _zoneArrivee
    --
    + GlissadeEau()
    + GlissadeEau(size_t nombreToboggans, size_t nombreTubes)
    + const Time& getHeureActuelle() const
    + void mettreAJour()
    + void ajouterVisiteur(Visiteur* visiteur)
    + Visiteur* traiterSortie()
    + void afficher(std::ostream& sortie) const
    + friend std::ostream& operator<<(std::ostream& os, const GlissadeEau& glissade)
}

class Parser {
    + void parse(std::istream& in)
}

class JSONParser {
    - nlohmann::json _data
    --
    + void parse(std::istream& in)
    + const nlohmann::json& getData() const
}

class Simulateur {
    - GlissadeEau _glissade
    - std::set<Visiteur*> _visiteurs
    - int _facteurVitesse
    - int _arriveesMinuteCourante
    - double _temperature
    - double _facteurTemperature
    - double calculerTauxArrivee(unsigned long secondesEcoulees)
    - void simulerArrivees(std::mt19937& gen)
    - void afficher() const
    --
    + Simulateur(std::istream& fichierConfig)
    + ~Simulateur()
    + void simuler()
}

ISOFormatEntity <|.. Duration
Duration <|-- Time
Parser <|-- JSONParser
Simulateur *-- GlissadeEau
Simulateur *-- Visiteur
GlissadeEau *-- Tube
GlissadeEau *-- Toboggan
GlissadeEau *-- Time
Toboggan ..> Visiteur
Toboggan ..> Time
Visiteur ..> Tube
GlissadeEau ..> Visiteur
Simulateur ..> JSONParser

@enduml
```

La classe `Simulateur` est déjà implémentée. C'est elle qui simule l'arrivée des visiteurs au fil du temps et qui adapte celle-ci à la température.

La classe `GlissadeEau` contient les `Toboggan`, et gère la file d'entrée, la file de montée, la zone d'arrivée et les piles de tube.

La classe `Toboggan` représente bien entendu un toboggan et gère le temps nécessaire à la descente.

Vous remarquerez la présence de plusieurs classes des laboratoires précédents.

![](images-readme/bob_leponge_reutilisation.jpg)

Votre mission, si vous l'acceptez (et je vous recommande fortement de l'accepter étant donné l'examen qui s'en vient), est de compléter le programme pour rendre fonctionnelle la simulation. Pour ce faire, vous devez modifier **uniquement** les classes `Toboggan` et `GlissadeEau`. Dans ces classes, complétez les méthodes contenant un commentaire `/***À COMPLÉTER***/`. Faites les ajouts décrits par les commentaires.

Bonne chance!

> **Psssst!** La classe `std::map` n'a pas d'opérateur `[]` constant, donc si jamais vous rencontrez une erreur `"No viable function"` en lien avec ça, il faut utiliser la méthode `at()` à la place.
