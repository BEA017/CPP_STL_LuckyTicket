#pragma once
#include "LuckyCriteria.h"
class LuckyBackSequence : public LuckyCriteria
{
public:
	bool isLucky(Ticket& ticket) override;
};

