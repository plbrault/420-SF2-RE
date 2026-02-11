#ifndef SOLUTION_DURATION_H
#define SOLUTION_DURATION_H

#include <iostream>

class Duration {
private:
    int _totalSeconds;
public:
    Duration() : Duration(0) {}
    Duration(int totalSeconds);
    Duration(int hours, int minutes, int seconds);

    int getTotalSeconds() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    Duration& addHours();
    Duration& addMinutes();
    Duration& addSeconds();
    Duration& subtractHours();
    Duration& subtractMinutes();
    Duration& subtractSeconds();

    void print(std::ostream& output) const;
};


#endif //SOLUTION_DURATION_H