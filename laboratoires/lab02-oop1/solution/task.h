#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string _description;
    bool _fait;

public:

    Task();
    Task(const std::string &, bool);

    void marquerFait();
    void demarquerFait();
    std::string obtenirChaine(int);
};

#endif