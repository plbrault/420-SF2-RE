#include <iostream>
#include "Felin.h"
#include "Chat.h"
#include "Lion.h"

using namespace std;

void dormirF(Felin& felin) {
    felin.dormir();
}

void dormirC(Chat& chat) {
    chat.dormir();
}

int main() {
    Chat felix;

    dormirF(felix); // Affiche ZZZzzzMiaouuuuuuuZZZzzz
    dormirC(felix); // Affiche ZZZzzzMiaouuuuuuuZZZzzz
}
