#pragma once

#include <iostream>
#include <fstream>

class CompteBancaire {
private:
	std::ofstream _fichierOperations;
	std::string _nom;
	float _solde;
public:
	CompteBancaire();
	void deposer(float montant);
	bool retirer(float montant);

	std::string getNom() const;
	float getSolde() const;

	void setNom(std::string nom);
};
