#include "LuckySum.h"
#include "Ticket.h"

bool LuckySum::isLucky(Ticket& ticket) {
    if (LuckyCriteria::isLucky(ticket)) {
        unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;

        for (unsigned i = 0; i < count / 2; ++i) sum += ticket[i];
        for (unsigned i = count / 2; i < count; ++i) sum1 += ticket[i];

        return sum == sum1;

    }
    else return false;
}
