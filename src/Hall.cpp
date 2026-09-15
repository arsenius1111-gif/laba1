#include "../include/Hall.h"
#include <iostream>

using namespace std;

Hall::Hall(int number_, int capacity_)
    : number(number_), capacity(capacity_) {}

void Hall::addPerformance(const Performance& performance) {
    performances.push_back(performance);
    soldTickets.push_back(0);
}

int Hall::getPerformanceCount() const {
    return static_cast<int>(performances.size());
}

Performance& Hall::getPerformance(int index) {
    return performances[index];
}

const Performance& Hall::getPerformance(int index) const {
    return performances[index];
}

int Hall::getSoldTickets(int index) const {
    return soldTickets[index];
}

int Hall::getNumber() const {
    return number;
}

int Hall::getCapacity() const {
    return capacity;
}

bool Hall::sellTickets(int performanceIndex, int count) {
    if (performanceIndex < 0 || performanceIndex >= static_cast<int>(performances.size())) {
        cout << "Ошибка! Такого спектакля нет.\n";
        return false;
    }

    if (count <= 0) {
        cout << "Ошибка! Количество билетов должно быть больше 0.\n";
        return false;
    }

    if (soldTickets[performanceIndex] + count > capacity) {
        cout << "Ошибка! Нельзя продать столько билетов.\n"
             << "Вместимость зала: " << capacity << "\n"
             << "Уже продано: " << soldTickets[performanceIndex] << "\n"
             << "Свободно: " << capacity - soldTickets[performanceIndex] << "\n";
        return false;
    }

    soldTickets[performanceIndex] += count;
    cout << "Билеты успешно проданы.\n";
    return true;
}

void Hall::printPerformances() const {
    if (performances.empty()) {
        cout << "В этом зале нет спектаклей.\n";
        return;
    }

    for (size_t i = 0; i < performances.size(); i++) {
        cout << "\nСпектакль №" << i + 1 << "\n";
        performances[i].printInfo();
        cout << "Продано билетов: " << soldTickets[i] << "\n"
             << "Свободных мест: " << capacity - soldTickets[i] << "\n";
    }
}

void Hall::printInfo() const {
    cout << "\n===== ИНФОРМАЦИЯ О ЗАЛЕ =====\n"
         << "Номер зала: " << number << "\n"
         << "Вместимость: " << capacity << "\n"
         << "Количество спектаклей: " << performances.size() << "\n";
}