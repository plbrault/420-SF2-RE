#ifndef SOLUTION_TEMPERATUREDATAPOINT_H
#define SOLUTION_TEMPERATUREDATAPOINT_H

#include "DateTime.h"
#include <iostream>

class TemperatureDatapoint {
private:
    DateTime _moment;
    double _temperature;
public:
    TemperatureDatapoint() : TemperatureDatapoint(DateTime(), 0.0) {}
    TemperatureDatapoint(const DateTime& datetime, double temperature);

    const DateTime& getMoment() const;
    double getTemperature() const;

    void setMoment(const DateTime& timestamp);
    void setTemperature(double temperature);

    bool operator==(const TemperatureDatapoint& other) const;
    bool operator!=(const TemperatureDatapoint& other) const;

    friend std::ostream& operator<<(std::ostream& output, const TemperatureDatapoint& datapoint);
    friend std::istream& operator>>(std::istream& input, TemperatureDatapoint& datapoint);
};

#endif //SOLUTION_TEMPERATUREDATAPOINT_H