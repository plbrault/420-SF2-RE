#include <iostream>
#include <fstream>
#include "IntegerMatrixParser.h"
#include "fonctions.h"

using namespace std;

int main() {
	IntegerMatrixParser parser;
	string nomFichier;
	ifstream fichier;
	vector<vector<int>> carte;

	cout << "Entrer le nom du fichier de carte à charger : ";
	cin >> nomFichier;

	fichier.open(nomFichier);
	if (!fichier) {
		cerr << "Impossible d'ouvrir le fichier " << nomFichier << endl;
		return 1;
	}
	parser.parse(fichier);
	fichier.close();

	carte = parser.getData();

	cout << "Altitude du plus haut sommet atteignable par une pente constante: " << trouverPlusHautSommet(carte) << endl;
}
