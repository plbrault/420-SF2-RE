#ifndef __VECTOR_BENCHMARK_H
#define __VECTOR_BENCHMARK_H

#include <vector>

#include "benchmark.h"

class VectorBenchmark: public Benchmark {
private:
    std::vector<double> _benchmarked;
public:
    void exec() const;
};

#endif

