#include "fonctions.h"
#include "CSVParser.h"
#include <fstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    string current;
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    result.push_back(current);
    return result;
}

vector<Element> parseElements(const string& filename) {
    CSVParser parser;

    ifstream elementsFile(filename);
    if (!elementsFile.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return vector<Element>();
    }

    parser.parse(elementsFile);
    elementsFile.close();

    vector<Element> elements;
    for (size_t i = 0; i < parser.getNumRows(); i++) {
        Element element(
            parser.getCell(i, "Nom"),
            parser.getCell(i, "Symbole"),
            stoi(parser.getCell(i, "Nombre de particules chargees")),
            stoi(parser.getCell(i, "Nombre de trous")),
            parser.getCell(i, "Groupe")
        );
        elements.push_back(element);
    }

    return elements;
}