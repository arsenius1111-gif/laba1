#include "../include/Performance.h"
#include <iostream>

using namespace std;

Performance::Performance(string_view title_, string_view director_, string_view genre_, int duration_, int ageLimit_)
    : title(title_), genre(genre_), director(director_), duration(duration_), ageLimit(ageLimit_) {}

void Performance::setTitle(string_view title_) { this->title = title_; }
void Performance::setDirector(string_view director_) { this->director = director_; }
void Performance::setGenre(string_view genre_) { this->genre = genre_; }
void Performance::setDuration(int duration_) { this->duration = duration_; }
void Performance::setAgeLimit(int ageLimit_) { this->ageLimit = ageLimit_; }

string Performance::getTitle() const { return title; }
string Performance::getDirector() const { return director; }
string Performance::getGenre() const { return genre; }
int Performance::getDuration() const { return duration; }
int Performance::getAgeLimit() const { return ageLimit; }

void Performance::printInfo() const {
    cout << "Название: " << title << "\n"
         << "Режиссёр: " << director << "\n"
         << "Жанр: " << genre << "\n"
         << "Продолжительность: " << duration << " мин.\n"
         << "Возрастное ограничение: " << ageLimit << "+\n";
}