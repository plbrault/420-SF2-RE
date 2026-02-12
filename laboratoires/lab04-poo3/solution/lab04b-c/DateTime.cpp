//
// Created by plbrault on 2026-02-11.
//

#include "DateTime.h"

DateTime::DateTime(const Date& date, const Time& time) {
    this->setDate(date);
    this->setTime(time);
}

const Date& DateTime::getDate() const {
    return this->_date;
}

const Time& DateTime::getTime() const {
    return this->_time;
}

void DateTime::setDate(const Date& date) {
    this->_date = date;
}

void DateTime::setTime(const Time& time) {
    this->_time = time;
}

std::string DateTime::toString() const {
    return this->_date.toString() + "T" + this->_time.toString();
}

void DateTime::print(std::ostream& output) const {
    output << this->toString();
}

void DateTime::read(std::istream& input) {
    Date date;
    Time time;
    char separator;

    input >> date >> separator >> time;

    this->setDate(date);
    this->setTime(time);
}

std::ostream& operator<<(std::ostream& output, const DateTime& dateTime) {
    dateTime.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, DateTime& dateTime) {
    dateTime.read(input);
    return input;
}

bool DateTime::operator==(const DateTime& other) const {
    return this->_date == other._date && this->_time == other._time;
}

bool DateTime::operator!=(const DateTime& other) const {
    return !(*this == other);
}

bool DateTime::operator<(const DateTime& other) const {
    if (this->_date != other._date) {
        return this->_date < other._date;
    }
    return this->_time < other._time;
}

bool DateTime::operator<=(const DateTime& other) const {
    return *this < other || *this == other;
}

bool DateTime::operator>(const DateTime& other) const {
    return !(*this <= other);
}

bool DateTime::operator>=(const DateTime& other) const {
    return !(*this < other);
}
