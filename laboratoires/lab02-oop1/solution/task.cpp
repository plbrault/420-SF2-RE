#include "task.h"

#include <sstream>

Task::Task() : Task::Task("", false) { }

Task::Task(const std::string &description, bool fait) {
    this->description = description;
    this->fait = fait;
}

void Task::marquerFait() {
    this->fait = true;
}

void Task::demarquerFait() {
    this->fait = false;
}

std::string Task::obtenirChaine(int index) {
    std::ostringstream flux;

    flux << index << " [" << (this->fait ? 'X' : ' ') << "] " << this->description;

    return flux.str();
}
