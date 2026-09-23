#ifndef HALL_H
#define HALL_H
#include "Performance.h"
#include <vector>
#include <iostream>
class Hall {
private:
    int number;
    int capacity;
    int ticketsSold = 0;
    std::vector<Performance> performances;
public:
    Hall(int number_, int capacity_);
    int getNumber() const;
    int getCapacity() const;
    int getTicketsSold() const;
    void setCapacity(int newCapacity);
    bool sellTickets (int count);
    bool addPerformance(const Performance& p);
    std::vector<Performance>& getPerformances();
    const std::vector<Performance>& getPerformances() const;
    void displayFullInfo() const;
};
#endif 