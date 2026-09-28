#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>
#include <iostream>
#include <compare>

class Performance {
private:
    std::string title;
    std::string director;
    std::string genre;
    int duration = 0;
    int ageRestriction = 0;

public:
    Performance();
    Performance(const std::string& title_, const std::string& director_, const std::string& genre_, int duration_, int ageRestriction_);

    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getDuration() const;
    int getAgeRestriction() const;

    void setTitle(const std::string& title_);
    void setDirector(const std::string& director_);
    void setGenre(const std::string& genre_);
    void setDuration(int duration_);
    void setAgeRestriction(int ageRestriction_);

    void displayInfo() const;

    bool operator==(const Performance& other) const;
    std::strong_ordering operator<=>(const Performance& other) const;

    friend void printPerformanceSecretDetails(const Performance& p);

    friend std::ostream& operator<<(std::ostream& os, const Performance& p) {
        os << "Спектакль: \"" << p.title << "\" | Режиссер: " << p.director 
           << " | Жанр: " << p.genre << " | Длительность: " << p.duration 
           << " мин | Возраст: " << p.ageRestriction << "+";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Performance& p) {
        std::cout << "Введите название спектакля: ";
        is.ignore(10000, '\n');
        std::getline(is, p.title);
        std::cout << "Введите режиссера: ";
        std::getline(is, p.director);
        std::cout << "Введите жанр: ";
        std::getline(is, p.genre);
        std::cout << "Введите длительность (в минутах): ";
        is >> p.duration;
        std::cout << "Введите возрастное ограничение: ";
        is >> p.ageRestriction;
        return is;
    }
};

#endif