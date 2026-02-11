#include "Time.h"
#include <stdexcept>
#include <sstream>

Time::Time(int hours, int minutes, int seconds) {
    this->setHours(hours);
    this->setMinutes(minutes);
    this->setSeconds(seconds);
}

void Time::setHours(int hours) {
    if (hours < 0 || hours > 23) {
        throw std::out_of_range("Les heures doivent être comprises entre 0 et 23.");
    }
    this->_hours = hours;
}

void Time::setMinutes(int minutes) {
    if (minutes < 0 || minutes > 59) {
        throw std::out_of_range("Les minutes doivent être comprises entre 0 et 59.");
    }
    this->_minutes = minutes;
}

void Time::setSeconds(int seconds) {
    if (seconds < 0 || seconds > 59) {
        throw std::out_of_range("Les minutes doivent être comprises entre 0 et 59.");
    }
    this->_seconds = seconds;
}

int Time::getHours() const {
    return this->_hours;
}

int Time::getMinutes() const {
    return this->_minutes;
}

int Time::getSeconds() const {
    return this->_seconds;
}

std::string Time::toString() const {
    std::stringstream out;
    if (this->_hours < 10) {
        out << 0;
    }
    out << this->_hours << ':';
    if (this->_minutes < 10) {
        out << 0;
    }
    out << this->_minutes << ":";
    if (this->_seconds < 10) {
        out << 0;
    }
    out << this->_seconds;
    return out.str();
}
