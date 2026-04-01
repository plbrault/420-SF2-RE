#ifndef SOLUTION_TEMPERATUREHISTORY_H
#define SOLUTION_TEMPERATUREHISTORY_H

#include <list>
#include "TemperatureDatapoint.h"

class TemperatureHistory {
private:
    std::list<TemperatureDatapoint> _datapoints;
public:
    size_t getSize() const;

    void clear();
    std::list<TemperatureDatapoint>::iterator addDatapoint(const TemperatureDatapoint& datapoint, std::list<TemperatureDatapoint>::iterator start);
    std::list<TemperatureDatapoint>::iterator addDatapoint(const TemperatureDatapoint& datapoint);
    void deleteDatapoint(const DateTime& moment);
    void deleteRange(const DateTime& from, const DateTime& to);
    std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::iterator start);
    std::list<TemperatureDatapoint>::iterator findDatapoint(const DateTime& moment);
    std::list<TemperatureDatapoint>::const_iterator findDatapoint(const DateTime& moment, std::list<TemperatureDatapoint>::const_iterator start) const;
    std::list<TemperatureDatapoint>::const_iterator findDatapoint(const DateTime& moment) const;
    void readFromFile(const std::string& filename);

    std::list<TemperatureDatapoint>::iterator begin();
    std::list<TemperatureDatapoint>::iterator end();
    std::list<TemperatureDatapoint>::const_iterator begin() const;
    std::list<TemperatureDatapoint>::const_iterator end() const;

    TemperatureHistory& operator+=(const TemperatureDatapoint& datapoint);
};


#endif //SOLUTION_TEMPERATUREHISTORY_H