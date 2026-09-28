#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <string>
#include <iostream>

class Performance {
private:
    std::string title;
    std::string director;
    std::string genre;
    int duration = 0;
    int ageRestriction = 0;

public:
    Performance();
    Performance(std::string title_, std::string director_, std::string genre_, int duration_, int ageRestriction_);

    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getDuration() const;
    int getAgeRestriction() const;

    void displayInfo() const;

    bool operator==(const Performance& other) const;
    bool operator<(const Performance& other) const;
    bool operator>(const Performance& other) const;
    bool operator<=(const Performance& other) const;
    bool operator>=(const Performance& other) const;
  
    friend void printPerformanceSecretDetails(const Performance& p);

    friend std::ostream& operator<<(std::ostream& os, const Performance& p) {
        os << "Спектакль: \"" << p.title << "\" (" << p.genre << ", " 
           << p.duration << " мин, " << p.ageRestriction << "+)";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Performance& p) {
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
};

#endif