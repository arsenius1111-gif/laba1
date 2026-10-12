#include "PerformanceMenu.h"
#include "Ballet.h"
#include "Musical.h"
#include "Opera.h"
#include <iostream>
#include <limits>
#include <string>

namespace {
    bool readChoice(int& choice) {
        if (std::cin >> choice) {
            return true;
        }

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Введите число.\n";
        return false;
    }

    void changeTitle(Performance& performance) {
        std::string title;

        std::cout << "Введите новое название: ";
        std::cin >> std::ws;
        std::getline(std::cin, title);

        if (title.empty()) {
            std::cout << "Название не может быть пустым.\n";
            return;
        }

        performance.setTitle(title);
        std::cout << "Название изменено.\n";
    }

    void showBallet() {
        Ballet ballet(
            "Лебединое озеро", "Мариус Петипа", 140, 6, 24);

        bool running = true;

        while (running) {
            std::cout << "\n========== БАЛЕТ ==========\n";
            ballet.displayBalletInfo();
            ballet.performDance();

            int choice = -1;
            std::cout << "\n1. Изменить название\n0. Назад\n";

            if (!readChoice(choice)) {
                continue;
            }

            switch (choice) {
            case 1:
                changeTitle(ballet);
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "Такого пункта меню нет.\n";
            }
        }
    }

    void showOpera() {
        Opera opera(
            "Евгений Онегин", "Константин Сергеев", 160, 12, true);

        bool running = true;

        while (running) {
            std::cout << "\n========== ОПЕРА ==========\n";
            opera.displayOperaInfo();
            opera.performVocal();

            int choice = -1;
            std::cout << "\n1. Изменить название\n0. Назад\n";

            if (!readChoice(choice)) {
                continue;
            }

            switch (choice) {
            case 1:
                changeTitle(opera);
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "Такого пункта меню нет.\n";
            }
        }
    }

    void showMusical() {
        Musical musical(
            "Чикаго", "Боб Фосси", 150, 16, true);

        bool running = true;

        while (running) {
            std::cout << "\n========== МЮЗИКЛ ==========\n";
            musical.displayMusicalInfo();
            musical.performMusicalNumber();

            int choice = -1;
            std::cout << "\n1. Изменить название\n0. Назад\n";

            if (!readChoice(choice)) {
                continue;
            }

            switch (choice) {
            case 1:
                changeTitle(musical);
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "Такого пункта меню нет.\n";
            }
        }
    }
}

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

    if (!readChoice(i1)) {
        return;
    }

    std::cout << "Введите номер второго спектакля: ";

    if (!readChoice(i2)) {
        return;
    }

    if (i1 < 1 || i1 > static_cast<int>(catalog.size()) || 
        i2 < 1 || i2 > static_cast<int>(catalog.size())) {
        std::cout << "Указан неверный номер спектакля.\n";
        return;
    }

    const Performance& first =
        catalog[static_cast<std::size_t>(i1 - 1)];
    const Performance& second =
        catalog[static_cast<std::size_t>(i2 - 1)];

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
    bool running = true;

    while (running) {
        int choice = -1;

        std::cout << "\n========== ПРОСМОТР ТИПОВ СПЕКТАКЛЕЙ ==========\n";
        std::cout << "1. Балет\n";
        std::cout << "2. Опера\n";
        std::cout << "3. Мюзикл\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите тип спектакля: ";

        if (!readChoice(choice)) {
            continue;
        }

        switch (choice) {
        case 1:
            showBallet();
            break;
        case 2:
            showOpera();
            break;
        case 3:
            showMusical();
            break;
        case 0:
            running = false;
            break;
        default:
            std::cout << "Такого пункта меню нет.\n";
        }
    }
}