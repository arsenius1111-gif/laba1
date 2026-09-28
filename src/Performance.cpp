#include "Performance.h"

Performance::Performance()
    : title(""), director(""), genre("") {}

Performance::Performance(const std::string& title_, const std::string& director_, const std::string& genre_, int duration_, int ageRestriction_)
    : title(title_), director(director_), genre(genre_), duration(duration_), ageRestriction(ageRestriction_) {}

std::string Performance::getTitle() const { return title; }
std::string Performance::getDirector() const { return director; }
std::string Performance::getGenre() const { return genre; }
int Performance::getDuration() const { return duration; }
int Performance::getAgeRestriction() const { return ageRestriction; }

void Performance::setTitle(const std::string& title_) { title = title_; }
void Performance::setDirector(const std::string& director_) { director = director_; }
void Performance::setGenre(const std::string& genre_) { genre = genre_; }
void Performance::setDuration(int duration_) { duration = duration_; }
void Performance::setAgeRestriction(int ageRestriction_) { ageRestriction = ageRestriction_; }

void Performance::displayInfo() const {
    std::cout << *this << std::endl;
}

bool Performance::operator==(const Performance& other) const {
    return this->title == other.title;
}

std::strong_ordering Performance::operator<=>(const Performance& other) const {
    return this->duration <=> other.duration;
}

void printPerformanceSecretDetails(const Performance& p) {
    std::cout << "\n[Friend-функция]: Прямой доступ к private-полям спектакля:" << std::endl;
    std::cout << "Название: " << p.title << " | Длительность: " << p.duration << " мин.\n";
}