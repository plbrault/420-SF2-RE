#include <iostream>
#include <iomanip>

#include "benchmark.h"
#include "vectorBenchmark.h"
#include "listBenchmark.h"

int main(int, char**) {
    std::vector<Benchmark *> benches;

    benches.push_back(new VectorBenchmark("data.csv", "data_to_add.csv"));
    benches.push_back(new ListBenchmark("data.csv", "data_to_add.csv"));

    VectorBenchmark("data.csv", "data_to_add.csv");
    ListBenchmark("data.csv", "data_to_add.csv");

    std::cout << std::setw(26) << std::left << "Nom";
    std::cout << std::setw(10) << std::right << "PB";
    std::cout << std::setw(10) << std::right << "Ins";
    std::cout << std::setw(10) << std::right << "Pa";
    std::cout << std::setw(20) << std::right << "Somme";
    std::cout << std::setw(12) << std::right << "QD";
    std::cout << std::setw(12) << std::right << "QE";
    std::cout << std::setw(12) << std::right << "QB" << std::endl;

    for (Benchmark *b: benches) {
        b->bench();
        std::cout << *b << std::endl;
    }

    return 0;
}
