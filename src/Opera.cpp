#include "Opera.h"
#include <iostream>

Opera::Opera(
    std::string_view title_,
    std::string_view director_,
    int duration_,
    int ageRestriction_,
    bool hasRecitatives_
)
    : Performance(title_, director_, "Опера", duration_, ageRestriction_),
      hasRecitatives(hasRecitatives_) {}

bool Opera::getHasRecitatives() const {
    return hasRecitatives;
}

void Opera::setHasRecitatives(bool value) {
    hasRecitatives = value;
}

std::string Opera::getType() const {
    return "Опера";
}

void Opera::displayInfo() const {
    Performance::displayInfo();

    std::cout << "Наличие речитативов: "
              << (hasRecitatives ? "есть" : "нет") << '\n';
}

void Opera::performSpecialAction() const {
    std::cout << "\n=== Вокальное исполнение ===\n";
    std::cout << "Опера \"" << getTitle()
              << "\" исполняется вокально.\n";

    if (hasRecitatives) {
        std::cout << "В исполнении предусмотрены речитативы.\n";
    } else {
        std::cout << "В исполнении нет речитативов.\n";
    }
}