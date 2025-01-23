#include "task.h"

#include <sstream>

Task::Task() : Task::Task("", false) { }

Task::Task(const std::string &description, bool fait) {
    this->_description = description;
    this->_fait = fait;
}

void Task::marquerFait() {
    this->_fait = true;
}

void Task::demarquerFait() {
    this->_fait = false;
}

std::string Task::obtenirChaine(int index) {
    std::ostringstream flux;

    flux << index << " [" << (this->_fait ? 'X' : ' ') << "] " << this->description;

    return flux.str();
}
