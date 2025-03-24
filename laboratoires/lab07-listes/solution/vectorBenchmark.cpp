#include "vectorBenchmark.h"

void VectorBenchmark::execPush() {
    for (double value: this->_data) {
        this->_benchmarked.push_back(value);
    }
}

void VectorBenchmark::execInsert() {
    for (double value: this->_extra) {
        this->_benchmarked.insert(this->_benchmarked.begin() + 500000, value);
    }
}

void VectorBenchmark::execParse() {
    this->sum = 0.0;

    for (double value: this->_benchmarked) {
        this->sum += value;
    }
} 
size_t VectorBenchmark::getBenchmarkedSize() const {
    return this->_benchmarked.size();
}