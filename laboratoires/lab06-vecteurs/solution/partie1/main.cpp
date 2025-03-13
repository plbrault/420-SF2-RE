#include <iostream>
#include "CSVParser.h"

using namespace std;

int main() {
    CSVParser parser;

    cout << "Data format: " << parser.getDataFormat() << endl;

    return 0;
}