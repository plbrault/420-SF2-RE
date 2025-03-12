#include "Chat.h"
#include <iostream>

using namespace std;

void Chat::faireUnSon() {
    if (this->_appetit < 50) {
        std::cout << "Miaou!" << std::endl;
    } else {
        std::cout << "MIAAAOUUUU!!!" << std::endl;
    }
}

void Chat::dormir() {
    Felin::dormir();
    cout << "*rêve qu'il chasse une souris*" << endl;
}