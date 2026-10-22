#include "Musical.h"
#include <iostream>

Musical::Musical(
    std::string_view title_,
    std::string_view director_,
    int duration_,
    int ageRestriction_,
    bool hasLiveBand_
)
    : Performance(title_, director_, "Мюзикл", duration_, ageRestriction_),
      hasLiveBand(hasLiveBand_) {}

bool Musical::getHasLiveBand() const {
    return hasLiveBand;
}

void Musical::setHasLiveBand(bool value) {
    hasLiveBand = value;
}

std::string Musical::getType() const {
    return "Мюзикл";
}

void Musical::displayInfo() const {
    Performance::displayInfo();

    std::cout << "Живая музыкальная группа: "
              << (hasLiveBand ? "есть" : "нет") << '\n';
}

void Musical::performSpecialAction() const {
    std::cout << "\n=== Музыкальный номер ===\n";
    std::cout << "Мюзикл \"" << getTitle()
              << "\" исполняет музыкальный номер.\n";

    if (hasLiveBand) {
        std::cout << "Музыка исполняется живой группой.\n";
    } else {
        std::cout << "Используется фонограмма или другая музыкальная запись.\n";
    }
}