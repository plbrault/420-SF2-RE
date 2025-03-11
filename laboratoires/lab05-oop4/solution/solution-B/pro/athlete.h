#ifndef __ATHLETE_H
#define __ATHLETE_H

#include <cstdint>
#include <string>


class Athlete {
private:
    
    std::string _firstname;
    std::string _lastname;

    uint16_t _matchPlayed;
public:
    Athlete();
    Athlete(const std::string &, const std::string &);
    virtual ~Athlete() = default;

    std::string getFullname() const;
    std::string getFirstname() const;
    std::string getLastname() const;
    uint16_t getMatchPlayed() const;

    void setFirstname(const std::string &);
    void setLastname(const std::string &);

    virtual void plays();
    virtual uint8_t scores() const = 0;
};

#endif
