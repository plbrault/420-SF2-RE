#include "persistance.h"

#include <stdexcept>

Persistance::Persistance(const std::string &path) {
    this->_path = path;
    this->_file = new std::ofstream(this->_path);
    if (!this->_file->good()) {
        throw std::invalid_argument("Le chemin n'existe pas.");
    }
}

Persistance::~Persistance() {
    this->_file->close();
    delete this->_file;
}
