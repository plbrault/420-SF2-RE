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

	// Ce code ne compile pas car l'attribut "_solde" est privé
	float soldeTotal = compteCheques._solde + compteEpargne._solde;
	cout << "Solde total: " << soldeTotal;
}