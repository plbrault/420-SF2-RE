#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include "JSONParser.h"

using namespace std;

int main() {
    JSONParser jsonParser;

    //cout << "Enter JSON string: ";
    //jsonParser.parse(cin);

    //cout << "Parsed JSON: " << jsonParser.getData().dump() << endl;

    //map<string, string> m = jsonParser.getData().template get<map<string, string>>();
    //cout << m["allo"] << endl;

    ifstream mots("mots/mots.json");
    if (!mots.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    jsonParser.parse(mots);

    set<string> motsSet = jsonParser.getData().template get<set<string>>();

    if (motsSet.contains("structures")) {
        cout << "Le mot structures est dans le set" << endl;
    }
}