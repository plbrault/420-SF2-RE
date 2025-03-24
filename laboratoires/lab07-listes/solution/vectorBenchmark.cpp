#include "vectorBenchmark.h"

void VectorBenchmark::exec() const {
    for (double value: this->_data) {
        this->_benchmarked.push_back(value);
    }
}