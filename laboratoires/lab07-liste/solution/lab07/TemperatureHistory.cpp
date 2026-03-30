#include <fstream>
#include "TemperatureHistory.h"

std::list<TemperatureDatapoint>::iterator TemperatureHistory::findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::iterator start) {
    for (auto it = start; it != this->_datapoints.end(); it++) {
        if (it->getMoment() == moment) {
            return it;
        }
    }
    return this->_datapoints.end();
}

std::list<TemperatureDatapoint>::iterator TemperatureHistory::findDatapoint(const DateTime& moment) {
    return this->findDatapoint(moment, this->_datapoints.begin());
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::const_iterator start) const {
    for (auto it = start; it != this->_datapoints.end(); it++) {
        if (it->getMoment() == moment) {
            return it;
        }
    }
    return this->_datapoints.end();
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::findDatapoint(const DateTime& moment) const {
    return this->findDatapoint(moment, this->_datapoints.begin());
}

size_t TemperatureHistory::getSize() const {
    return this->_datapoints.size();
}

void TemperatureHistory::clear() {
    this->_datapoints.clear();
}

void TemperatureHistory::addDatapoint(const TemperatureDatapoint &datapoint) {
    for (auto it = this->_datapoints.begin(); it != this->_datapoints.end(); it++) {
        if (it->getMoment() > datapoint.getMoment()) {
            this->_datapoints.insert(it, datapoint);
            return;
        } else if (it->getMoment() == datapoint.getMoment()) {
            *it = datapoint;
            return;
        }
    }
    this->_datapoints.push_back(datapoint);
}

TemperatureHistory& TemperatureHistory::operator+=(const TemperatureDatapoint &datapoint) {
    addDatapoint(datapoint);
    return *this;
}

void TemperatureHistory::readFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur lors de l'ouverture du fichier.");
    }
    TemperatureDatapoint datapoint;
    while (!file.eof()) {
        file >> datapoint;
        this->addDatapoint(datapoint);
    }
    file.close();
}

void TemperatureHistory::deleteDatapoint(const DateTime &moment) {
    auto it = this->findDatapoint(moment);
    if (it != this->_datapoints.end()) {
        this->_datapoints.erase(it);
    }
}

std::list<TemperatureDatapoint>::iterator TemperatureHistory::begin() {
    return this->_datapoints.begin();
}

std::list<TemperatureDatapoint>::iterator TemperatureHistory::end() {
    return this->_datapoints.end();
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::begin() const {
    return this->_datapoints.begin();
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::end() const {
    return this->_datapoints.end();
}
