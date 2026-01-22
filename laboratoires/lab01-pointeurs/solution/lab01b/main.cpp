#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
	double* nombres = nullptr;
	int nombreValeurs;

	cout << "Combien de nombres voulez-vous entrer? ";
	cin >> nombreValeurs;

	if (nombreValeurs > 0) {
		nombres = new double[nombreValeurs];
		demanderNombres(nombres, 0, nombreValeurs - 1);
		afficherMoyenne(nombreValeurs, calculerMoyenne(nombres, nombreValeurs));
	}

	cout << "Voulez-vous ajouter d'autres nombres? (o/n) ";
	char reponse;
	cin >> reponse;
	if (toupper(reponse) == 'O') {
		int nombreNouvellesValeurs;

		cout << "Combien de nouveaux nombres voulez-vous ajouter? ";
		cin >> nombreNouvellesValeurs;

		if (nombreNouvellesValeurs > 0) {
			double* nouveauTableau = new double[nombreValeurs + nombreNouvellesValeurs];
			for (int i = 0; i < nombreValeurs; i++) {
				nouveauTableau[i] = nombres[i];
			}
			delete[] nombres;
			nombres = nouveauTableau;

			demanderNombres(nombres, nombreValeurs, nombreValeurs + nombreNouvellesValeurs - 1);
			nombreValeurs = nombreValeurs + nombreNouvellesValeurs;
			afficherMoyenne(nombreValeurs, calculerMoyenne(nombres, nombreValeurs));
		}
	}

	delete[] nombres;

	// Allocation d'un tableau de 5 éléments
	int* monTableau = new int[5];

	// Insertion de données dans monTableau
	for (int i = 0; i < 5; i++) {
		monTableau[i] = i * i;
	}
}
