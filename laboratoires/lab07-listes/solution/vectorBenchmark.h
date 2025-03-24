#ifndef __VECTOR_BENCHMARK_H
#define __VECTOR_BENCHMARK_H

#include <vector>

#include "benchmark.h"

class VectorBenchmark: public Benchmark {
private:
    std::vector<double> _benchmarked;
public:
    VectorBenchmark(const std::string &pathData, const std::string &extraData) 
        : Benchmark("Vector benchmark", pathData, extraData) { }
    void execPush();
    void execInsert();
    void execParse();

    size_t getBenchmarkedSize() const;
};

#endif
