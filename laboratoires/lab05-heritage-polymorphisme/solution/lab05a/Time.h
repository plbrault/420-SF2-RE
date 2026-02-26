#ifndef SOLUTION_TIME_H
#define SOLUTION_TIME_H

#include <iostream>
#include "Duration.h"

class Time : public Duration {
private:
public:
    Time() : Time(0, 0, 0) {}
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds) : Duration(hours, minutes, seconds) {}

    /*Time& operator+=(const Duration& duration);
    Time operator+(const Duration& duration) const;
    Time& operator-=(const Duration& duration);
    Time operator-(const Duration& duration) const;
    Duration operator-(const Time& other) const;*/
};

#endif //SOLUTION_TIME_H