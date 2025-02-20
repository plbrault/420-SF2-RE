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
    sim::String testAddLiteral = anotherString + " avons du plaisir";
    sim::String testLiteral = "Beaucoup!";

    std::cout << testAdd << std::endl;
    std::cout << testAddLiteral << std::endl;
    std::cout << testLiteral << std::endl;

    return 0;
}