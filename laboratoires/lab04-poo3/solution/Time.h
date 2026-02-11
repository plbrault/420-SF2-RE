#ifndef SOLUTION_TIME_H
#define SOLUTION_TIME_H

#include <iostream>

class Time {
private:
    unsigned int _hours;
    unsigned int _minutes;
    unsigned int _seconds;
public:
    Time() : Time(0, 0, 0) {}
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds);

    void setHours(unsigned int hours);
    void setMinutes(unsigned int minutes);
    void setSeconds(unsigned int seconds);

    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;

    std::string toString() const;

    void print(std::ostream& output) const;
    void read(std::istream& input);
};

std::ostream& operator<<(std::ostream& output, const Time& time);
std::istream& operator>>(std::istream& input, Time& time);

#endif //SOLUTION_TIME_H