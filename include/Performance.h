#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <string>
class Performance {
private:
    std::string title;
    std::string director;
    std::string genre;
    int duration;
    int ageRestriction;
public:
    Performance(std::string title_, std::string director_, std::string genre_, int duration_, int ageRestriction_);
    std::string getTitle() const;
    std::string getDirector() const;
    std::string getGenre() const;
    int getDuration() const;
    int getAgeRestriction() const;
};
#endif 