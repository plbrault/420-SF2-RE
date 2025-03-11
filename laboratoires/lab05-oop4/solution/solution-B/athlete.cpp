#include "athlete.h"

Athlete::Athlete() : Athlete("", "") { }

Athlete::Athlete(const std::string &firstName, const std::string &lastName)
    : _firstName(firstName), _lastName(lastName), _matchPlayed(0) { }

std::string Athlete::getFirstName() const {
    return this->_firstName;
}

std::string Athlete::getLastName() const {
    return this->_lastName;
}

std::string Athlete::getFullName() const {
    return this->_firstName + " " + this->_lastName;
}

uint16_t Athlete::getMatchPlayed() const {
    return this->_matchPlayed;
}

void Athlete::setFirstName(const std::string &firstName) {
    this->_firstName = firstName;
}

void Athlete::setLastName(const std::string &lastName) {
    this->_lastName = lastName;
}

void Athlete::plays() {
    this->_matchPlayed++;
}