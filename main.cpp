#include <iostream>
#include <vector>
#include "Performance.h"
#include "Hall.h"

void runLab1() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "   ДЕМОНСТРАЦИЯ ЛАБОРАТОРНОЙ РАБОТЫ №1" << std::endl;
    std::cout << "==========================================\n" << std::endl;

    std::vector<Hall> halls;
    halls.emplace_back(1, 100);
    halls.emplace_back(2, 50);

    Performance p1("Гамлет", "Шекспир", "Трагедия", 150, 16);
    Performance p2("Щелкунчик", "Чайковский", "Балет", 120, 6);

    std::cout << "1. Добавление спектаклей в залы:" << std::endl;
    halls[0].addPerformance(p1);
    halls[0].addPerformance(p2);

    std::cout << "\n2. Информация о залах и продажа билетов:" << std::endl;
    halls[0].displayFullInfo();

    std::cout << "\nПродажа 30 билетов в Зал №1:" << std::endl;
    halls[0].sellTickets(30);

    std::cout << "\nПопытка продать 80 билетов в Зал №1 (превышение вместимости):" << std::endl;
    halls[0].sellTickets(80);

    halls[0].displayFullInfo();
}

void runLab2() {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "   ДЕМОНСТРАЦИЯ ЛАБОРАТОРНОЙ РАБОТЫ №2" << std::endl;
    std::cout << "==========================================\n" << std::endl;

    Performance p1("Гамлет", "Шекспир", "Трагедия", 150, 16);
    Performance p2("Щелкунчик", "Чайковский", "Балет", 120, 6);
    Performance p3("Ревизор", "Гоголь", "Комедия", 250, 12);

    std::cout << "1. Перегрузка оператора вывода <<:" << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    std::cout << "\n2. Перегрузка операторов сравнения (==, <, >):" << std::endl;

    Performance p1_copy("Гамлет", "Неизвестен", "Драма", 100, 12);
    if (p1 == p1_copy) {
        std::cout << "[==] Спектакли равны по названию: \"" << p1.getTitle() << "\"" << std::endl;
    }

    if (p2 < p1) {
        std::cout << "[<] \"" << p2.getTitle() << "\" (" << p2.getDuration() 
                  << " мин) короче, чем \"" << p1.getTitle() << "\" (" << p1.getDuration() << " мин)" << std::endl;
    }

    if (p3 > p1) {
        std::cout << "[>] \"" << p3.getTitle() << "\" (" << p3.getDuration() 
                  << " мин) длиннее, чем \"" << p1.getTitle() << "\" (" << p1.getDuration() << " мин)" << std::endl;
    }

    std::cout << "\n3. Вызов дружественных функций (friend):" << std::endl;
    printPerformanceSecretDetails(p1);

    std::cout << "\n4. Перегрузка операторов += и -= для класса Hall:" << std::endl;
    Hall hall1(1, 100);

    hall1 += p1;
    hall1 += p2;

    std::cout << "\n[Проверка лимита 480 минут (попытка добавить 250 мин)]:" << std::endl;
    hall1 += p3;

    hall1.sellTickets(45);
    printHallAnalytics(hall1);

    std::cout << "\nУдаление спектакля через оператор -=:" << std::endl;
    hall1 -= p1;
    hall1 -= p3;
}

int main() {
    int choice = 0;

    while (true) {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "           ГЛАВНОЕ МЕНЮ СИСТЕМЫ" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "1. Продемонстрировать Лабораторную работу №1" << std::endl;
        std::cout << "2. Продемонстрировать Лабораторную работу №2" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите вариант: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода! Введите число 1, 2 или 0." << std::endl;
            continue;
        }

        if (choice == 1) {
            runLab1();
        } else if (choice == 2) {
            runLab2();
        } else if (choice == 0) {
            std::cout << "\nЗавершение работы программы..." << std::endl;
            break;
        } else {
            std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }
    }

    return 0;
}