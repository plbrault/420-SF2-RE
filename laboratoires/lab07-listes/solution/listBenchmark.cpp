#include "listBenchmark.h"

#include <cmath>

void ListBenchmark::execPush() {
    for (double value: this->_data) {
        this->_benchmarked.push_back(value);
    }    
}

void ListBenchmark::execInsert() {
    auto insertPos = this->_benchmarked.begin();
    std::advance(insertPos, 500000);
    for (auto itExtra = this->_extra.rbegin(); itExtra != this->_extra.rend(); ++itExtra) {
        insertPos = this->_benchmarked.insert(insertPos, *itExtra);
    }
    
}

void ListBenchmark::execParse() {
    this->pointParsed.clear();
    if (this->_benchmarked.size() < 2)
        return;

    auto prev = this->_benchmarked.begin();
    auto curr = std::next(prev);
    size_t index = 1;

    while (curr != this->_benchmarked.end()) {
        double first = *prev;
        double second = *curr;

        if ((abs(second - first) / first) >= 0.12) {
            this->pointParsed.push_back(index);
        }

        ++prev;
        ++curr;
        ++index;
    }
}

size_t ListBenchmark::getBenchmarkedSize() const {
    return this->_benchmarked.size();
}

const void *ListBenchmark::getBenchmarked() const
{
    return &(this->_benchmarked);
}
