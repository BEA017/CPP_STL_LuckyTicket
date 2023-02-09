#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <ctime>
#include <list>
#include "LuckyCriteria.h"

class Ticket {
private:
    unsigned* numbers;
public:
    static const unsigned NUMBERS_COUNT = 6;
    typedef bool (*luckyFunctions)(const unsigned*);

    Ticket();

    explicit Ticket(const unsigned* numbers);

    ~Ticket();

    void generateNumbers();

    void print();

    bool isLucky(std::list<luckyFunctions> functions);

    bool isLucky(std::list<LuckyCriteria*> criteria);

    void save(FILE* fileStream);

    unsigned operator[](const unsigned& i);
};


#endif TICKET_H
