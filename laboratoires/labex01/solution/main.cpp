#include <iostream>

#include "string.h"

int main () {
    sim::String myString;
    sim::String anotherString("Hello");
    sim::String copyString(anotherString);
    sim::String dashes(15, '-');

    std::cout << myString.getLength() << std::endl;
    std::cout << anotherString << std::endl << copyString << std::endl << dashes << std::endl;

    sim::String testAdd = anotherString + dashes;

    std::cout << testAdd << std::endl;

    return 0;
}