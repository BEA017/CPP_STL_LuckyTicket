#include "Ticket.h"
 
Ticket::Ticket() {
    this->numbers = new unsigned[Ticket::NUMBERS_COUNT];
    for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
        this->numbers[i] = 0;
    }
}

Ticket::Ticket(const unsigned* numbers) {
    this->numbers = new unsigned[Ticket::NUMBERS_COUNT];
    for (unsigned i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
        this->numbers[i] = numbers[i];
    }
}

Ticket::~Ticket() {
    delete[] this->numbers;
}

void Ticket::generateNumbers() {
    for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
        this->numbers[i] = rand() % 9;
    }
}

void Ticket::print() {
    for (int i = 0; i < Ticket::NUMBERS_COUNT; ++i) {
        std::cout << this->numbers[i];
    }
    std::cout << std::endl;
}

bool Ticket::isLucky(std::list<luckyFunctions> functions) {
    for (auto& function : functions) {
        if (function(this->numbers))
            return true;
    }
    return false;
}

bool Ticket::isLucky(std::list<LuckyCriteria*> criteria) {
    for (auto& criterion : criteria) {
        if (criterion->isLucky(*this))
            return true;
    }

    return false;
}

void Ticket::save(FILE* fileStream) {
    for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i) {
        fprintf(fileStream, "%d", this->numbers[i]);
    }
    fprintf(fileStream, "%d\n", this->numbers[Ticket::NUMBERS_COUNT - 1]);
}

unsigned Ticket::operator[](const unsigned int& i) 
{
    if (i >= 0 && i < Ticket::NUMBERS_COUNT) return this->numbers[i];
 }

