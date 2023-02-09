#ifndef LUCKYSEQUENCE_H
#define LUCKYSEQUENCE_H

#include "LuckyCriteria.h"

class LuckySequence : public LuckyCriteria {
public:
    bool isLucky(Ticket& ticket) override;
};


#endif LUCKYSEQUENCE_H
