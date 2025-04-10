#include "ticketOfficeQueue.h"

#include <thread>

void TicketOfficeQueue::processFamily() {
    double pushButton = 0.0;
    Family current = this->_families.front();
    this->_families.pop();
    for (int i = 0; i < 100000 + (current.getSize() - 1) * 50000; i++) {
        pushButton += (pushButton * 0.12) / i;  // busy work
    }
}

void TicketOfficeQueue::openQueue() {
    this->_open = true;
}

bool TicketOfficeQueue::isOpen() const {
    return this->_open;
}

bool TicketOfficeQueue::queueUp(const Family &family)
{
    if (this->_size + family.getSize() <= TICKE_OFFICE_QUEUE_MAX) {
        this->_families.push(family);
        return true;
    }

    return false;
}

bool TicketOfficeQueue::process() {
    if (this->_families.size() > 0) {
        this->processFamily();
        return true;
    }
    return false;
}
