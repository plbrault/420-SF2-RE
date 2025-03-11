#include "goaltender.h"

#include <iomanip>

Goaltender::Goaltender() : Goaltender("", "") { }

Goaltender::Goaltender(const std::string &firstname, const std::string &lastname) : Athlete(firstname, lastname) {
    this->_wins = 0;
    this->_losses = 0;
    this->_otLosses = 0;

    this->_goalAgainst = 0;
    this->_shotAgainst = 0;
}

void Goaltender::plays(bool hasWon, bool wasOT, uint16_t goalAgainst, uint16_t shotAgainst) {
    Athlete::plays();
    if (hasWon) {
        this->_wins++;
    } else if(wasOT) {
        this->_otLosses++;
    } else {
        this->_losses++;
    }
    this->_goalAgainst += goalAgainst;
    this->_shotAgainst += shotAgainst;
}

uint16_t Goaltender::getWins() const {
    return this->_wins;
}

uint16_t Goaltender::getLosses() const {
    return this->_losses;
}

uint16_t Goaltender::getOTLosses() const {
    return this->_otLosses;
}

uint16_t Goaltender::getAllLosses() const {
    return this->getLosses() + this->getOTLosses();
}

double Goaltender::getWinLossRatio() const {
    return ((double)this->getWins()) / ((double)this->getMatchPlayed());
}

uint16_t Goaltender::getGoalAgainst() const {
    return this->_goalAgainst;
}

uint16_t Goaltender::getShotAgainst() const {
    return this->_shotAgainst;
}

double Goaltender::getGoalShotRatio() const {
    return (double)(this->getShotAgainst() - this->getGoalAgainst()) / (double)this->getShotAgainst();
}

uint8_t Goaltender::scores() const {
    uint8_t scores = (this->getWins() - this->getLosses()) * 5 + this->getOTLosses() + (this->getShotAgainst() - this->getGoalAgainst()) / 10.0;
    return scores;
}

std::ostream &operator<<(std::ostream &os, const Goaltender &goaltender) {
    os << std::setw(24) << goaltender.getFullname()
        << std::setw(8) << std::right << goaltender.getMatchPlayed()
        << std::setw(8) << std::right << goaltender.getWins()
        << std::setw(8) << std::right << goaltender.getLosses()
        << std::setw(8) << std::right << goaltender.getOTLosses()
        << std::setw(8) << std::right << std::fixed << std::setprecision(3) << goaltender.getWinLossRatio()
        << std::setw(8) << std::right << std::setprecision(0) << goaltender.getGoalAgainst()
        << std::setw(8) << std::right << goaltender.getShotAgainst()
        << std::setw(8) << std::right << std::fixed << std::setprecision(3) << goaltender.getGoalShotRatio()
        << std::setw(8) << std::right << unsigned(goaltender.scores());
    return os;
}