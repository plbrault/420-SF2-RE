#include <iostream>
#include "fonctions.h"

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
        << "Adresse pointée par pointeurNombre: " << pointeurNombre << endl
        << "Valeur pointée par pointeurNombre: " << *pointeurNombre << endl;

    // Étape 4

    cout << "&pointeurNombre = " << &pointeurNombre << endl;

    // Étape 5

    string *pointeurString = nullptr;

    pointeurString = new string;

    *pointeurString = "Bonjour le monde!";

    cout << *pointeurString << endl;

    delete pointeurString;
    pointeurString = nullptr;

    // Étape 6

    afficherValeurPointeur(pointeurString);
    pointeurString = new string;
    *pointeurString = "Hello World!";
    afficherValeurPointeur(pointeurString);

    // Étape 7

    string  *prenom = new string,
            *nom = new string;

    cout << "Votre prénom: ";
    cin >> *prenom;

    cout << "Votre nom: ";
    cin >> *nom;

    cout << "Votre nom complet est " << *prenom << " " << *nom << "." << endl;

    delete prenom;
    delete nom;
    prenom = nullptr;
    nom = nullptr;

    // Étape 8

    char *caractere1 = new char, *caractere2 = new char;

    *caractere1 = 'A';
    *caractere2 = 'B';

    cout << "caractere1: " << *caractere1 << endl
        << "caractere2: " << *caractere2 << endl;

    char* temp = caractere1;
    caractere1 = caractere2;
    caractere2 = temp;

    cout << "caractere1: " << *caractere1 << endl
        << "caractere2: " << *caractere2 << endl;

    delete caractere1;
    delete caractere2;
    caractere1 = caractere2 = nullptr;
}
