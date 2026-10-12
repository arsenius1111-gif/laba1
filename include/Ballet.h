#ifndef BALLET_H
#define BALLET_H

#include "Performance.h"

class Ballet : public Performance {
private:
    int dancersCount = 0;

public:
    Ballet(std::string_view title_, std::string_view director_,
        int duration_, int ageRestriction_, int dancersCount_);

    int getDancersCount() const;
    void setDancersCount(int value);

    void displayBalletInfo() const;
    void performDance() const;
};

#endif