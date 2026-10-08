#include "Musical.h"
#include <iostream>

Musical::Musical(
    std::string_view title_,
    std::string_view director_,
    int duration_,
    int ageRestriction_,
    int musicalNumbers_,
    int danceNumbers_,
    bool hasLiveBand_
)
    : Performance(title_, director_, "Мюзикл", duration_, ageRestriction_),
      musicalNumbers(musicalNumbers_),
      danceNumbers(danceNumbers_),
      hasLiveBand(hasLiveBand_) {}

int Musical::getMusicalNumbers() const {
    return musicalNumbers;
}

int Musical::getDanceNumbers() const {
    return danceNumbers;
}

bool Musical::getHasLiveBand() const {
    return hasLiveBand;
}

void Musical::setMusicalNumbers(int value) {
    musicalNumbers = value;
}

void Musical::setDanceNumbers(int value) {
    danceNumbers = value;
}

void Musical::setHasLiveBand(bool value) {
    hasLiveBand = value;
}

void Musical::displayMusicalInfo() const {
    displayInfo();
    std::cout << "Количество музыкальных номеров: " << musicalNumbers << '\n';
    std::cout << "Количество танцевальных номеров: " << danceNumbers << '\n';
    std::cout << "Живая музыкальная группа: "
              << (hasLiveBand ? "да" : "нет") << '\n';
}