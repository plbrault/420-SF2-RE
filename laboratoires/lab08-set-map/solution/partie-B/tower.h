#ifndef __TOWER_H
#define __TOWER_H

#include <stack>
#include <string>
#include <sstream>

#include "disk.h"

class Tower {
private:
    std::stack<Disk> _disks;

public:
    bool push(const Disk &disk);
    bool transfert(Tower &tower);

    friend std::ostream &operator<<(std::ostream &os, Tower tower);
};

#endif
