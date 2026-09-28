#include "HallMenu.h"
#include "PerformanceMenu.h"
#include <iostream>

void HallMenu::create(std::vector<Hall>& halls) {
    int num = 0;
    int cap = 0;
    std::cout << "\n--- Создание нового зала ---" << std::endl;
    std::cout << "Введите номер зала: ";
    if (!(std::cin >> num)) return;
    std::cout << "Введите вместимость зала: ";
    if (!(std::cin >> cap)) return;

    halls.emplace_back(num, cap);
    std::cout << "[Успех]: Зал №" << num << " успешно создан!\n";
}

void HallMenu::manage(std::vector<Hall>& halls, const std::vector<Performance>& catalog) {
    if (halls.empty()) {
        std::cout << "\n[Инфо]: Залы еще не созданы!\n";
        return;
    }

    std::cout << "\nСписок доступных залов:\n";
    for (size_t i = 0; i < halls.size(); ++i) {
        std::cout << i + 1 << ". Зал №" << halls[i].getNumber() 
                  << " (Вместимость: " << halls[i].getCapacity() << ")\n";
    }

    std::cout << "Выберите зал (1 - " << halls.size() << "): ";
    size_t idx = 0;
    if (!(std::cin >> idx) || idx < 1 || idx > halls.size()) {
        std::cout << "Неверный выбор зала!\n";
        return;
    }

    Hall& currentHall = halls[idx - 1];

    while (true) {
        std::cout << "\n--- Управление Залом №" << currentHall.getNumber() << " ---" << std::endl;
        std::cout << "1. Показать информацию о зале\n";
        std::cout << "2. Изменить вместимость зала (сеттер)\n";
        std::cout << "3. Продать билеты (с проверкой)\n";
        std::cout << "4. Добавить спектакль из базы в зал (operator+=)\n";
        std::cout << "5. Удалить спектакль из зала (operator-=)\n";
        std::cout << "6. Показать аналитику зала (friend-функция)\n";
        std::cout << "0. Назад в главное меню\n";
        std::cout << "Выбор: ";

        int choice = 0;
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            currentHall.displayFullInfo();
        } else if (choice == 2) {
            int newCap = 0;
            std::cout << "Введите новую вместимость: ";
            std::cin >> newCap;
            currentHall.setCapacity(newCap);
        } else if (choice == 3) {
            int count = 0;
            std::cout << "Сколько билетов продать: ";
            std::cin >> count;
            currentHall.sellTickets(count);
        } else if (choice == 4) {
            PerformanceMenu::showAll(catalog);
            std::cout << "Выберите номер спектакля для добавления: ";
            size_t pIdx = 0;
            std::cin >> pIdx;
            if (pIdx >= 1 && pIdx <= catalog.size()) {
                currentHall += catalog[pIdx - 1];
            }
        } else if (choice == 5) {
            const auto& perfs = currentHall.getPerformances();
            if (perfs.empty()) {
                std::cout << "В этом зале нет спектаклей!\n";
                continue;
            }
            std::cout << "\nСпектакли в зале:\n";
            for (size_t i = 0; i < perfs.size(); ++i) {
                std::cout << i + 1 << ". " << perfs[i].getTitle() << "\n";
            }
            std::cout << "Выберите номер для удаления: ";
            size_t pIdx = 0;
            std::cin >> pIdx;
            if (pIdx >= 1 && pIdx <= perfs.size()) {
                currentHall -= perfs[pIdx - 1];
            }
        } else if (choice == 6) {
            printHallAnalytics(currentHall);
        } else if (choice == 0) {
            break;
        }
    }
}