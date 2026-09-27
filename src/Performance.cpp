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
bool Performance::operator==(const Performance& other) const {
    return this->title == other.title;  
}
bool Performance::operator!=(const Performance& other) const {
    return !(*this == other);
}
bool Performance::operator<(const Performance& other) const {
    return this->duration < other.duration; 
}
bool Performance::operator>(const Performance& other) const {
    return other < *this;  
}
bool Performance::operator<=(const Performance& other) const {
    return !(*this > other);   
}
bool Performance::operator>=(const Performance& other) const {
    return !(*this < other);   
} 
void printPerformanceSecretDetails(const Performance& p){
    std::cout << "\n[Дружественная функция]: Прямой доступ к private-полям!" << std::endl;
    std::cout << "Название: " <<p.title << ",Длительность: " <<p.duration << "мин.\n";
}
std::ostream& operator<<( std::ostream& os, const Performance& p) {
    os << "Спектакль: \""<<p.title << "\" ("<<p.genre <<","<<p.duration<<"мин,"<<p.ageRestriction<<"+)";
return os;
}
std::istream& operator>>(std::istream& is, Performance& p) {
    std::cout << "Введите название спектакля: ";
    is >> p.title;
    std::cout << "Введите режиссера: ";
    is >> p.director;
    std::cout << "Введите жанр: ";
    is >> p.genre;
    std::cout << "Введите длительность (мин): ";
    is >> p.duration;
    std::cout << "Введите возрастное ограничение: ";
    is >> p.ageRestriction;
    return is;
}