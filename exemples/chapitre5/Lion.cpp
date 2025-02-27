#include "Lion.h"
#include <iostream>

void Lion::rugir() {
    if (_appetit < 50) {
        std::cout << "Rwaar!" << std::endl;
    } else {
        std::cout << "RWAARRRRRR!!!" << std::endl;
    }
}
