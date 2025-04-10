#include <iostream>

#include "hanoi.h"

int main () {
    std::cout << "Lab 8" << std::endl;

    Hanoi game;
    game.newGame();
    
    std::cout << game << std::endl;

    return 0;
}
