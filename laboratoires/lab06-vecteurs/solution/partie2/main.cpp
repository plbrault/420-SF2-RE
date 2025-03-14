#include <iostream>
#include <fstream>
#include "IntegerMatrixParser.h"

using namespace std;

int main() {
	IntegerMatrixParser parser;
	string nomFichier;
	ifstream fichier;

	cout << "Entrer le nom du fichier de carte à charger : ";
	cin >> nomFichier;

	fichier.open(nomFichier);
	if (!fichier) {
		cerr << "Impossible d'ouvrir le fichier " << nomFichier << endl;
		return 1;
	}

	parser.parse(fichier);

	fichier.close();

	cout << parser.getData().size();
}
