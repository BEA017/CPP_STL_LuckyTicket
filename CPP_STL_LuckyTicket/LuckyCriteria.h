#ifndef LUCKYCRITERIA_H
#define LUCKYCRITERIA_H

class Ticket;

class LuckyCriteria {
public:
    virtual bool isLucky(Ticket& ticket);
};


#endif LUCKYCRITERIA_H
