#ifndef SOLUTION_DATETIME_H
#define SOLUTION_DATETIME_H

#include <iostream>
#include "Date.h"
#include "Time.h"

class DateTime {
private:
    Date _date;
    Time _time;
public:
    DateTime() : DateTime(Date(), Time()) {}
    DateTime(const Date& date, const Time& time);

    const Date& getDate() const;
    const Time& getTime() const;

    void setDate(const Date& date);
    void setTime(const Time& time);

    std::string toString() const;

    void print(std::ostream& output) const;
    void read(std::istream& input);

    bool operator==(const DateTime& other) const;
    bool operator!=(const DateTime& other) const;
    bool operator<(const DateTime& other) const;
    bool operator<=(const DateTime& other) const;
    bool operator>(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
};

std::ostream& operator<<(std::ostream& output, const DateTime& dateTime);
std::istream& operator>>(std::istream& input, DateTime& dateTime);

#endif //SOLUTION_DATETIME_H