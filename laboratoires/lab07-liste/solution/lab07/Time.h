#ifndef SOLUTION_TIME_H
#define SOLUTION_TIME_H

#include <iostream>
#include "Duration.h"

class Time : public Duration {
public:
    Time() : Time(0, 0, 0) {}
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds) : Duration(hours, minutes, seconds) {}

    void setTotalSeconds(unsigned long int totalSeconds) override;
    void setHours(unsigned int hours) override;
    Time& addHours(unsigned int hours) override;
    Time& addMinutes(unsigned int minutes) override;
    Time& addSeconds(unsigned long int seconds) override;

    void read(std::istream& input) override;

    Time& operator+=(const Duration& duration) override;
    Time operator+(const Duration& duration) const;
    Time& operator-=(const Duration& duration) override;
    Time operator-(const Duration& duration) const;
    Duration operator-(const Time& other) const;

    Duration& operator*=(double factor) override;
    Duration operator*(double factor) = delete;
    Duration& operator/=(double divisor) override;
    Duration operator/(double divisor) = delete;
    double operator/(const Duration& divisor) = delete;
};

std::istream& operator>>(std::istream& input, Time& time);

#endif //SOLUTION_TIME_H