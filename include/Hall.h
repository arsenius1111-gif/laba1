#ifndef HALL_H
#define HALL_H
#include "Performance.h"
#include <vector>
class Hall {
private:
    int number;
    int capacity;
    std::vector<Performance> performances;
public:
    Hall(int number_, int capacity_);
    int getNumber() const;
    int getCapacity() const;
    void setCapacity(int newCapacity);
    bool addPerformance(const Performance& p);
    std::vector<Performance>& getPerformances();
    const std::vector<Performance>& getPerformances() const;
    void displayFullInfo() const;
};
#endif 