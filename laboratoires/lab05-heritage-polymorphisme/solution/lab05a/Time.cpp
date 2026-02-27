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

void Time::read(std::istream &input) {
    unsigned long int previousTotalSeconds = this->getTotalSeconds();
    Duration::read(input);
    if (this->getTotalSeconds() >= 24 * 3600) {
        this->setTotalSeconds(previousTotalSeconds);
        throw std::invalid_argument("Heure dépassant la valeur maximale de 23:59:59.");
    }
}

Time& Time::operator+=(const Duration& duration) {
    unsigned int previousTotalSeconds = this->getTotalSeconds();
    Duration::operator+=(duration);
    if (this->getHours() >= 24) {
        this->setTotalSeconds(previousTotalSeconds);
        throw std::overflow_error("Heure dépassant la valeur maximale de 23:59:59.");
    }
    return *this;
}

Time Time::operator+(const Duration& duration) const {
    Time result = *this;
    result += duration;
    return result;
}

Time& Time::operator-=(const Duration& duration) {
    Duration::operator-=(duration);
    return *this;
}

Time Time::operator-(const Duration& duration) const {
    Time result = *this;
    result -= duration;
    return result;
}

std::istream& operator>>(std::istream& input, Time& time) {
    time.read(input);
    return input;
}
