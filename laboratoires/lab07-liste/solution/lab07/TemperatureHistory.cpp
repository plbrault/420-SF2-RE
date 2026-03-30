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
    if (this->_size == this->_capacity) {
        increaseCapacity();
    }
    this->_datapoints[this->_size] = datapoint;
    this->_size++;
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
    this->clear();
    TemperatureDatapoint datapoint;
    while (!file.eof()) {
        file >> datapoint;
        this->addDatapoint(datapoint);
    }
    file.close();
}

void TemperatureHistory::deleteDatapoint(const DateTime &moment) {
    deleteDatapoint(findDatapoint(moment));
}
