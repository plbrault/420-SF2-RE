#include <iostream>
#include <iomanip>

int main () {
    Point a(3), b(3), c(3);
    Point wow(4);

    a[0] = 2.5;
    a[1] = 2.8;
    a[2] = 2.95;

    b[0] = 3.5;
    b[1] = 3.8;
    b[2] = 3.98;

    c[0] = 4.5;
    c[1] = 4.8;
    c[2] = 4.98;

    wow[0] = 0.5;
    wow[1] = 0.8;
    wow[2] = 0.98;
    wow[3] = 1.16;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "wow: " << wow << std::endl;

    Point d(a);

    a[0] = 0.0104;

    Point e(3);

    e[0] = 9.5;
    e[1] = 9.8;
    e[2] = 9.98;

    b = e;

    b[0] = 8.58;
    
    c = wow;

    c[0] = 7.7;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "wow: " << wow << std::endl;

    Point p1;                       // On garde (0.0, 0.0)
    Point p2, p3;

    p2[0] = 1.0;                    // (1.0, 0.0)
    p3[1] = 1.0;                    // (0.0, 1.0);

    Triangle t1(p1, p2, p3);        // Devrait être valide et rectangle
    bool estValide = t1.estValide();
    bool estRectangle = t1.estRectangle();

    Point interieur, exterieur;
    interieur[0] = 0.2;
    interieur[1] = 0.2;
    exterieur[0] = 0.8;
    exterieur[1] = 0.8;
    
    bool devrait = t1.estInterieur(interieur);
    bool devraitPas = t1.estInterieur(exterieur);

    std::cout << "Le triangle t1 est un " << (estValide ? "valide" : "invalide") 
                << " triangle. Il est un triangle " << (estRectangle ? "rectangle" : "non rectangle")
                << " ayant une aire de " << t1.getAire() << " m. Le point " << interieur.toString() << " est à "
                << (devrait ? "l'intérieur" : "l'extérieur") << " de t1 et le point " << exterieur.toString() << " est à "
                << (devraitPas ? "l'intérieur" : "l'extérieur") << "." << std::endl;

    Triangle t2(p1, p1, p1);
    std::cout << "Le triangle t2 est un " << (t2.estValide() ? "valide" : "invalide") 
                << " triangle. Il est un triangle " << (t2.estRectangle() ? "rectangle" : "non rectangle")
                << " ayant une aire de " << t2.getAire() << " m." << std::endl;

    return 0;
}