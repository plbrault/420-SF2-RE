#ifndef __ATHLETE_H
#define __ATHLETE_H

#include <cstdint>
#include <string>


class Athlete {
private:
    
    std::string _firstName;
    std::string _lastName;

    uint16_t _matchPlayed;
public:
    Athlete();
    Athlete(const std::string &, const std::string &);

    std::string getFullName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    uint16_t getMatchPlayed() const;

    void setFirstName(const std::string &);
    void setLastName(const std::string &);

    virtual void plays();
    virtual uint8_t scores() const = 0;
};

#endif
