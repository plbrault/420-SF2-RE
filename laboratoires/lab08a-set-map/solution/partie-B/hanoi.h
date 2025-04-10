#ifndef __HANOI_H
#define __HANOI_H

#include <array>
#include <sstream>

#include "tower.h"

class Hanoi {
private:
    std::array<Tower, 3> _towers;

public:
    void newGame();

    friend std::ostream &operator<<(std::ostream &os, const Hanoi &hanoi);
};

#endif
