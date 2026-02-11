#include "Duration.h"
#include <sstream>

Duration::Duration(unsigned int totalSeconds) {
    this->_totalSeconds = totalSeconds;
}

Duration::Duration(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    this->_totalSeconds = hours * 3600 + minutes * 60 + seconds;
}

unsigned int Duration::getTotalSeconds() const {
    return this->_totalSeconds;
}

unsigned int Duration::getHours() const {
    return this->_totalSeconds / 3600;
}

unsigned int Duration::getMinutes() const {
    return (this->_totalSeconds % 3600) / 60;
}

unsigned int Duration::getSeconds() const {
    return this->_totalSeconds % 60;
}

Duration& Duration::addHours(unsigned int hours) {
    return this->addSeconds(hours * 3600);
}

Duration& Duration::addMinutes(unsigned int minutes) {
    return this->addSeconds(minutes * 60);
}

Duration& Duration::addSeconds(unsigned int seconds) {
    this->_totalSeconds += seconds;
    return *this;
}

Duration& Duration::subtractHours(unsigned int hours) {
    return this->subtractSeconds(hours * 3600);
}

Duration& Duration::subtractMinutes(unsigned int minutes) {
    return this->subtractSeconds(minutes * 60);
}

Duration& Duration::subtractSeconds(unsigned int seconds) {
    if (seconds > this->_totalSeconds) {
        throw std::underflow_error("Une durée ne peut être négative.");
    }
    this->_totalSeconds -= seconds;
    return *this;
}

std::string Duration::toString() const {
    std::stringstream out;
    if (this->getHours() < 10) {
        out << 0;
    }
    out << this->getHours() << ':';
    if (this->getMinutes() < 10) {
        out << 0;
    }
    out << this->getMinutes() << ":";
    if (this->getSeconds() < 10) {
        out << 0;
    }
    out << this->getSeconds();
    return out.str();
}