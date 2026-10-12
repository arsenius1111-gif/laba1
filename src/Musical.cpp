#include "Musical.h"
#include <iostream>

Musical::Musical(std::string_view title_, std::string_view director_,
    int duration_, int ageRestriction_, bool hasLiveBand_)
    : Performance(title_, director_, "Мюзикл", duration_, ageRestriction_),
      hasLiveBand(hasLiveBand_) {}

bool Musical::getHasLiveBand() const {
    return hasLiveBand;
}

void Musical::setHasLiveBand(bool value) {
    hasLiveBand = value;
}

void Musical::displayMusicalInfo() const {
    displayInfo();

    std::cout << "Живой музыкальный коллектив: "
              << (hasLiveBand ? "есть" : "нет") << '\n';
}

void Musical::performMusicalNumber() const {
    std::cout << "\n--- Музыкальный номер ---\n";
    std::cout << "Спектакль: " << getTitle() << '\n';
    std::cout << "Живой музыкальный коллектив: "
              << (hasLiveBand ? "есть" : "нет") << '\n';
    std::cout << "Исполняется музыкальный номер.\n";
}  