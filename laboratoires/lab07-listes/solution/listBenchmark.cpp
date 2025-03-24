#include "listBenchmark.h"

void ListBenchmark::execPush() {
    for (double value: this->_data) {
        this->_benchmarked.push_back(value);
    }    
}

void ListBenchmark::execInsert() {
    std::list<double>::iterator it = this->_benchmarked.begin();
    std::advance(it, 500000);
    for (double value: this->_extra) {
        this->_benchmarked.insert(it, value);
    }
}

void ListBenchmark::execParse() {
    this->sum = 0.0;

    for (double value: this->_benchmarked) {
        this->sum += value;
    }
}

size_t ListBenchmark::getBenchmarkedSize() const {
    return this->_benchmarked.size();
}