#include "LuckyAlternation.h"
#include "Ticket.h"
bool LuckyAlternation::isLucky(Ticket& ticket)
{
    if (LuckyCriteria::isLucky(ticket))
    {     
      if (ticket[0] != ticket[2] && ticket[2] != ticket[4] && ticket[1] != ticket[3] && ticket[3] != ticket[5]) 
          return false;
    }
    else return true;
}
