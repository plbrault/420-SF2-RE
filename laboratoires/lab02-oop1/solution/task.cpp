#include "task.h"

Task::Task(const std::string &description, bool fait) {
    this->description = description;
    this->fait = fait;
}
