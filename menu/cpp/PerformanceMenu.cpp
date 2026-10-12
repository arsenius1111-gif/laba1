#include "PerformanceMenu.h"
#include "Ballet.h"
#include "Musical.h"
#include "Opera.h"
#include <iostream>
#include <limits>

void PerformanceMenu::showAll(
    const std::vector<Performance>& catalog) {
    std::cout << "\n========== КАТАЛОГ СПЕКТАКЛЕЙ ==========\n";

    if (catalog.empty()) {
        std::cout << "Каталог пуст.\n";
        return;
    }

    for (std::size_t i = 0; i < catalog.size(); ++i) {
        std::cout << "\n" << i + 1 << ".\n";
        std::cout << catalog[i];
    }
}

void PerformanceMenu::create(std::vector<Performance>& catalog) {
    Performance performance;

    std::cout << "\n========== ДОБАВЛЕНИЕ СПЕКТАКЛЯ ==========\n";

    if (!(std::cin >> performance)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Спектакль не добавлен.\n";
        return;
    }

    catalog.push_back(performance);
    std::cout << "Спектакль добавлен в каталог.\n";
}

void PerformanceMenu::compare(
    const std::vector<Performance>& catalog) {
    if (catalog.size() < 2) {
        std::cout << "Для сравнения нужны минимум два спектакля.\n";
        return;
    }

    showAll(catalog);

    int i1 = 0;
    int i2 = 0;

    std::cout << "\nВведите номер первого спектакля: ";
    if (!(std::cin >> i1)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода.\n";
        return;
    }

    std::cout << "Введите номер второго спектакля: ";
    if (!(std::cin >> i2)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода.\n";
        return;
    }

    if (i1 < 1 || i1 > static_cast<int>(catalog.size()) ||
        i2 < 1 || i2 > static_cast<int>(catalog.size())) {
        std::cout << "Указан неверный номер спектакля.\n";
        return;
    }

    const Performance& first = catalog[static_cast<std::size_t>(i1 - 1)];
    const Performance& second = catalog[static_cast<std::size_t>(i2 - 1)];

    std::cout << "\nРезультат сравнения:\n";

    if (first == second) {
        std::cout << "Спектакли имеют одинаковое название.\n";
    } else {
        std::cout << "Названия спектаклей различаются.\n";
    }

    if (first < second) {
        std::cout << "Первый спектакль короче второго.\n";
    } else if (first > second) {
        std::cout << "Первый спектакль длиннее второго.\n";
    } else {
        std::cout << "Длительности спектаклей равны.\n";
    }
}

void PerformanceMenu::showInheritanceDemo() {
    Ballet ballet(
        "Лебединое озеро", "Мариус Петипа", 140, 6, 24);
    Opera opera(
        "Евгений Онегин", "Константин Сергеев", 160, 12, true);
    Musical musical(
        "Чикаго", "Боб Фосси", 150, 16, true);

    bool running = true;

    while (running) {
        int choice = -1;

        std::cout << "\n========== ПРОСМОТР ТИПОВ СПЕКТАКЛЕЙ ==========\n";
        std::cout << "1. Балет\n";
        std::cout << "2. Опера\n";
        std::cout << "3. Мюзикл\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите тип спектакля: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число.\n";
            continue;
        }

        if (choice == 0) {
            running = false;
        } else if (choice == 1) {
            bool editing = true;

            while (editing) {
                int action = -1;

                std::cout << "\n========== БАЛЕТ ==========\n";
                ballet.displayBalletInfo();
                ballet.performDance();

                std::cout << "\n1. Изменить название\n";
                std::cout << "0. Назад\n";
                std::cout << "Выберите действие: ";

                if (!(std::cin >> action)) {
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода.\n";
                    continue;
                }

                if (action == 1) {
                    std::string title;

                    std::cout << "Введите новое название: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, title);

                    ballet.setTitle(title);
                    std::cout << "Название изменено.\n";
                } else if (action == 0) {
                    editing = false;
                } else {
                    std::cout << "Такого пункта меню нет.\n";
                }
            }
        } else if (choice == 2) {
            bool editing = true;

            while (editing) {
                int action = -1;

                std::cout << "\n========== ОПЕРА ==========\n";
                opera.displayOperaInfo();
                opera.performVocal();

                std::cout << "\n1. Изменить название\n";
                std::cout << "0. Назад\n";
                std::cout << "Выберите действие: ";

                if (!(std::cin >> action)) {
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода.\n";
                    continue;
                }

                if (action == 1) {
                    std::string title;

                    std::cout << "Введите новое название: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, title);

                    opera.setTitle(title);
                    std::cout << "Название изменено.\n";
                } else if (action == 0) {
                    editing = false;
                } else {
                    std::cout << "Такого пункта меню нет.\n";
                }
            }
        } else if (choice == 3) {
            bool editing = true;

            while (editing) {
                int action = -1;

                std::cout << "\n========== МЮЗИКЛ ==========\n";
                musical.displayMusicalInfo();
                musical.performMusicalNumber();

                std::cout << "\n1. Изменить название\n";
                std::cout << "0. Назад\n";
                std::cout << "Выберите действие: ";

                if (!(std::cin >> action)) {
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода.\n";
                    continue;
                }

                if (action == 1) {
                    std::string title;

                    std::cout << "Введите новое название: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, title);

                    musical.setTitle(title);
                    std::cout << "Название изменено.\n";
                } else if (action == 0) {
                    editing = false;
                } else {
                    std::cout << "Такого пункта меню нет.\n";
                }
            }
        } else {
            std::cout << "Такого пункта меню нет.\n";
        }
    }
}