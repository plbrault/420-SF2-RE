#include <iostream>
#include <map>
#include <string>
#include "JSONParser.h"

using namespace std;

int main() {
    JSONParser jsonParser;

    cout << "Enter JSON string: ";
    jsonParser.parse(cin);

    cout << "Parsed JSON: " << jsonParser.getData().dump() << endl;

    map<string, string> m = jsonParser.getData().template get<map<string, string>>();
    cout << m["allo"] << endl;
}