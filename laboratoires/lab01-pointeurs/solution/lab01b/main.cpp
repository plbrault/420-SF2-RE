#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
	float* nombres = nullptr;
	int nombreValeurs;

	cout << "Combien de nombres voulez-vous entrer? ";
	cin >> nombreValeurs;

	if (nombreValeurs > 0) {
		nombres = new float[nombreValeurs];
		demanderNombres(nombres, 0, nombreValeurs - 1);
		afficherMoyenne(nombreValeurs, calculerMoyenne(nombres, nombreValeurs));
	}

	cout << "Voulez-vous ajouter d'autres nombres? (o/n) ";
	if (repondOui()) {
		int nombreNouvellesValeurs;

		cout << "Combien de nouveaux nombres voulez-vous ajouter? ";
		cin >> nombreNouvellesValeurs;

		if (nombreNouvellesValeurs > 0) {
			float* nouveauTableau = new float[nombreValeurs + nombreNouvellesValeurs];
			copierTableau(nombres, nombreValeurs, nouveauTableau);
			delete[] nombres;
			nombres = nouveauTableau;

			demanderNombres(nombres, nombreValeurs, nombreValeurs + nombreNouvellesValeurs - 1);
			nombreValeurs = nombreValeurs + nombreNouvellesValeurs;
			afficherMoyenne(nombreValeurs, calculerMoyenne(nombres, nombreValeurs));
		}
	}

	delete[] nombres;
}
