#include <iostream>
#include "Element.h"
#include "fonctions.h"

int main() {
    Element hydrogene("H", "Hydrogen", 1, "1");
    hydrogene.ajouterIsotope(Isotope("Protium", 0, 99.9885, 1.00782503207));
    hydrogene.ajouterIsotope(Isotope("Deuterium", 1, 0.0115, 2.01410177785));
    hydrogene.ajouterIsotope(Isotope("Tritium", 2, 0, 12.32, 3.0160492777));

    Element helium("He", "Helium", 2, "18");
    helium.ajouterIsotope(Isotope("Helium-3", 1, 0.000137, 3.0160293191));
    helium.ajouterIsotope(Isotope("Helium-4", 2, 99.999863, 4.00260325415));

    Element lithium("Li", "Lithium", 3, "1");
    lithium.ajouterIsotope(Isotope("Lithium-6", 3, 7.59, 6.015122795));
    lithium.ajouterIsotope(Isotope("Lithium-7", 4, 92.41, 7.01600455));

    Element beryllium("Be", "Beryllium", 4, "2");
    beryllium.ajouterIsotope(Isotope("Beryllium-7", 3, 0, 0.1461, 7.01692983));
    beryllium.ajouterIsotope(Isotope("Beryllium-9", 5, 100, 9.0121822));
    beryllium.ajouterIsotope(Isotope("Beryllium-10", 6, 0, 1.51e6, 10.0135338));

    Element bore("B", "Bore", 5, "13");
    bore.ajouterIsotope(Isotope("Bore-10", 5, 19.9, 10.0129370));
    bore.ajouterIsotope(Isotope("Bore-11", 6, 80.1, 11.0093054));

    Element carbone("C", "Carbone", 6, "14");
    carbone.ajouterIsotope(Isotope("Carbone-12", 6, 98.93, 12.0));
    carbone.ajouterIsotope(Isotope("Carbone-13", 7, 1.07, 13.0033548378));
    carbone.ajouterIsotope(Isotope("Carbone-14", 8, 0, 5730, 14.003241989));

    Element elements[6] = {hydrogene, helium, lithium, beryllium, bore, carbone};

    for (size_t i = 0; i < 6; i++) {
        afficherElement(elements[i]);
        std::cout << std::endl;
    }

    return 0;
}
