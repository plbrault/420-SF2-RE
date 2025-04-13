#include "hanoi.h"

#include <iomanip>

void Hanoi::newGame() {
    Tower full;

    for (size_t i = 8; i > 0; i--) {
        full.push(Disk(i));
    }

    this->_towers.push(full);

    Tower empty;

    this->_towers.push(empty);
    this->_towers.push(empty);
}

uint16_t Hanoi::getCounter() const {
    return this->_counter;
}

Tower &Hanoi::operator[](std::size_t idx) {
    if (idx < 3) {
        Hanoi temp = *this;
        Tower result;
        std::size_t count = 0;
        while (count < idx) {
            
        }


        return this->_towers[idx];
    }

    throw std::invalid_argument("Indice en dehors de la plage valide");
}

std::ostream &operator<<(std::ostream &os, const Hanoi &hanoi) {
    std::stringstream stream[3];

    for (std::size_t i = 0; i < hanoi._towers.size(); i++) {
        stream[i] << hanoi._towers[i];
    }
    os << "\n";

    for (std::size_t i = 0; i < hanoi._towers.size(); i++) {
        os << "              ░▓░              ";
    }

    os << "\n";

    for (std::size_t j = 0; j < 11; j++) {
        for (std::size_t i = 0; i < hanoi._towers.size(); i++) {
            std::string line;
            std::getline(stream[i], line);
            os << ' ' << line << ' ';
        }

        os << "\n";
    }

    for (std::size_t i = 0; i < hanoi._towers.size(); i++) {
        os << "              [" << (i + 1) << "]              ";
    }

    os << "\n";

    return os;
}
