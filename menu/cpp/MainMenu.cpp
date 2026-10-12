#include "MainMenu.h"
#include "HallMenu.h"
#include "PerformanceMenu.h"
#include <iostream>

MainMenu::MainMenu() {
    initDatabase();
}

void MainMenu::clearInput() const {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void MainMenu::initDatabase() {
    halls.emplace_back(1, 100);
    halls.emplace_back(2, 50);

    catalog.emplace_back(
        "Гамлет", "Уильям Шекспир", "Трагедия", 150, 16);
    catalog.emplace_back(
        "Щелкунчик", "Пётр Чайковский", "Балет", 120, 6);
    catalog.emplace_back(
        "Ревизор", "Николай Гоголь", "Комедия", 140, 12);
    catalog.emplace_back(
        "Мастер и Маргарита", "Михаил Булгаков", "Драма", 180, 16);

    halls[0] += catalog[0];
    halls[0] += catalog[1];
}

void MainMenu::run() {
    bool running = true;

    while (running) {
        int choice = -1;

        std::cout << "\n========== ТЕАТР ==========\n";
        std::cout << "1. Просмотреть каталог спектаклей\n";
        std::cout << "2. Управление залами\n";
        std::cout << "3. Сравнить спектакли\n";
        std::cout << "4. Добавить спектакль в каталог\n";
        std::cout << "5. Создать зал\n";
        std::cout << "6. Просмотр типов спектаклей\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Ошибка ввода. Введите число.\n";
            continue;
        }

        if (choice == 1) {
            PerformanceMenu::showAll(catalog);
        } else if (choice == 2) {
            HallMenu::manage(halls, catalog);
        } else if (choice == 3) {
            PerformanceMenu::compare(catalog);
        } else if (choice == 4) {
            PerformanceMenu::create(catalog);
        } else if (choice == 5) {
            HallMenu::create(halls);
        } else if (choice == 6) {
            PerformanceMenu::showInheritanceDemo();
        } else if (choice == 0) {
            running = false;
            std::cout << "Программа завершена.\n";
        } else {
            std::cout << "Такого пункта меню нет.\n";
        }
    }
}