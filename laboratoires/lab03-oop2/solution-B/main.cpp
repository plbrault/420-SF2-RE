
#include <iostream>

#include "element.h"

int main() {
    Element hydrogen("Hydrogen", "H", 1, 1, "1");
    hydrogen.ajouterIsotope(Isotope("Protium", 0, 0.999855, 1.007825031898));
    hydrogen.ajouterIsotope(Isotope("Deutorium", 1, 0.000145, 2.014101777844));
    hydrogen.ajouterIsotope(Isotope("Tritium", 2, 0.0, 3.8879e+8, 3.016049281320));
    hydrogen.ajouterIsotope(Isotope("hydrogen-4", 3, 0.0, 139e-24, 4.02643));
    hydrogen.ajouterIsotope(Isotope("hydrogen-5", 4, 0.0, 86e-24, 5.03531));
    hydrogen.ajouterIsotope(Isotope("hydrogen-6", 5, 0.0, 294e-24, 6.04496));
    hydrogen.ajouterIsotope(Isotope("hydrogen-7", 6, 0.0, 652e-24, 7.052750));

    Element helium("Helium", "He", 2, 0, "18");
    helium.ajouterIsotope(Isotope("helium-2", 0, 0.0, 10e-9, 2.015894));
    helium.ajouterIsotope(Isotope("helium-3", 0, 0.000002, 3.016029321967));
    helium.ajouterIsotope(Isotope("helium-4", 0, 0.999998, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-5", 0, 0.0, 6.02e-22, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-6", 0, 0.0, 806e-3, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-7", 0, 0.0, 2.51e-21, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-8", 0, 0.0, 119.5e-3, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-9", 0, 0.0, 2.5e-21, 4.002603254130));
    helium.ajouterIsotope(Isotope("helium-10", 0, 0.0, 2.60e-22, 4.002603254130));

    Element lithium("Lithium", "Li", 3, 0, "1");
    lithium.ajouterIsotope(Isotope("lithium-3", 0, 0.0, 4.5e-22, 3.0308));
    lithium.ajouterIsotope(Isotope("lithium-4", 1, 0.0, 8.6e-22, 4.02719));
    lithium.ajouterIsotope(Isotope("lithium-5", 2, 0.0, 7.6e-22, 5.01254));
    lithium.ajouterIsotope(Isotope("lithium-6", 3, 0.0759, 8.59e-22, 6.015122795));
    lithium.ajouterIsotope(Isotope("lithium-7", 4, 0.9241, 8.59e-22, 7.01600455));


    std::cout << hydrogen.toString() << std::endl;
    std::cout << helium.toString() << std::endl;
    std::cout << lithium.toString() << std::endl;

    return 0;
}
