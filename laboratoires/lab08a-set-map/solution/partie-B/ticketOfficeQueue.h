#ifndef __TICKET_OFFICE_QUEUE_H
#define __TICKET_OFFICE_QUEUE_H

#include <cstdint>
#include <queue>

#include "family.h"

#define TICKE_OFFICE_QUEUE_MAX 120

class TicketOfficeQueue {
private:
    std::queue<Family> _families;
    uint8_t _size;
    bool _open;

    void processFamily();
public:

    void openQueue();
    bool isOpen() const;
    bool queueUp(const Family &family);
    bool process();
};

#endif