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
    void displayInfo() const;
    bool operator==(const Performance& other) const;
    std::strong_ordering operator<=>(const Performance& other) const;
    friend void printPerformanceSecretDetails(const Performance& p);
    friend std::ostream& operator<<(std::ostream& os, const Performance& p);
    friend std::istream& operator>>(std::istream& is, Performance& p);
};

#endif