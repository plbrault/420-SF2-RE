#include "Lion.h"
#include <iostream>

void Lion::faireUnSon() {
    if (_appetit < 50) {
        std::cout << "Rwaar!" << std::endl;
    } else {
        std::cout << "RWAARRRRRR!!!" << std::endl;
    }
}
