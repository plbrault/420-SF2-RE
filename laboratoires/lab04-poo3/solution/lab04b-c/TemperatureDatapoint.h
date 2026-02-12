#ifndef SOLUTION_TEMPERATUREDATAPOINT_H
#define SOLUTION_TEMPERATUREDATAPOINT_H

#include "DateTime.h"
#include <iostream>

class TemperatureDatapoint {
private:
    DateTime _datetime;
    double _temperature;
public:
    TemperatureDatapoint() : TemperatureDatapoint(DateTime(), 0.0) {}
    TemperatureDatapoint(const DateTime& datetime, double temperature);

    const DateTime& getDateTime() const;
    double getTemperature() const;

    void setDateTime(const DateTime& timestamp);
    void setTemperature(double temperature);

    void print(std::ostream& output) const;
    void read(std::istream& input);

    bool operator==(const TemperatureDatapoint& other) const;
    bool operator!=(const TemperatureDatapoint& other) const;
};

std::ostream& operator<<(std::ostream& output, const TemperatureDatapoint& datapoint);
std::istream& operator>>(std::istream& input, TemperatureDatapoint& datapoint);

#endif //SOLUTION_TEMPERATUREDATAPOINT_H