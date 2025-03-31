#include <iostream>
#include <iomanip>

#include "benchmark.h"
#include "vectorBenchmark.h"
#include "listBenchmark.h"

int main(int, char**) {
    std::vector<Benchmark *> benches;

    benches.push_back(new VectorBenchmark("data.csv", "data_to_add.csv"));
    benches.push_back(new ListBenchmark("data.csv", "data_to_add.csv"));

    std::cout << std::setw(26) << std::left << "Nom";
    std::cout << std::setw(10) << std::right << "PB";
    std::cout << std::setw(10) << std::right << "Ins";
    std::cout << std::setw(10) << std::right << "Pa";
    std::cout << std::setw(20) << std::right << "Pts";
    std::cout << std::setw(12) << std::right << "QD";
    std::cout << std::setw(12) << std::right << "QE";
    std::cout << std::setw(12) << std::right << "QB" << std::endl;

    for (Benchmark *b: benches) {
        b->bench();
        std::cout << *b << std::endl;
    }

    std::cout << "Validation des données" << std::endl;
    std::vector<double> *dataVector = (std::vector<double> *)benches[0]->getBenchmarked();
    std::list<double> *dataList = (std::list<double> *)benches[1]->getBenchmarked();

    size_t count = 0;
    auto itL = dataList->begin();
    for (size_t i = 0; i < dataVector->size(); i++) {
        if ((*dataVector)[i] != *itL) {
            std::cout << "Mismatch at index " << i << ": " << (*dataVector)[i] << " vs " << *itL << std::endl;
        }
        ++itL;
    }
}
