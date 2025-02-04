#include "CompteBancaire.h"

using namespace std;

CompteBancaire::CompteBancaire() {
	solde = 0;
	_fichierOperations.open("operations.txt");
}

void CompteBancaire::deposer(float montant) {
	solde += montant;
	_fichierOperations << "Dépôt de " << montant << endl;
}

bool CompteBancaire::retirer(float montant) {
	if (solde < montant) {
		return false;
	}

	solde -= montant;
	_fichierOperations << "Retrait de " << montant << endl;

	return true;
}
