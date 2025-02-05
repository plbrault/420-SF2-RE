#include "CompteBancaire.h"

using namespace std;

CompteBancaire::CompteBancaire() {
	_solde = 0;
	_fichierOperations.open("operations.txt");
}

void CompteBancaire::deposer(float montant) {
	_solde += montant;
	_fichierOperations << "Dépôt de " << montant << endl;
}

bool CompteBancaire::retirer(float montant) {
	if (_solde < montant) {
		return false;
	}

	_solde -= montant;
	_fichierOperations << "Retrait de " << montant << endl;

	return true;
}

string CompteBancaire::getNom() const {
	return _nom;
}

float CompteBancaire::getSolde() const {
	return _solde;
}

void CompteBancaire::setNom(string nom) {
	_nom = nom;
}
