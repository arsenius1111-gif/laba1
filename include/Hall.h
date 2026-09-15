#ifndef HALL_H
#define HALL_H
#include <vector>
#include "Performance.h"
class Hall {
private:
    int number;
    int capacity;
    std::vector<Performance> performances;
    std::vector<int> soldTickets;
public:
    Hall(int number_, int capacity_);
    void addPerformance(const Performance& performance);
    int getPerformanceCount() const;
    Performance& getPerformance(int index);
    const Performance& getPerformance(int index) const;
    int getSoldTickets(int index) const;
    int getNumber() const;
    int getCapacity() const;
    bool sellTickets(int performanceIndex, int count);
    void printPerformances() const;
    void printInfo() const;
};
#endif