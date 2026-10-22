#ifndef MUSICAL_H
#define MUSICAL_H

#include "Performance.h"

class Musical : public Performance {
private:
    bool hasLiveBand = false;

public:
    Musical(
        std::string_view title_,
        std::string_view director_,
        int duration_,
        int ageRestriction_,
        bool hasLiveBand_
    );

    bool getHasLiveBand() const;
    void setHasLiveBand(bool value);

    std::string getType() const override;
    void displayInfo() const override;
    void performSpecialAction() const override;
};

#endif