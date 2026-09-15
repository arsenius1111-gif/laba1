#include "MainMenu.h"
#include "HallMenu.h"
#include <iostream>
#include <limits>

void runApplication(Hall& hall1, Hall& hall2) {
    while (true) {
        std::cout << "\n ГЛАВНОЕ МЕНЮ СИСТЕМЫ " << std::endl;
        std::cout << "1. Управление Залом №1" << std::endl;
        std::cout << "2. Управление Залом №2" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите вариант: ";

        int sc = 0;
        if (!(std::cin >> sc)) {
            std::cout << "Ошибка ввода! Введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (sc == 0) break;

        if (sc == 1) {
            runHallMenu(hall1);
        } else if (sc == 2) {
            runHallMenu(hall2);
        } else {
            std::cout << "Неверный вариант!" << std::endl;
        }
    }
}