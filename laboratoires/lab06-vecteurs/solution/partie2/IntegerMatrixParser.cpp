#include "IntegerMatrixParser.h"
#include "fonctions.h"

using namespace std;

IntegerMatrixParser::IntegerMatrixParser(char delimiter) {
	_delimiter = delimiter;
}

char IntegerMatrixParser::getDelimiter() const {
	return _delimiter;
}

void IntegerMatrixParser::setDelimiter(char delimiter) {
	_delimiter = delimiter;
}

const vector<vector<int>>& IntegerMatrixParser::getData() const {
	return _data;
}

void IntegerMatrixParser::parse(istream& in) {
    _data.clear();

    string line;
    vector<string> tokens;
    while (getline(in, line)) {
        tokens = split(line, _delimiter);
        vector<int> row;
        for (string token : tokens) {
			row.push_back(stoi(token));
		}
    }
}
