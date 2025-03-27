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
    for (size_t i = 1; i < this->_benchmarked.size(); i++) {
        if ((abs(this->_benchmarked[i] - this->_benchmarked[i - 1]) / this->_benchmarked[i - 1]) >= 0.12) {
            this->pointParsed.push_back(i);
        }
    }
}

size_t VectorBenchmark::getBenchmarkedSize() const {
    return this->_benchmarked.size();
}

const void *VectorBenchmark::getBenchmarked() const
{
    return &(this->_benchmarked);
}
