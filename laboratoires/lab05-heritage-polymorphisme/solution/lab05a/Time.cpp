#include "Time.h"
#include <stdexcept>
#include <sstream>

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