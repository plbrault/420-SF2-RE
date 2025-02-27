#include "Chat.h"
#include <iostream>

void Chat::miauler() {
    if (this->_appetit < 50) {
        std::cout << "Miaou!" << std::endl;
    } else {
        std::cout << "MIAAAOUUUU!!!" << std::endl;
    }
}
