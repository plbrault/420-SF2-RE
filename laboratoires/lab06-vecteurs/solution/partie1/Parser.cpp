#include "Parser.h"

Parser::Parser(const std::string& dataFormat) {
    _dataFormat = dataFormat;
}

const std::string& Parser::getDataFormat() const {
    return _dataFormat;
}
