#ifndef __BENCHMARK_H
#define __BENCHMARK_H

#include <string>
#include <fstream>
#include <vector>
#include <chrono>

class Benchmark {
private:
    std::string _label;
    std::string _dataPath;
    std::string _extraPath;

    std::ifstream _file;

    std::chrono::_V2::system_clock::time_point _start;
    std::chrono::_V2::system_clock::time_point _end;


    void load();
protected:
    std::vector<double> _data;
    std::vector<double> _extra;
    std::vector<int64_t> _durations;

    void startTimer();
    void endTimer();
    std::vector<double> pointParsed;
public:
    Benchmark(const std::string &label, const std::string &dataPath, const std::string &extraPath);

    void bench();
    virtual void execPush() = 0;
    virtual void execInsert() = 0;
    virtual void execParse() = 0;

    const std::vector<double> &getPointParsed() const;
    virtual size_t getBenchmarkedSize() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Benchmark &bench);

    virtual const void *getBenchmarked() const = 0;
};

#endif
