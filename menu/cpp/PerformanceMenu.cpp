#include "PerformanceMenu.h"
#include <iostream>
#include <limits>
#include <string>
Performance createPerformanceFromInput() {
    std::string title;
    std::string director;
    std::string genre;
    int duration = 0;
    int age = 0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите название спектакля: ";
    std::getline(std::cin, title);
    std::cout << "Введите режиссера: ";
    std::getline(std::cin, director);
    std::cout << "Введите жанр: ";
    std::getline(std::cin, genre);
    std::cout << "Введите длительность (мин): ";
    while (!(std::cin >> duration) || duration <= 0) {
        std::cout << "Ошибка ввода! Введите число больше 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Введите возрастной ценз (0, 6, 12, 16, 18): ";
    while (!(std::cin >> age) || age < 0) {
        std::cout << "Ошибка ввода! Введите корректный возраст: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Performance(title, director, genre, duration, age);
}
void runPerformanceMenu(Performance& performance) {
    while (true) {
        std::cout << "\n--- Редактирование спектакля ---" << std::endl;
        std::cout << "1. Показать данные" << std::endl;
        std::cout << "2. Изменить название" << std::endl;
        std::cout << "3. Изменить длительность" << std::endl;
        std::cout << "0. Назад в меню зала" << std::endl;
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
            performance.displayInfo();
        } else if (choice == 2) {
            std::cout << "Введите новое название: ";
            std::string newTitle;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newTitle);
            performance.setTitle(newTitle);
            std::cout << "Название изменено!" << std::endl;
        } else if (choice == 3) {
            std::cout << "Введите новую длительность (мин): ";
            int newDur = 0;
            if (std::cin >> newDur && newDur > 0) {
                performance.setDuration(newDur);
                std::cout << "Длительность изменена!" << std::endl;
            } else {
                std::cout << "Некорректная длительность!" << std::endl;
            }
        } else {
            std::cout << "Неверный пункт!" << std::endl;
        }
    }
}