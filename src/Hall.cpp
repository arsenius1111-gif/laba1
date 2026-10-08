#include "Hall.h"

Hall::Hall(int number_, int capacity_) 
    : number(number_), capacity(capacity_) {}

int Hall::getNumber() const { return number; }
int Hall::getCapacity() const { return capacity; }
int Hall::getTicketsSold() const { return ticketsSold; }

void Hall::setNumber(int number_) { number = number_; }

void Hall::setCapacity(int newCapacity) {
    if (newCapacity >= ticketsSold) {
        capacity = newCapacity;  
        std::cout << "[Успех]: Новая вместимость установлена: " << capacity << std::endl;
    } else {
        std::cout << "[Ошибка]: Вместимость не может быть меньше проданных билетов (" << ticketsSold << ")!\n";
    }
}

bool Hall::sellTickets(int count) {
    if (count <= 0) {
        std::cout << "\n[Ошибка]: Количество билетов должно быть больше 0!\n";
        return false;
    }

    if (ticketsSold + count > capacity) {
        std::cout << "\n[Ошибка вместимости]: Нельзя продать " << count 
                  << " билетов! Осталось мест: " << (capacity - ticketsSold) 
                  << " (Вместимость: " << capacity << ").\n";
        return false;
    }

    ticketsSold += count;
    std::cout << "\n[Успех]: Продано билетов: " << count 
              << ". Всего проданных: " << ticketsSold << "/" << capacity << "\n";
    return true;
}

bool Hall::addPerformance(const Performance& p) {
    size_t initialCount = performances.size();
    *this += p;
    return performances.size() > initialCount;
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
            std::cout << i + 1 << ". " << performances[i] << std::endl;
        }
    }
}

Hall& Hall::operator+=(const Performance& p) {
    int totalDuration = 0;
    for (const auto& existing : performances) {
        totalDuration += existing.getDuration();
    }

    if (totalDuration + p.getDuration() > 480) {
        std::cout << "\n[Ошибка +=]: Нельзя добавить \"" << p.getTitle() 
                  << "\". Превышен дневной лимит времени зала (480 мин)!\n"
                  << "Текущая суммарная длительность: " << totalDuration 
                  << " мин, пытаемся добавить: " << p.getDuration() << " мин.\n";
        return *this;
    }

    performances.push_back(p);
    std::cout << "\n[Успех +=]: Спектакль \"" << p.getTitle() << "\" добавлен в Зал №" << number << "!\n";
    return *this;
}

Hall& Hall::operator-=(const Performance& p) {
    bool found = false;
    for (auto it = performances.begin(); it != performances.end(); ++it) {
        if (*it == p) {
            performances.erase(it);
            std::cout << "\n[Успех -=]: Спектакль \"" << p.getTitle() << "\" удален из Зала №" << number << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "\n[Ошибка -=]: Спектакль \"" << p.getTitle() << "\" не найден в Зале №" << number << "!\n";
    }

    return *this;
}

void printHallAnalytics(const Hall& hall) {
    std::cout << "\n===== АНАЛИТИКА ЗАЛА №" << hall.number << " (через friend) =====" << std::endl;
    std::cout << "Загрузка зала: " << (hall.capacity > 0 ? (hall.ticketsSold * 100.0 / hall.capacity) : 0.0) << "%\n";
    std::cout << "Количество спектаклей: " << hall.performances.size() << std::endl;
    
    int totalMinutes = 0;
    for (const auto& p : hall.performances) {
        totalMinutes += p.getDuration();
    }
    std::cout << "Суммарная длительность репертуара: " << totalMinutes << " / 480 мин.\n";
    std::cout << "========================================================\n";
}