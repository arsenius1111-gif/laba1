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

    void displayInfo() const;

    bool operator==(const Performance& other) const;
    std::strong_ordering operator<=>(const Performance& other) const;

    friend void printPerformanceSecretDetails(const Performance& p);
    friend std::ostream& operator<<(std::ostream& os, const Performance& p);
    friend std::istream& operator>>(std::istream& is, Performance& p);
};

#endif