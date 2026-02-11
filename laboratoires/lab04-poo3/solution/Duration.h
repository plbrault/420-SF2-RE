#ifndef SOLUTION_DURATION_H
#define SOLUTION_DURATION_H

#include <iostream>

class Duration {
private:
    unsigned int _totalSeconds;
public:
    Duration() : Duration(0) {}
    Duration(unsigned int totalSeconds);
    Duration(unsigned int hours, unsigned int minutes, unsigned int seconds);

    unsigned int getTotalSeconds() const;
    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;

    Duration& addHours(unsigned int hours);
    Duration& addMinutes(unsigned int minutes);
    Duration& addSeconds(unsigned int seconds);
    Duration& subtractHours(unsigned int hours);
    Duration& subtractMinutes(unsigned int minutes);
    Duration& subtractSeconds(unsigned int seconds);

    std::string toString() const;

    void print(std::ostream& output) const;
};


#endif //SOLUTION_DURATION_H