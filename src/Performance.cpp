#include "Performance.h"
#include <iostream>
#include <utility>

Performance::Performance(std::string title_, std::string director_, std::string genre_, int duration_, int ageRestriction_)
    : title(std::move(title_)), director(std::move(director_)), genre(std::move(genre_)), duration(duration_), ageRestriction(ageRestriction_) {}

std::string Performance::getTitle() const { return title; }
std::string Performance::getDirector() const { return director; }
std::string Performance::getGenre() const { return genre; }
int Performance::getDuration() const { return duration; }
int Performance::getAgeRestriction() const { return ageRestriction; }

void Performance::setTitle(const std::string_view& newTitle) {
    if (!newTitle.empty()) {
        title = newTitle;
    }
}

void Performance::setDuration(int newDuration) {
    if (newDuration > 0) {
        duration = newDuration;
    }
}

void Performance::displayInfo() const {
    std::cout << "Спектакль: \"" << title << "\" | Режиссер: " << director 
              << " | Жанр: " << genre << " | Длительность: " << duration 
              << " мин. | Возраст: " << ageRestriction << "+" << std::endl;
}