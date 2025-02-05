#include <iostream>
#include "CompteBancaire.h"

using namespace std;

int main() {
	CompteBancaire compteCheques;
	CompteBancaire compteEpargne;

	// Déposer 1500$ dans le compte chèques
	compteCheques.deposer(1500);

	// Retirer 200$ du compte chèques
	compteCheques.retirer(200);

	// Déposer 200$ dans le compte épargne
	compteEpargne.deposer(200);

	// Calculer puis afficher le solde total des deux comptes
	float soldeTotal = compteCheques.getSolde() + compteEpargne.getSolde();
	cout << "Solde total: " << soldeTotal;
}