#include <iostream>

#include "tower.h"

int main () {
    std::cout << "Lab 8" << std::endl;

    Tower east;

    for (size_t i = 8; i > 0; i--) {
        east.push(Disk(i));
    }
    
    std::cout << east << std::endl;

    return 0;
}
