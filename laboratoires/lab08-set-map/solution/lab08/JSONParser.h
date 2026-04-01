#pragma once

#include <map>
#include <string>
#include "json.h"
#include "Parser.h"

class JSONParser : Parser {
private:
    nlohmann::json _data;
public:
    JSONParser() {}
    void parse(std::istream& in) override;
    const nlohmann::json& getData() const;
};
