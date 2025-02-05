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

	// Ce code ne compile pas car l'attribut "_solde" est priv�
	float soldeTotal = compteCheques._solde + compteEpargne._solde;
	cout << "Solde total: " << soldeTotal;
}