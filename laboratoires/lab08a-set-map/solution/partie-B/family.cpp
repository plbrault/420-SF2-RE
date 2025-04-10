#include "family.h"

Family::Family() : Family(2) { }

Family::Family(uint8_t size) {
    this->_size = size;
}

uint8_t Family::getSize() const {
    return this->_size;
}