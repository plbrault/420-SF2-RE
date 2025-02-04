#pragma once

#include <iostream>
#include <fstream>

class CompteBancaire {
private:
	std::ofstream _fichierOperations;
public:
	float solde;

	CompteBancaire();
	void deposer(float montant);
	bool retirer(float montant);
};
