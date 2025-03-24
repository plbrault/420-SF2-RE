#ifndef __LIST_BENCHMARK_H
#define __LIST_BENCHMARK_H

#include <list>

#include "benchmark.h"

class ListBenchmark: public Benchmark {
private:
    std::list<double> _benchmarked;

    std::list<double>::iterator it;
public:
    ListBenchmark(const std::string &pathData, const std::string &extraData) 
        : Benchmark("List benchmark", pathData, extraData) { }
    void execPush();
    void execInsert();
    void execParse();

    size_t getBenchmarkedSize() const;
};

#endif
