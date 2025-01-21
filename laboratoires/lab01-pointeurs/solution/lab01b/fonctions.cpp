#include <iostream>

using namespace std;

void demanderNombres(float nombres[], int indexMin, int indexMax) {
	for (int i = indexMin; i <= indexMax; i++) {
		cout << "Entrez le nombre #" << (i + 1) << ": ";
		cin >> nombres[i];
	}
}

float calculerMoyenne(float nombres[], int nombreValeurs) {
	float somme = 0;
	for (int i = 0; i < nombreValeurs; i++) {
		somme += nombres[i];
	}
	return somme / nombreValeurs;
}

void afficherMoyenne(int nombreValeurs, float moyenne) {
	cout << "La moyenne des " << nombreValeurs << " nombres est " << moyenne << "." << endl;
}

bool repondOui() {
	char reponse;
	cin >> reponse;
	return toupper(reponse) == 'O';
}

void copierTableau(float tableauSource[], int tailleSource, float tableauDestination[]) {
	for (int i = 0; i < tailleSource; i++) {
		tableauDestination[i] = tableauSource[i];
	}
}
