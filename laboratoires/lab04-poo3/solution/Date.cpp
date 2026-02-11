//
// Created by plbrault on 2026-02-11.
//

#include "Date.h"
#include <sstream>

const unsigned int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isBisextile(unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->setValue(year, month, day);
}

unsigned int Date::getYear() const {
    return _year;
}

unsigned int Date::getMonth() const {
    return _month;
}

unsigned int Date::getDay() const {
    return _day;
}

void Date::setValue(unsigned int year, unsigned int month, unsigned int day) {
    if (month < 1 || month > 12) {
        throw std::out_of_range("Le mois doit être compris entre 1 et 12");
    }
    if (month == 2 && isBisextile(year)) {
        if (day < 1 || day > 29) {
            throw std::out_of_range("Le jour doit être compris entre 1 et 29 pour le mois de février d'une année bissextile");
        }
    } else if (day < 1 || day > DAYS_IN_MONTH[month - 1]) {
        throw std::out_of_range("Le jour doit être compris entre 1 et le nombre de jours du mois");
    }
    this->_year = year;
    this->_month = month;
    this->_day = day;
}

std::string Date::toString() const {
    std::stringstream out;
    out << this->_year << "-";
    if (this->_month < 10) {
        out << 0;
    }
    out << this->_month << "-";
    if (this->_day < 10) {
        out << 0;
    }
    out << this->_day;
    return out.str();
}

void Date::print(std::ostream& output) const {
    output << this->toString();
}

void Date::read(std::istream& input) {
    unsigned int year, month, day;
    char sep1, sep2;
    input >> year >> sep1 >> month >> sep2 >> day;
    this->setValue(year, month, day);
}

std::ostream& operator<<(std::ostream& output, const Date& date) {
    date.print(output);
    return output;
}

std::istream& operator>>(std::istream& input, Date& date) {
    date.read(input);
    return input;
}

bool Date::operator==(const Date& other) const {
    return this->_year == other._year && this->_month == other._month && this->_day == other._day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (this->_year != other._year) {
        return this->_year < other._year;
    }
    if (this->_month != other._month) {
        return this->_month < other._month;
    }
    return this->_day < other._day;
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}
