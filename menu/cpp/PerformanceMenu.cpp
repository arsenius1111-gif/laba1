#include "../header/PerformanceMenu.h"
#include "../header/MainMenu.h"
#include <iostream>

using namespace std;

void handlePerformanceAction(Hall* selectedHall, int choice) {
    if (!selectedHall || selectedHall->getPerformanceCount() == 0) {
        cout << "В зале нет спектаклей.\n";
        return;
    }

    selectedHall->printPerformances();
    int index = inputInt("\nВведите номер спектакля: ");

    if (index < 1 || index > selectedHall->getPerformanceCount()) {
        cout << "Ошибка! Неверный номер спектакля.\n";
        return;
    }
    index--;

    if (choice == 3) {
        int count = inputPositiveInt("Введите количество билетов: ");
        selectedHall->sellTickets(index, count);
    }
    else if (choice == 4) {
        cout << "\nЧто изменить?\n"
             << "1. Название\n"
             << "2. Режиссёр\n"
             << "3. Жанр\n"
             << "4. Продолжительность\n"
             << "5. Возрастное ограничение\n";

        int field = inputInt("Выберите характеристику: ");
        switch (field) {
            case 1: selectedHall->getPerformance(index).setTitle(inputString("Новое название: ")); break;
            case 2: selectedHall->getPerformance(index).setDirector(inputString("Новый режиссёр: ")); break;
            case 3: selectedHall->getPerformance(index).setGenre(inputString("Новый жанр: ")); break;
            case 4: selectedHall->getPerformance(index).setDuration(inputPositiveInt("Новая продолжительность: ")); break;
            case 5: selectedHall->getPerformance(index).setAgeLimit(inputPositiveInt("Новое возрастное ограничение: ")); break;
            default: cout << "Ошибка! Неверный пункт.\n";
        }
    }
    else if (choice == 5) {
        cout << "\nЧто вывести?\n"
             << "1. Название\n"
             << "2. Режиссёр\n"
             << "3. Жанр\n"
             << "4. Продолжительность\n"
             << "5. Возрастное ограничение\n";

        int field = inputInt("Выберите характеристику: ");
        switch (field) {
            case 1: cout << "Название: " << selectedHall->getPerformance(index).getTitle() << "\n"; break;
            case 2: cout << "Режиссёр: " << selectedHall->getPerformance(index).getDirector() << "\n"; break;
            case 3: cout << "Жанр: " << selectedHall->getPerformance(index).getGenre() << "\n"; break;
            case 4: cout << "Продолжительность: " << selectedHall->getPerformance(index).getDuration() << " мин.\n"; break;
            case 5: cout << "Возрастное ограничение: " << selectedHall->getPerformance(index).getAgeLimit() << "+\n"; break;
            default: cout << "Ошибка! Неверный пункт.\n";
        }
    }
    else if (choice == 6) {
        cout << "\n===== ПОЛНАЯ ИНФОРМАЦИЯ =====\n";
        selectedHall->getPerformance(index).printInfo();
        cout << "Продано билетов: " << selectedHall->getSoldTickets(index) << "\n"
             << "Свободных мест: " << selectedHall->getCapacity() - selectedHall->getSoldTickets(index) << "\n";
    }
}