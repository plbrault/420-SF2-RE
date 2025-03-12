#ifndef CHAT_H
#define CHAT_H

#include "Felin.h"

class Chat : public Felin {
public:
    Chat() : Felin(50, 10) {};
    void miauler();
};

#endif // CHAT_H
