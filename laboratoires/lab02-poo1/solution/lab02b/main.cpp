#include <iostream>
#include "Parabole.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    double a, b, c, x;

    std::cout << "Entrez la valeur de a: ";
    std::cin >> a;
    std::cout << "Entrez la valeur de b: ";
    std::cin >> b;
    std::cout << "Entrez la valeur de c: ";
    std::cin >> c;

    Parabole parabole(a, b, c);

    std::cout << std::endl <<  "Équation: " << parabole.obtenirEquation() << std::endl;

    std::cout << std::endl <<  "Entrez la valeur de x: ";
    std::cin >> x;

    std::cout << "Valeur de y: " << parabole.evaluerY(x) << std::endl;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}