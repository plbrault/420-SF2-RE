#ifndef __HANOI_H
#define __HANOI_H

#include <array>
#include <cstdint>
#include <sstream>

#include "tower.h"

class Hanoi {
private:
    std::array<Tower, 3> _towers;

public:
    void newGame();

    Tower &operator[](std::size_t idx);

    friend std::ostream &operator<<(std::ostream &os, const Hanoi &hanoi);
};

#endif