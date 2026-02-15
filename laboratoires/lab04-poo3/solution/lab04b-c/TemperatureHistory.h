//
// Created by plbrault on 2026-02-11.
//

#ifndef SOLUTION_TEMPERATUREHISTORY_H
#define SOLUTION_TEMPERATUREHISTORY_H

#include "TemperatureDatapoint.h"

class TemperatureHistory {
private:
    TemperatureDatapoint* _datapoints;
    size_t _size;
    size_t _capacity;

    void increaseCapacity();
public:
    TemperatureHistory();
    TemperatureHistory(const TemperatureHistory& other);
    ~TemperatureHistory();
    TemperatureHistory& operator=(const TemperatureHistory& other);

    size_t getSize() const;

    void clear();
    void addDatapoint(const TemperatureDatapoint& datapoint);
    void deleteDatapoint(size_t index);
    void deleteDatapoint(const DateTime& datetime);
    size_t findDatapoint(const DateTime& datetime) const;

    void readFromFile(const std::string& filename);

    TemperatureHistory& operator+=(const TemperatureDatapoint& datapoint);

    const TemperatureDatapoint& operator[](size_t index) const;
    TemperatureDatapoint& operator[](size_t index);

    const TemperatureDatapoint& operator[](const DateTime& datetime) const;
    TemperatureDatapoint& operator[](const DateTime& datetime);
};


#endif //SOLUTION_TEMPERATUREHISTORY_H