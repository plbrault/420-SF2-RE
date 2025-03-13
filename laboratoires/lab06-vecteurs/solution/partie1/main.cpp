#include <iostream>
#include "fonctions.h"

using namespace std;

int main() {
    vector<Element> elements = parseElements("elements.csv");
    for (Element element : elements) {
        cout << element.toString() << endl;
    }

    return 0;
}