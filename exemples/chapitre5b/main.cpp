#include <iostream>
#include "Felin.h"
#include "Chat.h"
#include "Lion.h"

using namespace std;

int main() {
    Chat felix;
    Lion simba;

    felix.faireUnSon();
    felix.dormir();
    felix.faireUnSon();

    simba.faireUnSon();
    simba.dormir();
    simba.faireUnSon();
}
