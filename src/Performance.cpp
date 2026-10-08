#include "Performance.h"

Performance::Performance()
    : title(""), director(""), genre("") {}

Performance::Performance(
    std::string_view title_,
    std::string_view director_,
    std::string_view genre_,
    int duration_,
    int ageRestriction_
)
    : title(title_),
      director(director_),
      genre(genre_),
      duration(duration_),
      ageRestriction(ageRestriction_) {}

std::string Performance::getTitle() const {
    return title;
}

std::string Performance::getDirector() const {
    return director;
}

std::string Performance::getGenre() const {
    return genre;
}

int Performance::getDuration() const {
    return duration;
}

int Performance::getAgeRestriction() const {
    return ageRestriction;
}

void Performance::setTitle(std::string_view title_) {
    title = title_;
}

void Performance::setDirector(std::string_view director_) {
    director = director_;
}

void Performance::setGenre(std::string_view genre_) {
    genre = genre_;
}

void Performance::setDuration(int duration_) {
    duration = duration_;
}

void Performance::setAgeRestriction(int ageRestriction_) {
    ageRestriction = ageRestriction_;
}

void Performance::displayInfo() const {
    std::cout << *this << std::endl;
}

bool Performance::operator==(const Performance& other) const {
    return title == other.title;
}

std::strong_ordering Performance::operator<=>(const Performance& other) const {
    return duration <=> other.duration;
}

void printPerformanceSecretDetails(const Performance& p) {
    std::cout << "\n[Friend-функция]: Прямой доступ к private-полям спектакля:"
              << std::endl;
    std::cout << "Название: " << p.title
              << " | Длительность: " << p.duration << " мин.\n";
}