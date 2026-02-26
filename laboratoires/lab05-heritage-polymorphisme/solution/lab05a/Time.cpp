#include "Time.h"
#include <stdexcept>

void Time::setTotalSeconds(unsigned long int totalSeconds) {
    if (totalSeconds >= 24 * 3600) {
        throw std::invalid_argument("Le nombre total de secondes doit être inférieur à 86400 (24 heures).");
    }
    Duration::setTotalSeconds(totalSeconds);
}

void Time::setHours(unsigned int hours) {
    if (hours >= 24) {
        throw std::invalid_argument("Les heures doivent être comprises entre 0 et 23.");
    }
    Duration::setHours(hours);
}

Time& Time::addHours(unsigned int hours) {
    unsigned int previousTotalSeconds = this->getTotalSeconds();
    Duration::addHours(hours);
    if (this->getTotalSeconds() >= 24 * 3600) {
        this->setTotalSeconds(previousTotalSeconds);
        throw std::overflow_error("Heure dépassant la valeur maximale de 23:59:59.");
    }
    return *this;
}

Time& Time::addMinutes(unsigned int minutes) {
    unsigned int previousTotalSeconds = this->getTotalSeconds();
    Duration::addMinutes(minutes);
    if (this->getTotalSeconds() >= 24 * 3600) {
        this->setTotalSeconds(previousTotalSeconds);
        throw std::overflow_error("Heure dépassant la valeur maximale de 23:59:59.");
    }
    return *this;
}

Time& Time::addSeconds(unsigned int seconds) {
    unsigned int previousTotalSeconds = this->getTotalSeconds();
    Duration::addSeconds(seconds);
    if (this->getTotalSeconds() >= 24 * 3600) {
        this->setTotalSeconds(previousTotalSeconds);
        throw std::overflow_error("Heure dépassant la valeur maximale de 23:59:59.");
    }
    return *this;
}

// Time& Time::operator+=(const Duration& duration) {
//     Duration timeAsDuration(this->_hours, this->_minutes, this->_seconds);
//     Duration sum = timeAsDuration + duration;
//     if (sum.getHours() >= 24) {
//         throw std::overflow_error("Heure dépassant la valeur maximale de 23:59:59.");
//     }
//     this->setHours(sum.getHours());
//     this->setMinutes(sum.getMinutes());
//     this->setSeconds(sum.getSeconds());
//     return *this;
// }

// Time Time::operator+(const Duration& duration) const {
//     Time result = *this;
//     result += duration;
//     return result;
// }

// Time& Time::operator-=(const Duration& duration) {
//     Duration timeAsDuration(this->_hours, this->_minutes, this->_seconds);
//     Duration difference = timeAsDuration - duration;
//     this->setHours(difference.getHours());
//     this->setMinutes(difference.getMinutes());
//     this->setSeconds(difference.getSeconds());
//     return *this;
// }
//
// Time Time::operator-(const Duration& duration) const {
//     Time result = *this;
//     result -= duration;
//     return result;
// }
//
// Duration Time::operator-(const Time& other) const {
//     Duration thisAsDuration(this->_hours, this->_minutes, this->_seconds);
//     Duration otherAsDuration(other._hours, other._minutes, other._seconds);
//     return thisAsDuration - otherAsDuration;
// }