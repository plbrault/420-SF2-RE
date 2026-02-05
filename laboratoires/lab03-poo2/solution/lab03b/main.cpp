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
        int _groupe;
        Isotope* _isotopes;
        size_t _nombreIsotopes;
        size_t _capaciteIsotopes;

    public:
        Element();
        Element(std::string symbole, std::string nom, int nbParticulesChargees, int groupe);
        Element(const Element& autreElement);
        ~Element();

        void ajouterIsotope(Isotope isotope);

        std::string getSymbole() const;
        std::string getNom() const;
        int getNbParticulesChargees() const;
        int getGroupe() const;
        size_t getNombreIsotopes() const;
        Isotope* getIsotope(size_t indice) const;

        void setSymbole(std::string symbole);
        void setNom(std::string nom);
        void setNbParticulesChargees(int nbParticulesChargees);
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
    du tableau périodique avec leurs isotopes. Place les éléments dans un tableau `elements`.

    N'utilise pas l'opérateur d'affectation de la classe Element.
    */

    // DÉBUT DU CODE GÉNÉRÉ PAR L'IA

    Element elements[6] = {
        Element("H", "Hydrogène", 1, 1),
        Element("He", "Hélium", 2, 18),
        Element("Li", "Lithium", 3, 1),
        Element("Be", "Béryllium", 4, 2),
        Element("B", "Bore", 5, 13),
        Element("C", "Carbone", 6, 14)
    };

    // Ajout des isotopes de l'hydrogène (H)
    elements[0].ajouterIsotope(Isotope("H-1", 0, 99.9855, 1.00784));
    elements[0].ajouterIsotope(Isotope("H-2", 1, 0.0145, 2.014102));
    elements[0].ajouterIsotope(Isotope("H-3", 2, 0.0, 12.32, 3.016049));
    elements[0].ajouterIsotope(Isotope("H-4", 3, 0.0, 1.39e-22, 4.02781));
    elements[0].ajouterIsotope(Isotope("H-5", 4, 0.0, 8.6e-23, 5.03531));
    elements[0].ajouterIsotope(Isotope("H-6", 5, 0.0, 2.9e-22, 6.04494));
    elements[0].ajouterIsotope(Isotope("H-7", 6, 0.0, 2.3e-23, 7.05275));

    // Ajout des isotopes de l'hélium (He)
    elements[1].ajouterIsotope(Isotope("He-3", 1, 0.000137, 3.01603));
    elements[1].ajouterIsotope(Isotope("He-4", 2, 99.999863, 4.002602));
    elements[1].ajouterIsotope(Isotope("He-5", 3, 0.0, 7.0e-22, 5.01222));
    elements[1].ajouterIsotope(Isotope("He-6", 4, 0.0, 0.807, 6.01889));
    elements[1].ajouterIsotope(Isotope("He-7", 5, 0.0, 3.04e-21, 7.02803));
    elements[1].ajouterIsotope(Isotope("He-8", 6, 0.0, 0.119, 8.03392));
    elements[1].ajouterIsotope(Isotope("He-9", 7, 0.0, 7.0e-21, 9.04395));
    elements[1].ajouterIsotope(Isotope("He-10", 8, 0.0, 2.6e-21, 10.0524));

    // Ajout des isotopes du lithium (Li)
    elements[2].ajouterIsotope(Isotope("Li-4", 1, 0.0, 7.6e-23, 4.02719));
    elements[2].ajouterIsotope(Isotope("Li-5", 2, 0.0, 3.7e-22, 5.01254));
    elements[2].ajouterIsotope(Isotope("Li-6", 3, 7.59, 6.015122));
    elements[2].ajouterIsotope(Isotope("Li-7", 4, 92.41, 7.016004));
    elements[2].ajouterIsotope(Isotope("Li-8", 5, 0.0, 0.838, 8.02249));
    elements[2].ajouterIsotope(Isotope("Li-9", 6, 0.0, 0.178, 9.02679));
    elements[2].ajouterIsotope(Isotope("Li-10", 7, 0.0, 2.0e-21, 10.0355));
    elements[2].ajouterIsotope(Isotope("Li-11", 8, 0.0, 0.00859, 11.0438));

    // Ajout des isotopes du béryllium (Be)
    elements[3].ajouterIsotope(Isotope("Be-5", 1, 0.0, 1.0e-19, 5.0399));
    elements[3].ajouterIsotope(Isotope("Be-6", 2, 0.0, 5.0e-21, 6.01973));
    elements[3].ajouterIsotope(Isotope("Be-7", 3, 0.0, 53.22/365.25, 7.01693));
    elements[3].ajouterIsotope(Isotope("Be-8", 4, 0.0, 8.19e-17, 8.00531));
    elements[3].ajouterIsotope(Isotope("Be-9", 5, 100.0, 9.01218));
    elements[3].ajouterIsotope(Isotope("Be-10", 6, 0.0, 1.51e6, 10.01353));
    elements[3].ajouterIsotope(Isotope("Be-11", 7, 0.0, 13.81, 11.02166));
    elements[3].ajouterIsotope(Isotope("Be-12", 8, 0.0, 0.0204, 12.02692));

    // Ajout des isotopes du bore (B)
    elements[4].ajouterIsotope(Isotope("B-7", 2, 0.0, 3.5e-22, 7.02992));
    elements[4].ajouterIsotope(Isotope("B-8", 3, 0.0, 0.77, 8.02461));
    elements[4].ajouterIsotope(Isotope("B-9", 4, 0.0, 8.0e-19, 9.01333));
    elements[4].ajouterIsotope(Isotope("B-10", 5, 19.9, 10.012937));
    elements[4].ajouterIsotope(Isotope("B-11", 6, 80.1, 11.009305));
    elements[4].ajouterIsotope(Isotope("B-12", 7, 0.0, 0.0202, 12.01435));
    elements[4].ajouterIsotope(Isotope("B-13", 8, 0.0, 0.0174, 13.01778));
    elements[4].ajouterIsotope(Isotope("B-14", 9, 0.0, 0.0125, 14.02540));

    // Ajout des isotopes du carbone (C)
    elements[5].ajouterIsotope(Isotope("C-9", 3, 0.0, 0.127, 9.03104));
    elements[5].ajouterIsotope(Isotope("C-10", 4, 0.0, 19.29, 10.01685));
    elements[5].ajouterIsotope(Isotope("C-11", 5, 0.0, 20.33/60/24/365.25, 11.01143));
    elements[5].ajouterIsotope(Isotope("C-12", 6, 98.93, 12.000000));
    elements[5].ajouterIsotope(Isotope("C-13", 7, 1.07, 13.003355));
    elements[5].ajouterIsotope(Isotope("C-14", 8, 0.0, 5730.0, 14.003241));
    elements[5].ajouterIsotope(Isotope("C-15", 9, 0.0, 2.449, 15.01060));
    elements[5].ajouterIsotope(Isotope("C-16", 10, 0.0, 0.747, 16.01470));

    // FIN DU CODE GÉNÉRÉ PAR L'IA

    for (size_t i = 0; i < 6; i++) {
        afficherElement(elements[i]);
        std::cout << std::endl;
    }

    return 0;
}
