#include "zoo.h"
#include <iostream>

Zoo::Zoo() {}

void Zoo::receiveBus(Autobus& bus) {
    while (!bus.isEmpty()) {
        Family family = bus.climbDown();

        // Try to find a queue with space
        bool placed = false;
        for (auto& queue : _queues) {
            if (queue.isOpen() && queue.queueUp(family)) {
                placed = true;
                break;
            }
        }

        // If no space and we can open a new queue
        if (!placed && _queues.size() < MAX_QUEUES) {
            TicketOfficeQueue newQueue;
            newQueue.openQueue();
            newQueue.queueUp(family);
            _queues.push_back(newQueue);
        }
    }
}

void Zoo::openQueue(std::size_t) {
}

void Zoo::processQueues() {
    for (auto& queue : _queues) {
        while (queue.process()) {
            // Process all families
        }
    }
}
