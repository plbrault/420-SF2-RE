#ifndef __GOALTENDER_H
#define __GOALTENDER_H

#include <cstdint>
#include <sstream>

#include "athlete.h"

class Goaltender : public Athlete {
private:
    uint16_t _wins;
    uint16_t _losses;
    uint16_t _otLosses;

    uint16_t _goalAgainst;
    uint16_t _shotAgainst;
public:
    Goaltender();
    Goaltender(const std::string &, const std::string &);

    void plays(bool, bool, uint16_t, uint16_t);

    uint16_t getWins() const;
    uint16_t getLosses() const;
    uint16_t getOTLosses() const;
    uint16_t getAllLosses() const;
    double getWinLossRatio() const;
    uint16_t getGoalAgainst() const;
    uint16_t getShotAgainst() const;
    double getGoalShotRatio() const;

    uint8_t scores() const;

    friend std::ostream &operator<<(std::ostream &, const Goaltender &);
};

#endif