#include "HallMenu.h"
#include "PerformanceMenu.h"
#include <iostream>

namespace {
bool selectHall(std::vector<Hall>& halls, size_t& index) {
    std::cout << "\nСписок доступных залов:\n";

    for (size_t i = 0; i < halls.size(); ++i) {
        std::cout << i + 1 << ". Зал №" << halls[i].getNumber()
                  << " (Вместимость: " << halls[i].getCapacity() << ")\n";
    }

    std::cout << "Выберите зал (1 - " << halls.size() << "): ";

    if (!(std::cin >> index) || index < 1 || index > halls.size()) {
        std::cout << "Неверный выбор зала!\n";
        return false;
    }

    --index;
    return true;
}

void addPerformanceToHall(Hall& hall, const std::vector<Performance>& catalog) {
    PerformanceMenu::showAll(catalog);

    std::cout << "Выберите номер спектакля для добавления: ";

    size_t index = 0;

    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка ввода!\n";
        return;
    }

    if (index >= 1 && index <= catalog.size()) {
        hall += catalog[index - 1];
    } else {
        std::cout << "Неверный номер спектакля!\n";
    }
}

void removePerformanceFromHall(Hall& hall) {
    const auto& performances = hall.getPerformances();

    if (performances.empty()) {
        std::cout << "В этом зале нет спектаклей!\n";
        return;
    }

    std::cout << "\nСпектакли в зале:\n";

    for (size_t i = 0; i < performances.size(); ++i) {
        std::cout << i + 1 << ". " << performances[i].getTitle() << "\n";
    }

    std::cout << "Выберите номер для удаления: ";

    size_t index = 0;

    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка ввода!\n";
        return;
    }

    if (index >= 1 && index <= performances.size()) {
        hall -= performances[index - 1];
    } else {
        std::cout << "Неверный номер спектакля!\n";
    }
}

void handleHallChoice(
    int choice,
    Hall& hall,
    const std::vector<Performance>& catalog,
    bool& running
) {
    if (choice == 1) {
        hall.displayFullInfo();
    } else if (choice == 2) {
        int newCapacity = 0;
        std::cout << "Введите новую вместимость: ";

        if (std::cin >> newCapacity) {
            hall.setCapacity(newCapacity);
        } else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода!\n";
        }
    } else if (choice == 3) {
        int count = 0;
        std::cout << "Сколько билетов продать: ";

        if (std::cin >> count) {
            hall.sellTickets(count);
        } else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода!\n";
        }
    } else if (choice == 4) {
        addPerformanceToHall(hall, catalog);
    } else if (choice == 5) {
        removePerformanceFromHall(hall);
    } else if (choice == 6) {
        printHallAnalytics(hall);
    } else if (choice == 0) {
        running = false;
    } else {
        std::cout << "Неверный пункт меню!\n";
    }
}

void printHallMenu(const Hall& hall) {
    std::cout << "\n--- Управление Залом №" << hall.getNumber() << " ---" << std::endl;
    std::cout << "1. Показать информацию о зале\n";
    std::cout << "2. Изменить вместимость зала (сеттер)\n";
    std::cout << "3. Продать билеты (с проверкой)\n";
    std::cout << "4. Добавить спектакль из базы в зал (operator+=)\n";
    std::cout << "5. Удалить спектакль из зала (operator-=)\n";
    std::cout << "6. Показать аналитику зала (friend-функция)\n";
    std::cout << "0. Назад в главное меню\n";
    std::cout << "Выбор: ";
}
}

void HallMenu::create(std::vector<Hall>& halls) {
    int number = 0;
    int capacity = 0;

    std::cout << "\n--- Создание нового зала ---" << std::endl;
    std::cout << "Введите номер зала: ";

    if (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка ввода!\n";
        return;
    }

    std::cout << "Введите вместимость зала: ";
    if (!(std::cin >> capacity)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка ввода!\n";
        return;
    }

    if (number <= 0 || capacity <= 0) {
        std::cout << "Номер и вместимость должны быть больше 0!\n";
        return;
    }

    halls.emplace_back(number, capacity);

    std::cout << "[Успех]: Зал №" << number << " успешно создан!\n";
}

void HallMenu::manage(
    std::vector<Hall>& halls,
    const std::vector<Performance>& catalog
) {
    if (halls.empty()) {
        std::cout << "\n[Инфо]: Залы еще не созданы!\n";
        return;
    }

    size_t index = 0;

    if (!selectHall(halls, index)) {
        return;
    }

    Hall& currentHall = halls[index];
    bool running = true;

    while (running) {
        printHallMenu(currentHall);

        int choice = 0;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода!\n";
            continue;
        }

        handleHallChoice(choice, currentHall, catalog, running);
    }
}