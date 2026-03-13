//
// Created by plbrault on 2026-03-12.
//

#ifndef SOLUTION_ISOFORMATENTITY_H
#define SOLUTION_ISOFORMATENTITY_H

#include <string>

class ISOFormatEntity
{
public:
    virtual std::string toISOString() const = 0;
};


#endif //SOLUTION_ISOFORMATENTITY_H