#include "TemperatureDatapoint.h"

TemperatureDatapoint::TemperatureDatapoint(const DateTime &moment, double temperature) {
    this->setMoment(moment);
    this->setTemperature(temperature);
}

const DateTime &TemperatureDatapoint::getMoment() const {
    return this->_moment;
}

double TemperatureDatapoint::getTemperature() const {
    return this->_temperature;
}

void TemperatureDatapoint::setMoment(const DateTime &timestamp) {
    this->_moment = timestamp;
}

void TemperatureDatapoint::setTemperature(double temperature) {
    this->_temperature = temperature;
}

bool TemperatureDatapoint::operator==(const TemperatureDatapoint &other) const {
    return this->_moment == other._moment && this->_temperature == other._temperature;
}

bool TemperatureDatapoint::operator!=(const TemperatureDatapoint &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &output, const TemperatureDatapoint &datapoint) {
    output << "[" << datapoint._moment << "] " << datapoint._temperature << "°C";
    return output;
}

std::istream &operator>>(std::istream &input, TemperatureDatapoint &datapoint) {
    input >> datapoint._moment;
    input >> datapoint._temperature;
    return input;
}
