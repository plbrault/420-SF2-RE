#include "Duration.h"
#include <sstream>
#include <cmath>

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

void Duration::print(std::ostream& output) const {
    output << this->toString();
}

void Duration::read(std::istream &input) {
    unsigned int hours, minutes, seconds;
    char separator1, separator2;

    input >> hours >> separator1 >> minutes >> separator2 >> seconds;

    this->_totalSeconds = 0;
    this->addHours(hours).addMinutes(minutes).addSeconds(seconds);
}

std::ostream& operator<<(std::ostream& output, const Duration& duration) {
    duration.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, Duration& duration) {
    duration.read(input);
    return input;
}

bool Duration::operator==(const Duration& other) const {
    return this->_totalSeconds == other._totalSeconds;
}

bool Duration::operator!=(const Duration& other) const {
    return this->_totalSeconds != other._totalSeconds;
}

bool Duration::operator<(const Duration& other) const {
    return this->_totalSeconds < other._totalSeconds;
}

bool Duration::operator<=(const Duration& other) const {
    return this->_totalSeconds <= other._totalSeconds;
}

bool Duration::operator>(const Duration& other) const {
    return this->_totalSeconds > other._totalSeconds;
}

bool Duration::operator>=(const Duration& other) const {
    return this->_totalSeconds >= other._totalSeconds;
}

Duration& Duration::operator+=(const Duration& other) {
    return this->addSeconds(other._totalSeconds);
}

Duration Duration::operator+(const Duration& other) const {
    Duration result(*this);
    return result += other;
}

Duration& Duration::operator-=(const Duration& other) {
    return this->subtractSeconds(other._totalSeconds);
}

Duration Duration::operator-(const Duration& other) const {
    Duration result(*this);
    return result -= other;
}

Duration& Duration::operator*=(double factor) {
    this->_totalSeconds = std::round(this->_totalSeconds * factor);
    return *this;
}

Duration Duration::operator*(double factor) const {
    Duration result(*this);
    return result *= factor;
}

Duration& Duration::operator/=(double divisor) {
    if (divisor == 0) {
        throw std::invalid_argument("Le diviseur ne peut pas être zéro.");
    }
    this->_totalSeconds = std::round(this->_totalSeconds / divisor);
    return *this;
}

Duration Duration::operator/(double divisor) const {
    Duration result(*this);
    return result /= divisor;
}

double Duration::operator/=(const Duration& divisor) const {
    if (divisor._totalSeconds == 0) {
        throw std::invalid_argument("Le diviseur ne peut pas être zéro.");
    }
    return static_cast<double>(this->_totalSeconds) / divisor._totalSeconds;
}

double Duration::operator/(const Duration& divisor) const {
    return *this /= divisor;
}