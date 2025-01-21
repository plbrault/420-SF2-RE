#include <iostream>

using namespace std;

int main() {
    locale::global(locale{ "" });

    // Étape 1

    int nombre;

    cout << "L'adresse de la variable \"nombre\" est: " << &nombre << endl;

    // Étape 2

    int *pointeurNombre = nullptr;

    cout << "pointeurNombre contient l'adresse: " << pointeurNombre << endl;

    // Étape 3

    nombre = 42;
    pointeurNombre = &nombre;

    cout << "Adresse de nombre: " << &nombre << endl
        << "Valeur de nombre: " << nombre << endl
        << "Adresse pointée par pointeurNombre: " << &pointeurNombre << endl
        << "Valeur pointée par pointeurNombre: " << *pointeurNombre << endl;
}
