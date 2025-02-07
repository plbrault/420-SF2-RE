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

    

    wow.setCoordonnee(0, 0.5);
    wow.setCoordonnee(1, 0.8);
    wow.setCoordonnee(2, 0.98);
    wow.setCoordonnee(3, 1.16);

    std::cout << "a: " << a.toString() << std::endl;
    std::cout << "b: " << b.toString() << std::endl;
    std::cout << "c: " << c.toString() << std::endl;
    std::cout << "wow: " << wow.toString() << std::endl;

    Point d(a);

    a.setCoordonnee(0, 0.0104);

    Point e(3);

    e.setCoordonnee(0, 9.5);
    e.setCoordonnee(1, 9.8);
    e.setCoordonnee(2, 9.98);

    b = e;

    b.setCoordonnee(0, 8.58);
    
    c = wow;

    c.setCoordonnee(0, 7.7);

    std::cout << "a: " << a.toString() << std::endl;
    std::cout << "b: " << b.toString() << std::endl;
    std::cout << "c: " << c.toString() << std::endl;
    std::cout << "d: "<< d.toString() << std::endl;
    std::cout << "e: "<< e.toString() << std::endl;
    std::cout << "wow: " << wow.toString() << std::endl;

    Point p1;                       // On garde (0.0, 0.0)
    Point p2, p3;

    p2.setCoordonnee(0, 1.0);       // (1.0, 0.0)
    p3.setCoordonnee(1, 1.0);       // (0.0, 1.0);

    Triangle t1(p1, p2, p3);        // Devrait être valide et rectangle
    bool estValide = t1.estValide();
    bool estRectangle = t1.estRectangle();

    Point interieur, exterieur;
    interieur.setCoordonnee(0, 0.2);
    interieur.setCoordonnee(1, 0.2);
    exterieur.setCoordonnee(0, 0.8);
    exterieur.setCoordonnee(1, 0.8);
    
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