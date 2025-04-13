#ifndef __ZOO_H
#define __ZOO_H

#include "ticketOfficeQueue.h"
#include "autobus.h"
#include <array>
#include <set>

class Zoo {
private:
    static const int MAX_QUEUES = 8;
    std::array<TicketOfficeQueue, MAX_QUEUES> _queues;
    std::set<std::size_t> _queueOpen;

public:
    Zoo();
    void receiveBus(Autobus& bus);
    void openQueue(std::size_t);
    void closeQueue(std::size_t);
    void processQueues();
};

#endif
