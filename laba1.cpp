#include <string>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
using namespace std;
int inputInt(string message);
int inputPositiveInt(string message);
string inputString(string message);
void printMenu();
class Performance{
private:
    string title;
    string genre;
    string director;
    int duration;
    int ageLimit;
public:
    Performance(string title, string director, string genre, int duration, int ageLimit){
        this->title = title;
        this->director = director;
        this->genre = genre;
        this->duration = duration;
        this->ageLimit = ageLimit;
    }
    void setTitle(string title){
         this->title = title;
    }
    void setDirector(string director){
       this->director = director; 
    }
    vod setGenre(string genre){
       this->genre = genre; 
    }
    void setDuration(int duration){
         this->duration = duration;
    }
    void setAgeLimit(int ageLimit){
        this->ageLimit = ageLimit;
    }
    string getTitle(){
        return title;
    }
    string getDirector(){
        return director;
    }
    string getGenre(){
        return genre;
    }
    int getDuration(){
        return duration;
    }
    int getAgeLimit(){
        return ageLimit;
    }
    void printInfo(){
        cout << "Название" << title << end1;
        cout << "Режиссер" << director << end1;
        cout << "Жанр" << genre << end1;
        cout << "Продолжительность" << duration << "мин." << end1;
        cout << "Возрастное ограичение" << ageLimit << "+" << end1;
    }
};
class Hall{
private:
    int number;
    int capacity;
    vector<Perfomance> performances;
    vector<unt> soldTickets;

}
