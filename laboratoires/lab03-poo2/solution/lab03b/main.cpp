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
        int _nbParticulesChargees;
        std::string _groupe;
        Isotope* _isotopes;
        size_t _nombreIsotopes;
        size_t _capaciteIsotopes;

    public:
        Element();
        Element(std::string symbole, std::string nom, int nbParticulesChargees, std::string groupe);
        Element(const Element& autreElement);
        ~Element();

        void ajouterIsotope(Isotope isotope);

        std::string getSymbole() const;
        std::string getNom() const;
        int getNbParticulesChargees() const;
        std::string getGroupe() const;
        size_t getNombreIsotopes() const;
        Isotope* getIsotope(size_t indice) const;

        void setSymbole(std::string symbole);
        void setNom(std::string nom);
        void setNbParticulesChargees(int nbParticulesChargees);
        void setGroupe(std::string groupe);

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
    du tableau périodique avec leurs isotopes. Place les éléments dans un tableau `elements`.

    N'utilise pas l'opérateur d'affectation de la classe Element.
    */

    // DÉBUT DU CODE GÉNÉRÉ PAR L'IA

    Element elements[6] = {
        Element("H", "Hydrogène", 1, "Non-métal"),
        Element("He", "Hélium", 2, "Noble gaz"),
        Element("Li", "Lithium", 3, "Métal alcalin"),
        Element("Be", "Béryllium", 4, "Métal alcalino-terreux"),
        Element("B", "Bore", 5, "Métalloïde"),
        Element("C", "Carbone", 6, "Non-métal")
    };

    // Ajout des isotopes
    elements[0].ajouterIsotope(Isotope("H-1", 0, 99.98, 1.00784));
    elements[0].ajouterIsotope(Isotope("H-2", 1, 0.02, 2.014102));
    elements[1].ajouterIsotope(Isotope("He-3", 1, 0.000137, 3.01603));
    elements[1].ajouterIsotope(Isotope("He-4", 2, 99.999863, 4.002602));
    elements[2].ajouterIsotope(Isotope("Li-6", 3, 7.5, 6.015122));
    elements[2].ajouterIsotope(Isotope("Li-7", 4, 92.5, 7.016004));
    elements[3].ajouterIsotope(Isotope("Be-8", 4, 0.0, 8.005305)); // Instable
    elements[4].ajouterIsotope(Isotope("B-10", 5, 19.9, 10.012937));
    elements[4].ajouterIsotope(Isotope("B-11", 6, 80.1, 11.009305));
    elements[5].ajouterIsotope(Isotope("C-12", 6, 98.89, 12.000000));
    elements[5].ajouterIsotope(Isotope("C-13", 7, 1.11, 13.003355));

    // FIN DU CODE GÉNÉRÉ PAR L'IA

    for (size_t i = 0; i < 6; i++) {
        afficherElement(elements[i]);
        std::cout << std::endl;
    }

    return 0;
}
