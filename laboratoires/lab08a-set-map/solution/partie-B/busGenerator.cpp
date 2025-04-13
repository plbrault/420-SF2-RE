#include "busGenerator.h"

Autobus BusGenerator::generateBus(int familyCount) {
    Autobus bus;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(2, 6);
    uint8_t size = 0;
    
    do {
        size = static_cast<uint8_t>(dist(gen));
    } while(bus.climbUp(size));


    return bus;
}
