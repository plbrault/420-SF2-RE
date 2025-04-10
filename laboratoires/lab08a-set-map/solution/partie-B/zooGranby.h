#ifndef __ZOO_GRANBY_H
#define __ZOO_GRANBY_H

#include <set>
#include <vector>

#include "ticketOfficeQueue.h"
#include "autobus.h"

#define ZOO_GRANBY_MAX_QUEUES 8

class ZooGranby {
private:
    std::vector<TicketOfficeQueue> _queues;
    std::set<std::size_t> _queuesOpen;
public:
    void openQueue(std::size_t idx);

    void handleBus(const Autobus &autobus);
};

#endif
