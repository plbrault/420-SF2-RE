#include "disk.h"

Disk::Disk(uint8_t length) {
    this->_length = length;
}

uint8_t Disk::getLength() const {
    return this->_length;
}

std::ostream &operator<<(std::ostream &os, const Disk &disk) {
    for (std::size_t i = disk._length; i < 13; i++) {
        os << ' ';
    }

    os << "▐";

    for (std::size_t i = 1; i < disk._length; i++) {
        os << "█";
    }

    os << "░▓░";

    for (std::size_t i = 1; i < disk._length; i++) {
        os << "█";
    }

    os << "▌";

    for (std::size_t i = disk._length; i < 13; i++) {
        os << ' ';
    }
    
    return os;
}