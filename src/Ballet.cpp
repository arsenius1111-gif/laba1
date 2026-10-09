#include "Ballet.h"
#include <iostream>

Ballet::Ballet(
    std::string_view title_,
    std::string_view director_,
    int duration_,
    int ageRestriction_,
    int dancersCount_,
    int actsCount_,
    int orchestraSize_
)
    : Performance(title_, director_, "Балет", duration_, ageRestriction_),
      dancersCount(dancersCount_),
      actsCount(actsCount_),
      orchestraSize(orchestraSize_) {}

int Ballet::getDancersCount() const {
    return dancersCount;
}

int Ballet::getActsCount() const {
    return actsCount;
}

int Ballet::getOrchestraSize() const {
    return orchestraSize;
}

void Ballet::setDancersCount(int value) {
    dancersCount = value;
}

void Ballet::setActsCount(int value) {
    actsCount = value;
}

void Ballet::setOrchestraSize(int value) {
    orchestraSize = value;
}

void Ballet::displayBalletInfo() const {
    displayInfo();
    std::cout << "Количество танцоров: " << dancersCount << '\n';
    std::cout << "Количество актов: " << actsCount << '\n';
    std::cout << "Размер оркестра: " << orchestraSize << '\n';
}

void Ballet::performDance() const {
    std::cout << "\n Танцевальная часть баллета ----\n";
    std::cout << "Спектакль: " << getTitle() << '\n';
    std::cout << "Колличество танцоров: " << dancersCount << '\n';
    std::cout << "Колличество актов: " << actsCount << '\n';
}