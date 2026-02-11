#ifndef SOLUTION_TIME_H
#define SOLUTION_TIME_H

#include <iostream>

class Time {
private:
    int _hours;
    int _minutes;
    int _seconds;
public:
    Time() : Time(0, 0, 0) {}
    Time(int hours, int minutes, int seconds);

    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    std::string toString() const;

    void print(std::ostream& output) const;
    void read(std::istream& input);
};

std::ostream& operator<<(std::ostream& output, const Time& time);
std::istream& operator>>(std::istream& input, Time& time);

#endif //SOLUTION_TIME_H