#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <string>
#include <iostream>
class Performance {
private:
    std::string title;
    std::string director;
    std::string genre;
    int duration;
    int ageRestriction;
public:
    Performance ();
    Performance(std::string title_, std::string director_, std::string genre_, int duration_, int ageRestriction_);
    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getDuration() const;
    int getAgeRestriction() const;
    void setTitle(const std::string_view& newTitle);
    void setDuration(int newDuration);

    void displayInfo() const;

    bool operator==(const Performance& other) const;
    bool operator!=(const Performance& other) const;

    bool operator<(const Performance& other) const;
    bool operator>(const Performance& other) const;
    bool operator<=(const Performance& other) const;
    bool operator>=(const Performance& other) const;

    friend void printPerformanceSecretDetails(const Performance& p);

    friend std::ostream& operator<<(std::ostream& os, const Performance& p);   
    friend std::istream& operator>>(std::istream& is, Performance& p);
};
#endif 