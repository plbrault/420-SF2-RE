#include "JSONParser.h"

using namespace std;
using json = nlohmann::json;

void JSONParser::parse(std::istream& in) {
    in >> _data;
}

const nlohmann::json& JSONParser::getData() const {
    return _data;
}
