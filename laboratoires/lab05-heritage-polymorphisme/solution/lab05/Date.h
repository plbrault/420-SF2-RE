#ifndef SOLUTION_DATE_H
#define SOLUTION_DATE_H

#include <iostream>

class Date {
private:
    unsigned int _year;
    unsigned int _month;
    unsigned int _day;
public:
    Date(): Date(0, 1, 1) {}
    Date(unsigned int year, unsigned int month, unsigned int day);

    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;

    void setValue(unsigned int year, unsigned int month, unsigned int day);

    std::string toString() const;

    void print(std::ostream& output) const;
    void read(std::istream& input);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
};

std::ostream& operator<<(std::ostream& output, const Date& date);
std::istream& operator>>(std::istream& input, Date& date);

#endif //SOLUTION_DATE_H