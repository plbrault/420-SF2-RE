#include "tower.h"

Tower::Tower() { 
    this->_moveCount = 0;
}

bool Tower::push(const Disk &disk) {
    if (this->_disks.size() == 0) {
        this->_disks.push(disk);
        return true;
    }

    if (this->_disks.top().getLength() > disk.getLength()) {
        this->_disks.push(disk);
        return true;
    }

    return false;
}

bool Tower::transfert(Tower &tower) {
    if (this->_disks.size() == 0) {
        return false;
    }

    if (this->_disks.top().getLength() > tower._disks.top().getLength()) {
        return false;
    }

    this->push(tower._disks.top());
    tower._disks.pop();

    return false;
}

std::string Tower::lineToString(std::size_t idx) const {
    std::stringstream stream;

    if (idx == 0) {
        stream << "\n";
    } else if (idx < this->_disks.size()) {

    }

    return stream.str();
}

std::ostream &operator<<(std::ostream &os, Tower tower) {
    for (size_t i = tower._disks.size(); i < 10; i++) {
        for (std::size_t i = 0; i < 13; i++) {
            os << ' ';
        }

        os << "░▓░";

        for (std::size_t i = 0; i < 13; i++) {
            os << ' ';
        }
        os << "\n";
    }


    while (tower._disks.size() > 0) {
        os << tower._disks.top();
        os << '\n';
        tower._disks.pop();
    }

    os << "▛▚▚▚▚▚▚▚▚▚▚▚▚░▓░▞▞▞▞▞▞▞▞▞▞▞▞▜";
    return os;
}