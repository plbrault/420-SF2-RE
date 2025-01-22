#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    std::string description;
    bool fait;

    Task(const std::string &, bool);
};

#endif