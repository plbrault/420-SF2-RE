#include <iostream>
#include <vector>
#include <string>

class CSVParser {
private:
    std::vector<std::vector<std::string>> _data;
    std::vector<std::string> _columnNames;
public:
    void parse(std::istream& in, char delimiter=',', bool hasColumnNames=true);
    const std::vector<std::vector<std::string>>& getData() const;
    const std::vector<std::string>& getColumnNames() const;
    const std::vector<std::string>& getRow(size_t index) const;
    const std::string& getCell(size_t row, size_t column) const;
    const std::string& getCell(size_t row, const std::string& columnName) const;
    const size_t getNumRows() const;
    const size_t getNumColumns() const;
};