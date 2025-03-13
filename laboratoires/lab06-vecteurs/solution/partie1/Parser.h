#include <iostream>
#include <string>

class Parser {
private:
    std::string _dataFormat;
public:
    Parser(const std::string& dataFormat);
    const std::string& getDataFormat() const;

    virtual void parse(std::istream& in) = 0;
};