#ifndef __AUTOBUS_H
#define __AUTOBUS_H

#include <cstdint>
#include <stack>
#include "family.h"

#define AUTOBUS_MAX_SIZE 80

class Autobus {
private:
    std::stack<Family> _families;
    uint8_t _size;

public:
    bool climbUp(const Family &family);
    bool isEmpty() const;
    Family climbDown();
};

#endif
