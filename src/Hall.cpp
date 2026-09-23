#include "Hall.h"
Hall::Hall(int number_, int capacity_) 
    : number(number_), capacity(capacity_) {}

int Hall::getNumber() const { return number; }
int Hall::getCapacity() const { return capacity; }
int Hall::getTicketsSold() const { return ticketsSold; }

void Hall::setCapacity(int newCapacity) {
    if (newCapacity > 0) {
        capacity = newCapacity;
    }
}

bool Hall::sellTickets(int count) {
    if (count <= 0) {
        std::cout << "\n[Ошибка]: Количество билетов должно быть больше 0!\n";
        return false;
    }

    if (ticketsSold + count > capacity) {
        std::cout << "\n[Ошибка вместимости]: Нельзя продать " << count 
                  << " билетов! Осталось свободных мест: " << (capacity - ticketsSold) 
                  << " (Вместимость: " << capacity << ").\n";
        return false;
    }

    ticketsSold += count;
    std::cout << "\n[Успех]: Успешно продано билетов: " << count 
              << ". Всего проданных: " << ticketsSold << "/" << capacity << "\n";
    return true;
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
    return true;
}

const std::vector<Performance>& Hall::getPerformances() const { return performances; }
std::vector<Performance>& Hall::getPerformances() { return performances; }

void Hall::displayFullInfo() const {
    std::cout << "\n=== Зал №" << number << " ===" << std::endl;
    std::cout << "Вместимость: " << capacity << " мест" << std::endl;
    std::cout << "Продано билетов: " << ticketsSold << " / " << capacity << std::endl;
    std::cout << "Свободных мест: " << (capacity - ticketsSold) << std::endl;
    std::cout << "---------------------------" << std::endl;

    if (performances.empty()) {
        std::cout << "В этом зале пока нет спектаклей." << std::endl;
    } else {
        std::cout << "Репертуар зала:" << std::endl;
        for (size_t i = 0; i < performances.size(); ++i) {
            std::cout << i + 1 << ". ";
            performances[i].displayInfo();
        }
    }
}