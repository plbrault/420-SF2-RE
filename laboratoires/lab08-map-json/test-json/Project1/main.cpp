#include <iostream>
#include "JSONParser.h"

using namespace std;

int main() {
    JSONParser jsonParser;

    cout << "Enter JSON string: ";
    jsonParser.parse(cin);

    cout << "Parsed JSON: " << jsonParser.getData().dump() << endl;
}