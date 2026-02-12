//
// Created by plbrault on 2026-02-11.
//

#include "TemperatureDatapoint.h"

TemperatureDatapoint::TemperatureDatapoint(const DateTime &datetime, double temperature) {
    this->_datetime = datetime;
    this->_temperature = temperature;
}

const DateTime &TemperatureDatapoint::getDateTime() const {
    return this->_datetime;
}

double TemperatureDatapoint::getTemperature() const {
    return this->_temperature;
}

void TemperatureDatapoint::setDateTime(const DateTime &timestamp) {
    this->_datetime = timestamp;
}

void TemperatureDatapoint::setTemperature(double temperature) {
    this->_temperature = temperature;
}

void TemperatureDatapoint::print(std::ostream &output) const {
    output << "[" << this->_datetime << "] " << this->_temperature << "°C";
}

void TemperatureDatapoint::read(std::istream &input) {
    input >> this->_datetime >> this->_temperature;
}

bool TemperatureDatapoint::operator==(const TemperatureDatapoint &other) const {
    return this->_datetime == other._datetime && this->_temperature == other._temperature;
}

bool TemperatureDatapoint::operator!=(const TemperatureDatapoint &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &output, const TemperatureDatapoint &datapoint) {
    datapoint.print(output);
    return output;
}

std::istream &operator>>(std::istream &input, TemperatureDatapoint &datapoint) {
    datapoint.read(input);
    return input;
}
