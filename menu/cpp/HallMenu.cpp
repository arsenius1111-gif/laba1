#include "HallMenu.h"
#include "PerformanceMenu.h"
#include <iostream>
#include <limits>

void displayHallMenu(const Hall* selectedHall) {
    if (selectedHall != nullptr) {
        selectedHall->displayFullInfo();
    }
}

static void handleEditPerformance(Hall& hall) {
    auto& list = hall.getPerformances();
    if (list.empty()) {
        std::cout << "В зале пока нет спектаклей!\n";
        return;
    }
    hall.displayFullInfo();
    std::cout << "Выберите номер спектакля: ";
    if (int number = 0; std::cin >> number && number > 0 && static_cast<size_t>(number) <= list.size()) {
        runPerformanceMenu(list[static_cast<size_t>(number) - 1]);
    } else {
        std::cout << "Неверный номер!\n";
    }
}

static void handleSetCapacity(Hall& hall) {
    std::cout << "Введите новую вместимость: ";
    if (int newCap = 0; std::cin >> newCap && newCap > 0) {
        hall.setCapacity(newCap);
        std::cout << "Вместимость обновлена!\n";
    } else {
        std::cout << "Некорректная вместимость!\n";
    }
}

static void handleMenuChoice(Hall& hall, int choice, bool& running) {
    switch (choice) {
        case 0:
            running = false;
            break;
        case 1:
            hall.displayFullInfo();
            break;
        case 2: {
            Performance p = createPerformanceFromInput();
            hall.addPerformance(p);
            break;
        }
        case 3:
            handleEditPerformance(hall);
            break;
        case 4:
            handleSetCapacity(hall);
            break;
        default:
            std::cout << "Неверный вариант!\n";
            break;
    }
}

void runHallMenu(Hall& hall) {
    bool running = true;
    while (running) {
        std::cout << "\n=== Управление Залом №" << hall.getNumber() << " ===\n"
                  << "1. Показать полную информацию\n"
                  << "2. Добавить новый спектакль\n"
                  << "3. Редактировать спектакль\n"
                  << "4. Изменить вместимость зала\n"
                  << "0. Назад в главное меню\n"
                  << "Выберите вариант: ";

        if (int choice = 0; std::cin >> choice) {
            handleMenuChoice(hall, choice, running);
        } else {
            std::cout << "Ошибка ввода! Введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}