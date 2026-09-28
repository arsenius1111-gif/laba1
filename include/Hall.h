#ifndef HALL_H
#define HALL_H

#include <iostream>
#include <vector>
#include "Performance.h"

class Hall {
private:
    int number = 0;
    int capacity = 0;
    int ticketsSold = 0;
    std::vector<Performance> performances;

public:
    Hall() = default;
    Hall(int number_, int capacity_);

    int getNumber() const;
    int getCapacity() const;
    int getTicketsSold() const;

    void setNumber(int number_);
    void setCapacity(int newCapacity);

    bool sellTickets(int count);
    bool addPerformance(const Performance& p);

    const std::vector<Performance>& getPerformances() const;
    std::vector<Performance>& getPerformances();

    void displayFullInfo() const;

    Hall& operator+=(const Performance& p);
    Hall& operator-=(const Performance& p);

    friend void printHallAnalytics(const Hall& hall);
};

#endif