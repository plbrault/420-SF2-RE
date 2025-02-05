#include <iostream>
#include "CompteBancaire.h"

using namespace std;

int main() {
	CompteBancaire compteCheques;
	CompteBancaire compteEpargne;

	// D�poser 1500$ dans le compte ch�ques
	compteCheques.deposer(1500);

	// Retirer 200$ du compte ch�ques
	compteCheques.retirer(200);

	// D�poser 200$ dans le compte �pargne
	compteEpargne.deposer(200);

	// Calculer puis afficher le solde total des deux comptes
	float soldeTotal = compteCheques.getSolde() + compteEpargne.getSolde();
	cout << "Solde total: " << soldeTotal;
}