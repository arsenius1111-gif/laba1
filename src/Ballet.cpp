#include "Ballet.h"
#include <iostream>

Ballet::Ballet(std::string_view title_, std::string_view director_,
    int duration_, int ageRestriction_, int dancersCount_)
    : Performance(title_, director_, "Балет", duration_, ageRestriction_),
      dancersCount(dancersCount_) {}

int Ballet::getDancersCount() const {
    return dancersCount;
}

void Ballet::setDancersCount(int value) {
    if (value > 0) {
        dancersCount = value;
    } else {
        std::cout << "Количество танцоров должно быть положительным.\n";
    }
}

void Ballet::displayBalletInfo() const {
    displayInfo();
    std::cout << "Количество танцоров: " << dancersCount << '\n';
}

void Ballet::performDance() const {
    std::cout << "\n--- Танцевальная часть балета ---\n";
    std::cout << "Спектакль: " << getTitle() << '\n';
    std::cout << "Количество танцоров: " << dancersCount << '\n';
    std::cout << "Исполняется танцевальная сцена.\n";
}