#include <iostream>

using namespace std;

void demanderNombres(double nombres[], size_t indexMin, size_t indexMax) {
    for (size_t i = indexMin; i <= indexMax; i++) {
        cout << "Entrez le nombre #" << (i + 1) << ": ";
        cin >> nombres[i];
    }
}

double calculerMoyenne(double nombres[], size_t nombreValeurs) {
    double somme = 0;
    for (size_t i = 0; i < nombreValeurs; i++) {
        somme += nombres[i];
    }
    return somme / nombreValeurs;
}

void afficherMoyenne(size_t nombreValeurs, double moyenne) {
    cout << "La moyenne des " << nombreValeurs << " nombres est " << moyenne << "." << endl;
}
