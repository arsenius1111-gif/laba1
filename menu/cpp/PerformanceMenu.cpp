#include "PerformanceMenu.h"
#include "Ballet.h"
#include "Musical.h"
#include "Opera.h"
#include <iostream>
#include <limits>
#include <memory>
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

    std::shared_ptr<Performance> createPerformance() {
        int type = 0;

        std::cout << "\nВыберите тип спектакля:\n";
        std::cout << "1. Балет\n";
        std::cout << "2. Опера\n";
        std::cout << "3. Мюзикл\n";
        std::cout << "Ваш выбор: ";

        if (!readChoice(type)) {
            return nullptr;
        }

        std::string title;
        std::string director;
        int duration = 0;
        int ageRestriction = 0;

        std::cout << "Введите название: ";
        std::cin >> std::ws;
        std::getline(std::cin, title);

        if (title.empty()) {
            std::cout << "Название не может быть пустым.\n";
            return nullptr;
        }

        std::cout << "Введите режиссёра: ";
        std::getline(std::cin, director);

        if (director.empty()) {
            std::cout << "Режиссёр не может быть пустым.\n";
            return nullptr;
        }

        std::cout << "Введите длительность в минутах: ";

        if (!readChoice(duration) || duration <= 0) {
            std::cout << "Длительность должна быть положительной.\n";
            return nullptr;
        }

        std::cout << "Введите возрастное ограничение: ";

        if (!readChoice(ageRestriction) || ageRestriction < 0) {
            std::cout << "Возрастное ограничение не может быть отрицательным.\n";
            return nullptr;
        }

        switch (type) {
        case 1: {
            int dancersCount = 0;
            int actsCount = 0;
            int orchestraSize = 0;

            std::cout << "Введите количество танцоров: ";
            if (!readChoice(dancersCount) || dancersCount <= 0) {
                std::cout << "Количество танцоров должно быть положительным.\n";
                return nullptr;
            }

            std::cout << "Введите количество актов: ";
            if (!readChoice(actsCount) || actsCount <= 0) {
                std::cout << "Количество актов должно быть положительным.\n";
                return nullptr;
            }

            std::cout << "Введите размер оркестра: ";
            if (!readChoice(orchestraSize) || orchestraSize < 0) {
                std::cout << "Размер оркестра не может быть отрицательным.\n";
                return nullptr;
            }

            return std::make_shared<Ballet>(
                title, director, duration, ageRestriction,
                dancersCount, actsCount, orchestraSize);
        }

        case 2: {
            int recitatives = 0;

            std::cout << "Есть ли речитативы? (1 — да, 0 — нет): ";
            if (!readChoice(recitatives) ||
                (recitatives != 0 && recitatives != 1)) {
                std::cout << "Введите 1 или 0.\n";
                return nullptr;
            }

            return std::make_shared<Opera>(
                title, director, duration, ageRestriction,
                recitatives == 1);
        }

        case 3: {
            int liveBand = 0;

            std::cout << "Есть ли живая музыкальная группа? (1 — да, 0 — нет): ";
            if (!readChoice(liveBand) ||
                (liveBand != 0 && liveBand != 1)) {
                std::cout << "Введите 1 или 0.\n";
                return nullptr;
            }

            return std::make_shared<Musical>(
                title, director, duration, ageRestriction,
                liveBand == 1);
        }

        default:
            std::cout << "Такого типа спектакля нет.\n";
            return nullptr;
        }
    }

    void showBallet() {
        Ballet ballet(
            "Лебединое озеро", "Мариус Петипа",
            140, 6, 24, 4, 30);

        bool running = true;

        while (running) {
            std::cout << "\n========== БАЛЕТ ==========\n";
            ballet.displayInfo();
            ballet.performSpecialAction();

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
            "Евгений Онегин", "Константин Сергеев",
            160, 12, true);

        bool running = true;

        while (running) {
            std::cout << "\n========== ОПЕРА ==========\n";
            opera.displayInfo();
            opera.performSpecialAction();

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
            musical.displayInfo();
            musical.performSpecialAction();

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
    const std::vector<std::shared_ptr<Performance>>& catalog) {
    std::cout << "\n========== КАТАЛОГ СПЕКТАКЛЕЙ ==========\n";

    if (catalog.empty()) {
        std::cout << "Каталог пуст.\n";
        return;
    }

    for (std::size_t i = 0; i < catalog.size(); ++i) {
        std::cout << "\n" << i + 1 << ".\n";

        if (catalog[i]) {
            catalog[i]->displayInfo();
        }
    }
}

void PerformanceMenu::create(
    std::vector<std::shared_ptr<Performance>>& catalog) {
    std::cout << "\n========== ДОБАВЛЕНИЕ СПЕКТАКЛЯ ==========\n";

    std::shared_ptr<Performance> performance = createPerformance();

    if (!performance) {
        std::cout << "Спектакль не добавлен.\n";
        return;
    }

    catalog.push_back(std::move(performance));
    std::cout << "Спектакль добавлен в каталог.\n";
}

void PerformanceMenu::compare(
    const std::vector<std::shared_ptr<Performance>>& catalog) {
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

    const auto& first = catalog[static_cast<std::size_t>(i1 - 1)];
    const auto& second = catalog[static_cast<std::size_t>(i2 - 1)];

    if (!first || !second) {
        std::cout << "Не удалось сравнить спектакли.\n";
        return;
    }

    std::cout << "\nРезультат сравнения:\n";

    if (*first == *second) {
        std::cout << "Спектакли имеют одинаковое название.\n";
    } else {
        std::cout << "Названия спектаклей различаются.\n";
    }

    if (*first < *second) {
        std::cout << "Первый спектакль короче второго.\n";
    } else if (*first > *second) {
        std::cout << "Первый спектакль длиннее второго.\n";
    } else {
        std::cout << "Длительности спектаклей равны.\n";
    }
}

void PerformanceMenu::showInheritanceDemo() {
    std::vector<std::shared_ptr<Performance>> performances;

    performances.push_back(std::make_shared<Ballet>(
        "Лебединое озеро", "Мариус Петипа",
        140, 6, 24, 4, 30));

    performances.push_back(std::make_shared<Opera>(
        "Евгений Онегин", "Константин Сергеев",
        160, 12, true));

    performances.push_back(std::make_shared<Musical>(
        "Чикаго", "Боб Фосси", 150, 16, true));

    std::cout << "\n========== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ==========\n";

    for (const auto& performance : performances) {
        std::cout << "\nТип: " << performance->getType() << '\n';
        performance->displayInfo();
        performance->performSpecialAction();
        std::cout << "----------------------------------------\n";
    }
}