#include "benchmark.h"

#include <iomanip>


void Benchmark::load() {
    this->_file.open(this->_dataPath);
    std::string mainContent { std::istreambuf_iterator<char>(this->_file), std::istreambuf_iterator<char>() };
    size_t pos = 0, current = 0, count = 0;

    while ((current = mainContent.find("\n", pos)) != std::string::npos) {
        this->_data.push_back(atoi(mainContent.substr(pos, current - pos - 1).c_str()));
        pos = current + 1;
        count++;
    }

    this->_file.close();

    this->_file.open(this->_extraPath);
    std::string extraContent { std::istreambuf_iterator<char>(this->_file), std::istreambuf_iterator<char>() };
    pos = 0; current = 0; count = 0;

    while ((current = mainContent.find("\n", pos)) != std::string::npos && count < 100000) {
        this->_extra.push_back(atoi(mainContent.substr(pos, current - pos - 1).c_str()));
        pos = current + 1;
        count++;
    }

    this->_file.close();
}

void Benchmark::startTimer() {
    this->_start = std::chrono::high_resolution_clock::now();
}

void Benchmark::endTimer() {
    this->_end = std::chrono::high_resolution_clock::now();
    this->_durations.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(this->_end - this->_start).count());
}

Benchmark::Benchmark(const std::string &label, const std::string &dataPath, const std::string &extraPath) {
    this->_label = label;
    this->_dataPath = dataPath;
    this->_extraPath = extraPath;

    this->sum = 0.0;

    this->load();
}

void Benchmark::bench() {
    this->startTimer();
    this->execPush();
    this->endTimer();

    this->startTimer();
    this->execInsert();
    this->endTimer();

    this->startTimer();
    this->execParse();
    this->endTimer();
}

std::ostream &operator<<(std::ostream &os, const Benchmark &bench) {
    os << std::setw(26) << std::left << bench._label;
    for (size_t i = 0; i < bench._durations.size(); i++) {
        os << std::setw(10) << std::right << bench._durations[i] << " ms";
    }
    os << std::setw(20) << std::right << std::fixed << std::setprecision(3) << bench.sum;
    os << std::setw(12) << std::right << bench._data.size();
    os << std::setw(12) << std::right << bench._extra.size();
    os << std::setw(12) << std::right << bench.getBenchmarkedSize();
    return os;
}
