#ifndef SOLUTION_DURATION_H
#define SOLUTION_DURATION_H

#include <iostream>
#include "ISOFormatEntity.h"

class Duration : public ISOFormatEntity {
protected:
    unsigned long int _totalSeconds;
public:
    Duration() : Duration(0) {}
    Duration(unsigned long int totalSeconds);
    Duration(unsigned int hours, unsigned int minutes, unsigned int seconds);

    unsigned long int getTotalSeconds() const;
    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;

    virtual void setTotalSeconds(unsigned long int totalSeconds);
    virtual void setHours(unsigned int hours);
    virtual void setMinutes(unsigned int minutes);
    virtual void setSeconds(unsigned int seconds);

    virtual Duration& addHours(unsigned int hours);
    virtual Duration& addMinutes(unsigned int minutes);
    virtual Duration& addSeconds(unsigned long int seconds);
    virtual Duration& subtractHours(unsigned int hours);
    virtual Duration& subtractMinutes(unsigned int minutes);
    virtual Duration& subtractSeconds(unsigned long int seconds);

    std::string toISOString() const override;

    void print(std::ostream& output) const;
    virtual void read(std::istream& input);

    bool operator==(const Duration& other) const;
    bool operator!=(const Duration& other) const;
    bool operator<(const Duration& other) const;
    bool operator<=(const Duration& other) const;
    bool operator>(const Duration& other) const;
    bool operator>=(const Duration& other) const;

    virtual Duration& operator+=(const Duration& other);
    Duration operator+(const Duration& other) const;
    virtual Duration& operator-=(const Duration& other);
    Duration operator-(const Duration& other) const;

    virtual Duration& operator*=(double factor);
    Duration operator*(double factor) const;
    virtual Duration& operator/=(double divisor);
    Duration operator/(double divisor) const;
    double operator/(const Duration& divisor) const;
};

std::ostream& operator<<(std::ostream& output, const Duration& duration);
std::istream& operator>>(std::istream& input, Duration& duration);

#endif //SOLUTION_DURATION_H