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

void Performance::displayInfo() const {
    std::cout << "Спектакль: \"" << title << "\" | Режиссер: " << director
              << " | Жанр: " << genre << " | Длительность: " << duration
              << " мин | Возраст: " << ageRestriction << "+" << std::endl;
}

bool Performance::operator==(const Performance& other) const {
    return this->title == other.title;
}

bool Performance::operator<(const Performance& other) const {
    return this->duration < other.duration;
}

void printPerformanceSecretDetails(const Performance& p) {
    std::cout << "\n[Дружественная функция]: Прямой доступ к private-полям!" << std::endl;
    std::cout << "Название: " << p.title << ", Длительность: " << p.duration << " мин.\n";
}