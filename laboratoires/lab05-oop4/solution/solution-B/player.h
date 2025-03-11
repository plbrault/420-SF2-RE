#ifndef __PLAYER_H
#define __PLAYER_H

#include "athlete.h"
#include <sstream>

class Player : public Athlete {
private:
    std::string _position;

    uint16_t _goals;
    uint16_t _passes;
    uint16_t _shots;
    uint16_t _breakaways;
public:
    Player();
    Player(const std::string &, const std::string &, const std::string &);

    void plays(uint16_t, uint16_t, uint16_t, uint16_t);

    uint16_t getGoals() const;
    uint16_t getPasses() const;
    uint16_t getPoints() const;
    uint16_t getShots() const;
    double getAccuracy() const;
    uint16_t getBreakaways() const;

    uint8_t scores() const;

    friend std::ostream &operator<<(std::ostream &, const Player &);

};

#endif
