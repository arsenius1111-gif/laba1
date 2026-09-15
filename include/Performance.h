#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <string>
#include <string_view>
using namespace std;
class Performance {
private:
    string title;
    string genre;
    string director;
    int duration;
    int ageLimit;
public:
    Performance(string_view title_, string_view director_, string_view genre_, int duration_, int ageLimit_);
    void setTitle(string_view title_);
    void setDirector(string_view director_);
    void setGenre(string_view genre_);
    void setDuration(int duration_);
    void setAgeLimit(int ageLimit_);
    string getTitle() const;
    string getDirector() const;
    string getGenre() const;
    int getDuration() const;
    int getAgeLimit() const;
    void printInfo() const;
};
#endif