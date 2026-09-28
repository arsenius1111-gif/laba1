#include "MainMenu.h"
#include "PerformanceMenu.h"
#include "HallMenu.h"
#include <iostream>

MainMenu::MainMenu() {
    initDatabase();
}

void MainMenu::clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void MainMenu::initDatabase() {
    halls.emplace_back(1, 100);
    halls.emplace_back(2, 50);

    catalog.emplace_back("Гамлет", "Уильям Шекспир", "Трагедия", 150, 16);
    catalog.emplace_back("Щелкунчик", "Пётр Чайковский", "Балет", 120, 6);
    catalog.emplace_back("Ревизор", "Николай Гоголь", "Комедия", 140, 12);
    catalog.emplace_back("Мастер и Маргарита", "Михаил Булгаков", "Драма", 180, 16);

    halls[0] += catalog[0];
    halls[0] += catalog[1];
}

void MainMenu::run() {
    while (true) {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "       ГЛАВНОЕ МЕНЮ СИСТЕМЫ ТЕАТРА" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "1. Просмотреть все спектакли в базе\n";
        std::cout << "2. Управление залами и продажа билетов\n";
        std::cout << "3. Сравнить спектакли из базы (==, <=>, <, >)\n";
        std::cout << "4. Добавить новый спектакль в базу (operator>>)\n";
        std::cout << "5. Создать новый зал\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Ошибка ввода!\n";
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
        } else if (choice == 0) {
            std::cout << "Завершение работы программы...\n";
            break;
        } else {
            std::cout << "Неверный пункт меню!\n";
        }
    }
}