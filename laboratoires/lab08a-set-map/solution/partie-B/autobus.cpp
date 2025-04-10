#include "autobus.h"

#include <stdexcept>

bool Autobus::climbUp(const Family &family) {
    if (this->_size + family.getSize() <= AUTOBUS_MAX_SIZE) {
        this->_families.push(family);
        this->_size += family.getSize();
    }
}

bool Autobus::isEmpty() const {
    return this->_size == 0;
}

Family Autobus::climbDown() {
    if (this->isEmpty()) {
        throw std::runtime_error("Autobus est vide.");
    }
    Family result = this->_families.top();
    this->_size -= result.getSize();
    this->_families.pop();
    return result;
}
