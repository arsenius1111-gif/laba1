#ifndef OPERA_H
#define OPERA_H

#include "Performance.h"

class Opera : public Performance {
private:
    std::string voiceType;
    int chorusSize = 0;
    int actsCount = 0;

public:
    Opera(
        std::string_view title_,
        std::string_view director_,
        int duration_,
        int ageRestriction_,
        std::string_view voiceType_,
        int chorusSize_,
        int actsCount_
    );

    std::string getVoiceType() const;
    int getChorusSize() const;
    int getActsCount() const;

    void setVoiceType(std::string_view value);
    void setChorusSize(int value);
    void setActsCount(int value);

    void displayOperaInfo() const;
};

#endif