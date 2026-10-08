#include "Opera.h"
#include <iostream>

Opera::Opera(
    std::string_view title_,
    std::string_view director_,
    int duration_,
    int ageRestriction_,
    std::string_view voiceType_,
    int chorusSize_,
    int actsCount_
)
    : Performance(title_, director_, "Опера", duration_, ageRestriction_),
      voiceType(voiceType_),
      chorusSize(chorusSize_),
      actsCount(actsCount_) {}

std::string Opera::getVoiceType() const {
    return voiceType;
}

int Opera::getChorusSize() const {
    return chorusSize;
}

int Opera::getActsCount() const {
    return actsCount;
}

void Opera::setVoiceType(std::string_view value) {
    voiceType = value;
}

void Opera::setChorusSize(int value) {
    chorusSize = value;
}

void Opera::setActsCount(int value) {
    actsCount = value;
}

void Opera::displayOperaInfo() const {
    displayInfo();
    std::cout << "Тип ведущего голоса: " << voiceType << '\n';
    std::cout << "Размер хора: " << chorusSize << '\n';
    std::cout << "Количество актов: " << actsCount << '\n';
}