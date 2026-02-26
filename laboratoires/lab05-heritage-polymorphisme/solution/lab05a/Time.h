#ifndef SOLUTION_TIME_H
#define SOLUTION_TIME_H

#include <iostream>
#include "Duration.h"

class Time : public Duration {
public:
    Time() : Time(0, 0, 0) {}
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds) : Duration(hours, minutes, seconds) {}

    void setTotalSeconds(unsigned long int totalSeconds);
    void setHours(unsigned int hours);
    Time& addHours(unsigned int hours);
    Time& addMinutes(unsigned int minutes);
    Time& addSeconds(unsigned int seconds);

    Time& operator+=(const Duration& duration);
    Time operator+(const Duration& duration) const;
    Time& operator-=(const Duration& duration);
    Time operator-(const Duration& duration) const;

    Duration& operator*=(double factor) = delete;
    Duration operator*(double factor) = delete;
    Duration& operator/=(double divisor) = delete;
    Duration operator/(double divisor) = delete;
    double operator/(const Duration& divisor) = delete;
};

#endif //SOLUTION_TIME_H