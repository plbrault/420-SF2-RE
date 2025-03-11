#include "Chat.h"
#include <iostream>

void Chat::faireUnSon() {
    if (this->_appetit < 50) {
        std::cout << "Miaou!" << std::endl;
    } else {
        std::cout << "MIAAAOUUUU!!!" << std::endl;
    }
}
