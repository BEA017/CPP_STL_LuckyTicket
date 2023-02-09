/*1. ������ � ���������� �������
��� ������ ������������
������ ���������� � 111111 � ������������� 999999
����������� �������� ��������� ��������:
123006 - ����� ������ 3 ����� ����� ����� ��������� 3 �����
123456 - ������ ���� � ������� �����������
987654 - ������ ���� � ������� ��������
111111 - ��� ����� ����������
202020 - ����� ����������

�������:
- ���������� ������� ����� ���������� �������
- ��������� ��� ������ ������� � ����
- ��� ������ ������������ ���� ����������� ������������� ������ ��������� ����� �������� ���������� �������
- ������������ ������ ��������� STL � ���������

2. ������ ���������� ������ ��� ������������� ������������ � � �������������� ���������� �� �������

3. ������ ���������� ������ ��� ������������� ������������ � � �������������� lambda-���������*/
#include <iostream>
#include "Ticket.h"
#include "Ticket.h"
#include "LuckySum.h"
#include "LuckySequence.h"
#include "LuckyBackSequence.h"
#include "LuckySame.h"
#include "LuckyAlternation.h"

#include <list>

bool luckySum(const unsigned* items) 
{
    unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;

    for (unsigned i = 0; i < count / 2; ++i) sum += items[i];
    for (unsigned i = count / 2; i < count; ++i) sum1 += items[i];

    return sum == sum1;
}

bool luckySequence(const unsigned* items)
{
    for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i) 
    {
        if (items[i] > items[i + 1]+1) return false;
    }
    return true;
}

bool luckyBackSequence (const unsigned* items)
{
     for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
     {
         if (items[i] != items[i + 1] - 1) return false;
     }  
     return true;
}

bool luckySame (const unsigned* items)
{
     for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
     {
         if (items[i] != items[i + 1]) return false;
     } 
     return true;
}

bool luckyAlternation(const unsigned* items)
{
  if (items[0] != items[2] && items[2] != items[4] && items[1] != items[3] && items[3] != items[5])
     return false;
  
  return true;    
}



int main() {
    srand(time(nullptr));

    std::list<Ticket::luckyFunctions> functions;

   // functions.push_back(luckySum);
   // functions.push_back(luckySequence);
   // functions.push_back(luckyBackSequence);
    //functions.push_back(luckySame);
   // functions.push_back(luckyAlternation);

    functions.push_back([](const unsigned* items)->bool {
    unsigned sum = 0, sum1 = 0, count = Ticket::NUMBERS_COUNT;

    for (unsigned i = 0; i < count / 2; ++i) sum += items[i];
    for (unsigned i = count / 2; i < count; ++i) sum1 += items[i];

    return sum == sum1; });

    functions.push_back([](const unsigned* items)->bool {
        for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
        {
            if (items[i] != items[i + 1]+ 1) return false;
        }
        return true; });
   
    functions.push_back([](const unsigned* items)->bool {

        for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
        {
            if (items[i] != items[i + 1] - 1) return false;
        }
        return true; });
 
    functions.push_back([](const unsigned* items)->bool{  
      for (int i = 0; i < Ticket::NUMBERS_COUNT - 1; ++i)
  {
      if (items[i] != items[i + 1]) return false;
  }
  return true; });

    std::list<Ticket *> tickets;

    for (int i = 0; i < 100000; ++i) {
        auto *ticket = new Ticket();
        ticket->generateNumbers();

        if (ticket->isLucky(functions))
            tickets.push_back(ticket);

        else delete ticket;
    }

    FILE *dest;
    if (fopen_s(&dest, "tickets_res2.txt", "w") == 0) {
        auto iterator = tickets.begin();
        while (iterator != tickets.end()) {
            (**iterator).print();
            (**iterator).save(dest);
            ++iterator;
        }
        std::cout <<"\nIn the given criteria find: " << tickets.size();
        fprintf(dest, "%s", "\nIn the given criteria find: ");
        fprintf(dest, "%d", tickets.size());
        fclose(dest);
    }
    return 0;
}


/*
// �����������
int main()
{
    srand(time(nullptr));

    std::list<Ticket*> tickets;
    std::list<LuckyCriteria*> criteriaList;

   // criteriaList.push_back(new LuckySum);
  // criteriaList.push_back(new LuckySequence);
   // criteriaList.push_back(new LuckyBackSequence);
   // criteriaList.push_back(new LuckySame);
   //criteriaList.push_back(new LuckyAlternation);


    for (int i = 0; i < 100; ++i) {
        Ticket* ticket = new Ticket();
        ticket->generateNumbers();

        if (ticket->isLucky(criteriaList))
            tickets.push_back(ticket);
        else delete ticket;
    }

    FILE* dest;
    if (fopen_s(&dest, "tickets_res.txt", "w") == 0) {
        auto iterator = tickets.begin();
        while (iterator != tickets.end()) {
            (*iterator)->print();
            (**iterator).save(dest);
            ++iterator;
        }

        fclose(dest);
    }

    return 0;
}*/