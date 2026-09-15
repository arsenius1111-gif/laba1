#include "Hall.h"
#include <iostream>
Hall::Hall(int number_, int capacity_) : number(number_), capacity(capacity_) {}
int Hall::getNumber() const { return number; }
int Hall::getCapacity() const { return capacity; }
void Hall::setCapacity(int newCapacity) {
    if (newCapacity > 0) {
        capacity = newCapacity;
    }
}
bool Hall::addPerformance(const Performance& p) {
    int totalDuration = 0;
    for (const auto& existing : performances) {
        totalDuration += existing.getDuration();
    }
    if (totalDuration + p.getDuration() > 480) {
        std::cout << "\n[Ошибка ограничения]: Нельзя добавить \"" << p.getTitle() 
                  << "\". Превышен дневной лимит времени зала (480 мин)!\n";
        return false;
    }
    performances.push_back(p);
    std::cout << "\nСпектакль \"" << p.getTitle() << "\" успешно добавлен в Зал №" << number << "!\n";
    return true;
}
std::vector<Performance>& Hall::getPerformances() { return performances; }
const std::vector<Performance>& Hall::getPerformances() const { return performances; }
void Hall::displayFullInfo() const {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "Информация о Зале №" << number << " (Вместимость: " << capacity << " мест)" << std::endl;
    std::cout << "Список спектаклей:" << std::endl;
    if (performances.empty()) {
        std::cout << "  (нет запланированных спектаклей)" << std::endl;
    } else {
        for (size_t i = 0; i < performances.size(); ++i) {
            std::cout << "  " << i + 1 << ". ";
            performances[i].displayInfo();
        }
    }
    std::cout << "==========================================" << std::endl;
}