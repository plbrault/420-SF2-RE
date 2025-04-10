#ifndef __FAMILY_H
#define __FAMILY_H

#include <cstdint>

class Family {
private:
    uint8_t _size;

public:
    Family();
    Family(uint8_t);

    uint8_t getSize() const;
};

#endif
