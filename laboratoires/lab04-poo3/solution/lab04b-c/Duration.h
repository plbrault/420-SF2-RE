#ifndef SOLUTION_DURATION_H
#define SOLUTION_DURATION_H

#include <iostream>

class Duration {
private:
    unsigned long int _totalSeconds;
public:
    Duration() : Duration(0) {}
    Duration(unsigned long int totalSeconds);
    Duration(unsigned int hours, unsigned int minutes, unsigned int seconds);

    unsigned long int getTotalSeconds() const;
    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;

    Duration& addHours(unsigned int hours);
    Duration& addMinutes(unsigned int minutes);
    Duration& addSeconds(unsigned long int seconds);
    Duration& subtractHours(unsigned int hours);
    Duration& subtractMinutes(unsigned int minutes);
    Duration& subtractSeconds(unsigned long int seconds);

    std::string toString() const;

    void print(std::ostream& output) const;
    void read(std::istream& input);

    bool operator==(const Duration& other) const;
    bool operator!=(const Duration& other) const;
    bool operator<(const Duration& other) const;
    bool operator<=(const Duration& other) const;
    bool operator>(const Duration& other) const;
    bool operator>=(const Duration& other) const;

    Duration& operator+=(const Duration& other);
    Duration operator+(const Duration& other) const;
    Duration& operator-=(const Duration& other);
    Duration operator-(const Duration& other) const;

    Duration& operator*=(double factor);
    Duration operator*(double factor) const;
    Duration& operator/=(double divisor);
    Duration operator/(double divisor) const;
    double operator/=(const Duration& divisor) const;
    double operator/(const Duration& divisor) const;
};

std::ostream& operator<<(std::ostream& output, const Duration& duration);
std::istream& operator>>(std::istream& input, Duration& duration);

#endif //SOLUTION_DURATION_H