#include "fonctions.h"
#include <iostream>

using namespace std;

void afficherValeurPointeur(string* pointeur) {
    if (pointeur == nullptr) {
        cout << "Le pointeur est nul." << endl;
    } else {
        cout << *pointeur << endl;
    }
}