#include <fstream>
#include "TemperatureHistory.h"

TemperatureHistory::TemperatureHistory() {
    this->_size = 0;
    this->_capacity = 0;
    this->_datapoints = nullptr;
}

TemperatureHistory::TemperatureHistory(const TemperatureHistory &other) {
    this->_size = other._size;
    this->_capacity = other._capacity;
    this->_datapoints = new TemperatureDatapoint[this->_capacity];
    for (size_t i = 0; i < this->_size; i++) {
        this->_datapoints[i] = other._datapoints[i];
    }
}

TemperatureHistory::~TemperatureHistory() {
    clear();
}

TemperatureHistory &TemperatureHistory::operator=(const TemperatureHistory &other) {
    if (this != &other) {
        clear();
        this->_size = other._size;
        this->_capacity = other._capacity;
        this->_datapoints = new TemperatureDatapoint[this->_capacity];
        for (size_t i = 0; i < this->_size; i++) {
            this->_datapoints[i] = other._datapoints[i];
        }
    }
    return *this;
}

void TemperatureHistory::increaseCapacity() {
    size_t newCapacity = this->_capacity == 0 ? 2 : this->_capacity * 2;
    TemperatureDatapoint* newDatapoints = new TemperatureDatapoint[newCapacity];
    for (size_t i = 0; i < this->_size; i++) {
        newDatapoints[i] = this->_datapoints[i];
    }
    delete[] this->_datapoints;
    this->_datapoints = newDatapoints;
    this->_capacity = newCapacity;
}

size_t TemperatureHistory::findDatapoint(const DateTime &datetime) const {
    for (size_t i = 0; i < this->_size; i++) {
        if (this->_datapoints[i].getDateTime() == datetime) {
            return i;
        }
    }
    return this->_size; // Not found
}

size_t TemperatureHistory::getSize() const {
    return this->_size;
}

void TemperatureHistory::clear() {
    delete[] this->_datapoints;
    this->_datapoints = nullptr;
    this->_size = 0;
    this->_capacity = 0;
}

void TemperatureHistory::addDatapoint(const TemperatureDatapoint &datapoint) {
    if (this->_size == this->_capacity) {
        increaseCapacity();
    }
    this->_datapoints[this->_size] = datapoint;
    this->_size++;
}

void TemperatureHistory::deleteDatapoint(size_t index) {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < this->_size - 1; i++) {
        this->_datapoints[i] = this->_datapoints[i + 1];
    }
    this->_size--;
}

void TemperatureHistory::deleteDatapoint(const DateTime &datetime) {
    size_t index = findDatapoint(datetime);
    if (index < this->_size) {
        deleteDatapoint(index);
    }
}

TemperatureHistory& TemperatureHistory::operator+=(const TemperatureDatapoint &datapoint) {
    addDatapoint(datapoint);
    return *this;
}

TemperatureDatapoint& TemperatureHistory::operator[](size_t index) {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of range");
    }
    return this->_datapoints[index];
}

const TemperatureDatapoint& TemperatureHistory::operator[](size_t index) const {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of range");
    }
    return this->_datapoints[index];
}

TemperatureDatapoint& TemperatureHistory::operator[](const DateTime &datetime) {
    size_t index = findDatapoint(datetime);
    if (index >= this->_size) {
        throw std::out_of_range("DateTime not found");
    }
    return this->_datapoints[index];
}

const TemperatureDatapoint& TemperatureHistory::operator[](const DateTime &datetime) const {
    size_t index = findDatapoint(datetime);
    if (index >= this->_size) {
        throw std::out_of_range("DateTime not found");
    }
    return this->_datapoints[index];
}

void TemperatureHistory::readFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    TemperatureDatapoint datapoint;
    while (file >> datapoint) {
        this->addDatapoint(datapoint);
    }
    file.close();
}
