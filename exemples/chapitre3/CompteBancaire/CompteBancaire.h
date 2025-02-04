#pragma once

#include <iostream>
#include <fstream>

class CompteBancaire {
private:
	std::ofstream _fichierOperations;
	float _solde;
public:
	CompteBancaire();
	void deposer(float montant);
	bool retirer(float montant);
};
