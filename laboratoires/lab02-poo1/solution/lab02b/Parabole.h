#ifndef LAB02B_PARABOLE_H
#define LAB02B_PARABOLE_H

#include <iostream>

class Parabole {
private:
    double _valA;
    double _valB;
    double _valC;
public:
    Parabole();
    Parabole(double valA, double valB, double valC);

    double evaluerY(double x);
    std::string obtenirEquation();
    void afficher(std::ostream& sortie);
    void afficher();
};


#endif //LAB02B_PARABOLE_H