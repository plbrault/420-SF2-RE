#include "athlete.h"

Athlete::Athlete() : Athlete("", "") { }

Athlete::Athlete(const std::string &firstname, const std::string &lastname)
    : _firstname(firstname), _lastname(lastname), _matchPlayed(0) { }

std::string Athlete::getFirstname() const {
    return this->_firstname;
}

std::string Athlete::getLastname() const {
    return this->_lastname;
}

std::string Athlete::getFullname() const {
    return this->_firstname + " " + this->_lastname;
}

uint16_t Athlete::getMatchPlayed() const {
    return this->_matchPlayed;
}

void Athlete::setFirstname(const std::string &firstname) {
    this->_firstname = firstname;
}

void Athlete::setLastname(const std::string &lastname) {
    this->_lastname = lastname;
}

void Athlete::plays() {
    this->_matchPlayed++;
}