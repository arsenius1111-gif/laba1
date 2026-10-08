#ifndef MUSICAL_H
#define MUSICAL_H

#include "Performance.h"

class Musical : public Performance {
private:
    int musicalNumbers = 0;
    int danceNumbers = 0;
    bool hasLiveBand = false;

public:
    Musical(
        std::string_view title_,
        std::string_view director_,
        int duration_,
        int ageRestriction_,
        int musicalNumbers_,
        int danceNumbers_,
        bool hasLiveBand_
    );

    int getMusicalNumbers() const;
    int getDanceNumbers() const;
    bool getHasLiveBand() const;

    void setMusicalNumbers(int value);
    void setDanceNumbers(int value);
    void setHasLiveBand(bool value);

    void displayMusicalInfo() const;
};

#endif