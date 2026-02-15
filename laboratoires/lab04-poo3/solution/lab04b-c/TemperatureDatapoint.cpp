#include "TemperatureDatapoint.h"

TemperatureDatapoint::TemperatureDatapoint(const DateTime &datetime, double temperature) {
    this->setDateTime(datetime);
    this->setTemperature(temperature);
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

bool TemperatureDatapoint::operator==(const TemperatureDatapoint &other) const {
    return this->_datetime == other._datetime && this->_temperature == other._temperature;
}

bool TemperatureDatapoint::operator!=(const TemperatureDatapoint &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &output, const TemperatureDatapoint &datapoint) {
    output << "[" << datapoint._datetime << "] " << datapoint._temperature << "°C";
    return output;
}

std::istream &operator>>(std::istream &input, TemperatureDatapoint &datapoint) {
    input >> datapoint._datetime >> datapoint._temperature;
    return input;
}
