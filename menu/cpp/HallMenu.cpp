#include "HallMenu.h"
#include "PerformanceMenu.h"
#include <iostream>
#include <limits>
void runHallMenu(Hall& hall) {
    while (true) {
        std::cout << "\n=== Управление Залом №" << hall.getNumber() << " ===" << std::endl;
        std::cout << "1. Показать полную информацию" << std::endl;
        std::cout << "2. Добавить новый спектакль (с проверкой лимита)" << std::endl;
        std::cout << "3. Редактировать спектакль" << std::endl;
        std::cout << "4. Изменить вместимость зала" << std::endl;
        std::cout << "0. Назад в главное меню" << std::endl;
        std::cout << "Выберите вариант: ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice == 0) break;
        if (choice == 1) {
            hall.displayFullInfo();
        } else if (choice == 2) {
            Performance p = createPerformanceFromInput();
            hall.addPerformance(p);
        } else if (choice == 3) {
            auto& list = hall.getPerformances();
            if (list.empty()) {
                std::cout << "В зале пока нет спектаклей!" << std::endl;
            } else {
                hall.displayFullInfo();
                std::cout << "Выберите номер спектакля для изменения: ";
                size_t index = 0;
                if (std::cin >> index && index > 0 && index <= list.size()) {
                    runPerformanceMenu(list[index - 1]);
                } else {
                    std::cout << "Неверный номер!" << std::endl;
                }
            }
        } else if (choice == 4) {
            std::cout << "Введите новую вместимость: ";
            int newCap = 0;
            if (std::cin >> newCap && newCap > 0) {
                hall.setCapacity(newCap);
                std::cout << "Вместимость обновлена!" << std::endl;
            } else {
                std::cout << "Некорректная вместимость!" << std::endl;
            }
        } else {
            std::cout << "Неверный вариант!" << std::endl;
        }
    }
}