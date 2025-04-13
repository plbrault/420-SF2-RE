#ifndef __BUS_GENERATOR_H
#define __BUS_GENERATOR_H

#include "autobus.h"
#include <vector>
#include <random>

class BusGenerator {
public:
    Autobus generateBus(int familyCount);
};

#endif
