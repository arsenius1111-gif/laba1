#include "Opera.h"
#include <iostream>

Opera::Opera(std::string_view title_, std::string_view director_,
    int duration_, int ageRestriction_, bool hasRecitatives_)
    : Performance(title_, director_, "Опера", duration_, ageRestriction_),
      hasRecitatives(hasRecitatives_) {}

bool Opera::getHasRecitatives() const {
    return hasRecitatives;
}

void Opera::setHasRecitatives(bool value) {
    hasRecitatives = value;
}

void Opera::displayOperaInfo() const {
    displayInfo();

    std::cout << "Речитативы: "
              << (hasRecitatives ? "есть" : "нет") << '\n';
}

void Opera::performVocal() const {
    std::cout << "\n--- Вокальная часть оперы ---\n";
    std::cout << "Спектакль: " << getTitle() << '\n';
    std::cout << "Речитативы: "
              << (hasRecitatives ? "есть" : "нет") << '\n';
    std::cout << "Исполняется вокальная партия.\n";
}