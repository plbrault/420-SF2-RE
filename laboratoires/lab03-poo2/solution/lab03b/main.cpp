#include <iostream>
#include "Element.h"
#include "fonctions.h"

int main() {
    /*
    === PROMPT UTILISÉ POUR GÉNÉRER L'INSTANCIATION DES ÉLÉMENTS ET DES ISOTOPES ===

    Voici les définitions de mes classes Element et Isotope:

    class Element {
    private:
        std::string _symbole;
        std::string _nom;
        int _numeroAtomique;
        int _groupe;
        Isotope* _isotopes;
        size_t _nombreIsotopes;
        size_t _capaciteIsotopes;

    public:
        Element();
        Element(std::string symbole, std::string nom, int numeroAtomique, int groupe);
        Element(const Element& autreElement);
        ~Element();

        void ajouterIsotope(Isotope isotope);

        std::string getSymbole() const;
        std::string getNom() const;
        int getNumeroAtomique() const;
        int getGroupe() const;
        size_t getNombreIsotopes() const;
        Isotope* getIsotope(size_t indice) const;

        void setSymbole(std::string symbole);
        void setNom(std::string nom);
        void setNumeroAtomique(int numeroAtomique);
        void setGroupe(int groupe);

        bool aIsotopeStable() const;
    };

    class Isotope {
    private:
        std::string _nom;
        int _nbNeutrons;
        double _occurence;
        double _demiVie;
        double _masse;

    public:
        Isotope();
        Isotope(std::string nom, int nbNeutrons, double occurence, double masse);
        Isotope(std::string nom, int nbNeutrons, double occurence, double demiVie, double masse);

        std::string getNom() const;
        int getNbNeutrons() const;
        double getOccurence() const;
        double getDemiVie() const;
        double getMasse() const;

        void setNom(std::string nom);
        void setNbNeutrons(int nbNeutrons);
        void setOccurence(double occurence);
        void setDemiVie(double demiVie);
        void setMasse(double masse);

        bool estStable() const;
    };

    En te basant sur ces définitions, génère du code permettant d'instancier les 6 premiers éléments
    du tableau périodique. Ajoute aussi tous les isotopes présents naturellement sur Terre pour chacun
    de ces éléments. Base-toi sur des recherches sur le Web pour identifier ces isotopes et ne pas en oublier.

    Les éléments doivent être ajoutés dans un tableau statique `elements` de taille 6. Les isotopes n'ont pas à être
    stockés ailleurs que dans les éléments.

    Les demi-vies sont exprimées en années. Un isotope stable a une demi-vie infinie
    (`std::numeric_limits<double>::infinity()`).

    N'inclue pas les caractères accentués dans les noms des éléments et des isotopes.

    Je n'ai pas besoin que tu me fournisses le code des classes, je l'ai déjà. Je veux seulement le code d'instanciation
    des objets.

    N'utilise pas l'opérateur d'affectation de la classe Element.
    */

    // DÉBUT DU CODE GÉNÉRÉ PAR L'IA

    Element elements[6] = {
        // Hydrogene (groupe 1)
        [](){
            Element e("H", "Hydrogene", 1, 1);
            e.ajouterIsotope(Isotope("Hydrogene-1", 0, 0.999885, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Deuterium", 1, 0.000115, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Tritium", 2, 0.0, 12.32)); // demi-vie ~ 12.32 ans
            return e;
        }(),

        // Helium (groupe 18)
        [](){
            Element e("He", "Helium", 2, 18);
            e.ajouterIsotope(Isotope("Helium-3", 1, 0.00000137, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Helium-4", 2, 0.99999863, std::numeric_limits<double>::infinity()));
            return e;
        }(),

        // Lithium (groupe 1)
        [](){
            Element e("Li", "Lithium", 3, 1);
            e.ajouterIsotope(Isotope("Lithium-6", 3, 0.0759, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Lithium-7", 4, 0.9241, std::numeric_limits<double>::infinity()));
            return e;
        }(),

        // Beryllium (groupe 2)
        [](){
            Element e("Be", "Beryllium", 4, 2);
            e.ajouterIsotope(Isotope("Beryllium-9", 5, 1.0, std::numeric_limits<double>::infinity()));
            // isotope cosmogenique
            e.ajouterIsotope(Isotope("Beryllium-10", 6, 0.0, 1.387e6));
            return e;
        }(),

        // Bore (groupe 13)
        [](){
            Element e("B", "Bore", 5, 13);
            e.ajouterIsotope(Isotope("Bore-10", 5, 0.199, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Bore-11", 6, 0.801, std::numeric_limits<double>::infinity()));
            return e;
        }(),

        // Carbone (groupe 14)
        [](){
            Element e("C", "Carbone", 6, 14);
            e.ajouterIsotope(Isotope("Carbone-12", 6, 0.9893, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Carbone-13", 7, 0.0107, std::numeric_limits<double>::infinity()));
            e.ajouterIsotope(Isotope("Carbone-14", 8, 0.0, 5730)); // demi-vie ~ 5730 ans
            return e;
        }()
    };

    // FIN DU CODE GÉNÉRÉ PAR L'IA

    for (size_t i = 0; i < 6; i++) {
        afficherElement(elements[i]);
        std::cout << std::endl;
    }

    return 0;
}
