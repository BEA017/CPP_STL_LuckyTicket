#include "LuckyCriteria.h"
#include "Ticket.h"

bool LuckyCriteria::isLucky(Ticket& ticket) {
    for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
        if (ticket[i] < 0 || ticket[i] > 9) return false;
    }

    return true;
}
