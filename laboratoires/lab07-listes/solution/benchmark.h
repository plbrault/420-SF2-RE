#ifndef __BENCHMARK_H
#define __BENCHMARK_H

#include <string>
#include <fstream>
#include <vector>

class Benchmark {
private:
    std::string _label;
    std::string _dataPath;
    std::string _extraPath;

    std::ifstream _file;

    void load();
protected:
    std::vector<double> _data;
    std::vector<double> _extra;
public:
    Benchmark(const std::string &label, const std::string &dataPath, const std::string &extraPath);

    void bench();
    virtual void exec() const = 0;
};

#endif
