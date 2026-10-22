#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <compare>
#include <iostream>
#include <string>
#include <string_view>

class Performance {
private:
    std::string title;
    std::string director;
    std::string genre;
    int duration = 0;
    int ageRestriction = 0;

public:
    Performance();

    Performance(std::string_view title_, std::string_view director_,
        std::string_view genre_, int duration_, int ageRestriction_);

    virtual ~Performance() = default;

    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getDuration() const;
    int getAgeRestriction() const;

    void setTitle(std::string_view title_);
    void setDirector(std::string_view director_);
    void setGenre(std::string_view genre_);
    void setDuration(int duration_);
    void setAgeRestriction(int ageRestriction_);

    virtual std::string getType() const;
    virtual void displayInfo() const;
    virtual void performSpecialAction() const = 0;

    bool operator==(const Performance& other) const;
    std::strong_ordering operator<=>(const Performance& other) const;

    friend void printPerformanceSecretDetails(const Performance& p);

    friend std::ostream& operator<<(
        std::ostream& os, const Performance& p) {
        os << "Спектакль: " << p.title << '\n'
           << "Режиссёр: " << p.director << '\n'
           << "Жанр: " << p.genre << '\n'
           << "Длительность: " << p.duration << " мин.\n"
           << "Возрастное ограничение: " << p.ageRestriction << "+\n";

        return os;
    }

    friend std::istream& operator>>(
        std::istream& is, Performance& p) {
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
};

#endif