#include "Felin.h"
#include <iostream>

Felin::Felin(int appetit, int sommeil) {
    _appetit = appetit;
    _sommeil = sommeil;
}

void Felin::manger() {
    std::cout << "Le félin mange." << std::endl;
    _appetit--;
}

void Felin::dormir() {
    std::cout << "ZZZzzzZZZzzz" << std::endl;
    _sommeil++;
}
