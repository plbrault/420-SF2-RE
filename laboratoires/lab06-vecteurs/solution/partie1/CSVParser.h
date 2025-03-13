#include <iostream>
#include <vector>
#include <string>
#include "Parser.h"

class CSVParser : public Parser {
private:
    char _delimiter;
    bool _readsColumnNames;
    std::vector<std::vector<std::string>> _data;
    std::vector<std::string> _columnNames;
public:
    CSVParser(char delimiter=',', bool readColumnNames = true);

    char getDelimiter() const;
    void setDelimiter(char delimiter);
    bool readsColumnNames() const;
    void setReadsColumnNames(bool readsColumnNames);

    void parse(std::istream& in) override;
    const std::vector<std::vector<std::string>>& getData() const;
    const std::vector<std::string>& getColumnNames() const;
    const std::vector<std::string>& getRow(size_t index) const;
    const std::string& getCell(size_t row, size_t column) const;
    const std::string& getCell(size_t row, const std::string& columnName) const;
    const size_t getNumRows() const;
    const size_t getNumColumns() const;
};