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

static void handleEditTitle(Performance& performance) {
    std::cout << "Введите новое название: ";
    std::string newTitle;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newTitle);
    performance.setTitle(newTitle);
    std::cout << "Название изменено!\n";
}

static void handleEditDuration(Performance& performance) {
    std::cout << "Введите новую длительность (мин): ";
    if (int newDur = 0; std::cin >> newDur && newDur > 0) {
        performance.setDuration(newDur);
        std::cout << "Длительность изменена!\n";
    } else {
        std::cout << "Некорректная длительность!\n";
    }
}

static void handlePerformanceChoice(Performance& performance, int choice, bool& running) {
    switch (choice) {
        case 0:
            running = false;
            break;
        case 1:
            performance.displayInfo();
            break;
        case 2:
            handleEditTitle(performance);
            break;
        case 3:
            handleEditDuration(performance);
            break;
        default:
            std::cout << "Неверный пункт!\n";
            break;
    }
}

void runPerformanceMenu(Performance& performance) {
    bool running = true;
    while (running) {
        std::cout << "\n--- Редактирование спектакля ---\n"
                  << "1. Показать данные\n"
                  << "2. Изменить название\n"
                  << "3. Изменить длительность\n"
                  << "0. Назад в меню зала\n"
                  << "Выберите вариант: ";

        if (int choice = 0; std::cin >> choice) {
            handlePerformanceChoice(performance, choice, running);
        } else {
            std::cout << "Ошибка ввода! Введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}