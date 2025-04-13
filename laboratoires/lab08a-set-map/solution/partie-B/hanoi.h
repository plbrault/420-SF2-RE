#ifndef __HANOI_H
#define __HANOI_H

#include <queue>
#include <cstdint>
#include <sstream>

#include "tower.h"

class Hanoi {
private:
    std::queue<Tower> _towers;
    uint16_t _counter;

public:
    void newGame();

    uint16_t getCounter() const;

    Tower operator[](std::size_t idx);

    friend std::ostream &operator<<(std::ostream &os, Hanoi hanoi);
};

#endif
