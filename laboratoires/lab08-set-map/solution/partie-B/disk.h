#ifndef __DISK_H
#define __DISK_H

#include <cstdint>
#include <string>
#include <sstream>

class Disk {
private:
    uint8_t _length;
public:
    Disk(uint8_t);

    uint8_t getLength() const;

    friend std::ostream &operator<<(std::ostream &os, const Disk &disk);
};

#endif
