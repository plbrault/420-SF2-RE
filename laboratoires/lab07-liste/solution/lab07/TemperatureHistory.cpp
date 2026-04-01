#include <fstream>
#include "TemperatureHistory.h"

std::list<TemperatureDatapoint>::iterator TemperatureHistory::findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::iterator start) {
    for (auto it = start; it != this->_datapoints.end(); it++) {
        if (it->getMoment() == moment) {
            return it;
        } else if (it->getMoment() > moment) {
            return this->_datapoints.end();
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

std::list<TemperatureDatapoint>::iterator TemperatureHistory::addDatapoint(const TemperatureDatapoint &datapoint, std::list<TemperatureDatapoint>::iterator start) {
    for (auto it = start; it != this->_datapoints.end(); it++) {
        if (it->getMoment() > datapoint.getMoment()) {
            return _datapoints.insert(it, datapoint);
        }
        if (it->getMoment() == datapoint.getMoment()) {
            *it = datapoint;
            return it;
        }
    }
    this->_datapoints.push_back(datapoint);
    return --this->_datapoints.end();
}

std::list<TemperatureDatapoint>::iterator TemperatureHistory::addDatapoint(const TemperatureDatapoint &datapoint) {
    return this->addDatapoint(datapoint, this->_datapoints.begin());
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
    auto lastInsert = this->_datapoints.begin();
    while (!file.eof()) {
        file >> datapoint;
        if (datapoint.getMoment() >= lastInsert->getMoment())
        {
            this->addDatapoint(datapoint, lastInsert);
        } else {
            this->addDatapoint(datapoint);
        }
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

void TemperatureHistory::deleteRange(const DateTime& from, const DateTime& to)
{
    auto fromIt = this->findDatapoint(from);
    auto toIt = this->findDatapoint(to, fromIt);
    if (fromIt != this->_datapoints.end() && toIt != this->_datapoints.end()) {
        this->_datapoints.erase(fromIt, toIt);
    }
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::begin() const {
    return this->_datapoints.begin();
}

std::list<TemperatureDatapoint>::const_iterator TemperatureHistory::end() const {
    return this->_datapoints.end();
}
