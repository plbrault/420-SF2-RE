#include "CSVParser.h"
#include "split.h"
#include <stdexcept>

using namespace std;

CSVParser::CSVParser(char delimiter, bool readColumnNames) : Parser("csv") {
    setDelimiter(delimiter);
    setReadsColumnNames(readColumnNames);
}

char CSVParser::getDelimiter() const {
    return _delimiter;
}

void CSVParser::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

bool CSVParser::readsColumnNames() const {
    return _readsColumnNames;
}

void CSVParser::setReadsColumnNames(bool readsColumnNames) {
    _readsColumnNames = readsColumnNames;
}

void CSVParser::parse(istream& in) {
    _data.clear();
    _columnNames.clear();

    string line;
    if (_readsColumnNames) {
        getline(in, line);
        _columnNames = split(line, _delimiter);
    }
    while (getline(in, line)) {
        _data.push_back(split(line, _delimiter));
    }
}

const vector<vector<string>>& CSVParser::getData() const {
    return _data;
}

const vector<string>& CSVParser::getColumnNames() const {
    return _columnNames;
}

const vector<string>& CSVParser::getRow(size_t index) const {
    if (index >= _data.size()) {
        throw out_of_range("Index out of range.");
    }
    return _data[index];
}

const string& CSVParser::getCell(size_t row, size_t column) const {
    if (row >= _data.size()) {
        throw out_of_range("Row index out of range.");
    }
    if (column >= _data[row].size()) {
        throw out_of_range("Column index out of range.");
    }
    return _data[row][column];
}

const string& CSVParser::getCell(size_t row, const string& columnName) const {
    if (row >= _data.size()) {
        throw out_of_range("Row index out of range.");
    }
    size_t column = -1;
    for (size_t i = 0; i < _columnNames.size(); i++) {
        if (_columnNames[i] == columnName) {
            column = i;
            break;
        }
    }
    if (column == -1) {
        throw invalid_argument("Column name not found.");
    }
    return getCell(row, column);
}

const size_t CSVParser::getNumRows() const {
    return _data.size();
}

const size_t CSVParser::getNumColumns() const {
    if (_data.empty()) {
        return 0;
    }
    return _data[0].size();
}