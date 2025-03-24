#include "benchmark.h"

void Benchmark::load() {
    this->_file.open(this->_dataPath);
    std::string mainContent { std::istreambuf_iterator<char>(this->_file), std::istreambuf_iterator<char>() };
    size_t pos = 0, current = 0, count = 0;

    while ((current = mainContent.find("\n", pos)) != std::string::npos && count < 1000000) {
        this->_data.push_back(atoi(mainContent.substr(pos, current - pos - 1).c_str()));
        pos = current + 1;
        count++;
    }

    this->_file.close();

    this->_file.open(this->_extraPath);
    std::string extraContent { std::istreambuf_iterator<char>(this->_file), std::istreambuf_iterator<char>() };
    size_t pos = 0, current = 0, count = 0;

    while ((current = mainContent.find("\n", pos)) != std::string::npos && count < 100000) {
        this->_extra.push_back(atoi(mainContent.substr(pos, current - pos - 1).c_str()));
        pos = current + 1;
        count++;
    }

    this->_file.close();
}

Benchmark::Benchmark(const std::string &label, const std::string &dataPath, const std::string &extraPath) {
    this->_label = label;
    this->_dataPath = dataPath;
    this->_extraPath = extraPath;

    this->load();
}

void Benchmark::bench() {
    this->exec();
}