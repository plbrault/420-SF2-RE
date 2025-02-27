#ifndef LION_H
#define LION_H

#include "Felin.h"

class Lion : public Felin {
public:
    Lion() : Felin(200, 20) {};
    void rugir();
};

#endif // LION_H
