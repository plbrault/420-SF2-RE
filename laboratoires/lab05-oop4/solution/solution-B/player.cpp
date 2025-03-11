#include "player.h"

#include <iomanip>

Player::Player() : Player("", "", "") { }

Player::Player(const std::string &position, const std::string &firstName, const std::string &lastName): Athlete(firstName, lastName) {
    this->_position = position;

    this->_goals = 0;
    this->_passes = 0;
    this->_shots = 0;
    this->_breakaways = 0;
}

void Player::plays(uint16_t goals, uint16_t passes, uint16_t shots, uint16_t breakaways) {
    Athlete::plays();
    this->_goals += goals;
    this->_passes += passes;
    this->_shots += shots;
    this->_breakaways += breakaways;
}

uint16_t Player::getGoals() const {
    return this->_goals;
}

uint16_t Player::getPasses() const {
    return this->_passes;
}

uint16_t Player::getPoints() const {
    return this->_goals + this->_passes;
}

uint16_t Player::getShots() const {
    return this->_shots;
}

double Player::getAccuracy() const {
    return (double)this->_goals / (double)this->_shots;
}

uint16_t Player::getBreakaways() const {
    return this->_breakaways;
}

uint8_t Player::scores() const {
    uint8_t result = this->getGoals() * 2 + this->getPasses() + this->_breakaways + this->getShots() / 10.0;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << std::setw(24) << player.getFullName()
        << std::setw(8) << std::right << player.getMatchPlayed()
        << std::setw(8) << std::right << player.getGoals()
        << std::setw(8) << std::right << player.getPasses()
        << std::setw(8) << std::right << player.getPoints()
        << std::setw(8) << std::right << player.getShots()
        << std::setw(8) << std::right << std::fixed << std::setprecision(3) << player.getAccuracy()
        << std::setw(8) << std::right << player.getBreakaways()
        << std::setw(8) << std::right << unsigned(player.scores());
    return os;
}