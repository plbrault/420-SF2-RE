#include "tower.h"

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

    if (tower._disks.size() == 0) {
        tower.push(this->_disks.top());
        this->_disks.pop();
        return true;
    } else if (tower._disks.top().getLength() > this->_disks.top().getLength()) {
        tower.push(this->_disks.top());
        this->_disks.pop();
        return true;
    }

    return false;
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