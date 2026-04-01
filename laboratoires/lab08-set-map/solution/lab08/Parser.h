#pragma once

#include <iostream>
#include <string>

class Parser {
public:
    virtual void parse(std::istream& in) = 0;
};
