#ifndef __TOWER_H
#define __TOWER_H

#include <stack>
#include <string>
#include <sstream>

#include "disk.h"

class Tower {
private:
    std::stack<Disk> _disks;
    int _moveCount;

public:
    Tower();

    bool push(const Disk &disk);
    bool transfert(Tower &tower);

    std::string lineToString(std::size_t idx) const;
    friend std::ostream &operator<<(std::ostream &os, Tower tower);
};

#endif
