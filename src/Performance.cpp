#include "Performance.h"
#include <limits>

Performance::Performance()
    : title(""), director(""), genre("") {}

Performance::Performance(std::string_view title_,
    std::string_view director_, std::string_view genre_,
    int duration_, int ageRestriction_)
    : title(title_), director(director_), genre(genre_),
      duration(duration_), ageRestriction(ageRestriction_) {}

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
    if (duration_ > 0) {
        duration = duration_;
    } else {
        std::cout << "Длительность должна быть положительной.\n";
    }
}

void Performance::setAgeRestriction(int ageRestriction_) {
    if (ageRestriction_ >= 0) {
        ageRestriction = ageRestriction_;
    } else {
        std::cout << "Возрастное ограничение не может быть отрицательным.\n";
    }
}

void Performance::displayInfo() const {
    std::cout << "Название: " << title << '\n';
    std::cout << "Режиссёр: " << director << '\n';
    std::cout << "Жанр: " << genre << '\n';
    std::cout << "Длительность: " << duration << " мин.\n";
    std::cout << "Возрастное ограничение: "
              << ageRestriction << "+\n";
}

bool Performance::operator==(const Performance& other) const {
    return title == other.title;
}

std::strong_ordering Performance::operator<=>(
    const Performance& other) const {
    return duration <=> other.duration;
}

void printPerformanceSecretDetails(const Performance& p) {
    std::cout << "Закрытая информация о спектакле:\n";
    std::cout << "Название: " << p.title << '\n';
    std::cout << "Режиссёр: " << p.director << '\n';
    std::cout << "Длительность: " << p.duration << " мин.\n";
}

std::ostream& operator<<(std::ostream& os, const Performance& p) {
    os << "Спектакль: " << p.title << '\n'
       << "Режиссёр: " << p.director << '\n'
       << "Жанр: " << p.genre << '\n'
       << "Длительность: " << p.duration << " мин.\n"
       << "Возрастное ограничение: " << p.ageRestriction << "+\n";

    return os;
}

std::istream& operator>>(std::istream& is, Performance& p) {
    std::string title;
    std::string director;
    std::string genre;
    int duration = 0;
    int ageRestriction = 0;

    std::cout << "Введите название спектакля: ";
    is >> std::ws;
    std::getline(is, title);

    std::cout << "Введите режиссёра: ";
    std::getline(is, director);

    std::cout << "Введите жанр: ";
    std::getline(is, genre);

    std::cout << "Введите длительность в минутах: ";
    if (!(is >> duration) || duration <= 0) {
        is.setstate(std::ios::failbit);
        return is;
    }

    std::cout << "Введите возрастное ограничение: ";
    if (!(is >> ageRestriction) || ageRestriction < 0) {
        is.setstate(std::ios::failbit);
        return is;
    }

    p.title = title;
    p.director = director;
    p.genre = genre;
    p.duration = duration;
    p.ageRestriction = ageRestriction;

    return is;
}