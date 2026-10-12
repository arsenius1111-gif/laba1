#include "HallMenu.h"
#include <iostream>
#include <limits>

namespace {
    bool selectHall(const std::vector<Hall>& halls, int& index) {
        if (halls.empty()) {
            std::cout << "Залов пока нет.\n";
            return false;
        }

        std::cout << "\nДоступные залы:\n";

        for (std::size_t i = 0; i < halls.size(); ++i) {
            std::cout << i + 1 << ". Зал №"
                      << halls[i].getNumber()
                      << ", вместимость: "
                      << halls[i].getCapacity() << '\n';
        }

        std::cout << "Выберите номер зала: ";

        if (!(std::cin >> index)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число.\n";
            return false;
        }

        if (index < 1 || index > static_cast<int>(halls.size())) {
            std::cout << "Такого зала нет.\n";
            return false;
        }

        --index;
        return true;
    }

    bool selectPerformance(
        const std::vector<Performance>& catalog, int& index) {
        if (catalog.empty()) {
            std::cout << "Каталог спектаклей пуст.\n";
            return false;
        }

        std::cout << "\nКаталог спектаклей:\n";

        for (std::size_t i = 0; i < catalog.size(); ++i) {
            std::cout << i + 1 << ". "
                      << catalog[i].getTitle() << " — "
                      << catalog[i].getDuration() << " мин.\n";
        }

        std::cout << "Выберите номер спектакля: ";

        if (!(std::cin >> index)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число.\n";
            return false;
        }

        if (index < 1 || index > static_cast<int>(catalog.size())) {
            std::cout << "Такого спектакля нет.\n";
            return false;
        }

        --index;
        return true;
    }
}

void HallMenu::create(std::vector<Hall>& halls) {
    int number = 0;
    int capacity = 0;

    std::cout << "\n========== СОЗДАНИЕ ЗАЛА ==========\n";
    std::cout << "Введите номер зала: ";

    if (!(std::cin >> number)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода.\n";
        return;
    }

    if (number <= 0) {
        std::cout << "Номер зала должен быть положительным.\n";
        return;
    }

    for (const Hall& hall : halls) {
        if (hall.getNumber() == number) {
            std::cout << "Зал с таким номером уже существует.\n";
            return;
        }
    }

    std::cout << "Введите вместимость зала: ";

    if (!(std::cin >> capacity)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода.\n";
        return;
    }

    if (capacity <= 0) {
        std::cout << "Вместимость должна быть положительной.\n";
        return;
    }

    halls.emplace_back(number, capacity);
    std::cout << "Зал успешно создан.\n";
}

void HallMenu::manage(
    std::vector<Hall>& halls,
    const std::vector<Performance>& catalog) {
    int hallIndex = 0;

    if (!selectHall(halls, hallIndex)) {
        return;
    }

    Hall& hall = halls[static_cast<std::size_t>(hallIndex)];
    bool running = true;

    while (running) {
        int choice = -1;

        std::cout << "\n========== УПРАВЛЕНИЕ ЗАЛОМ №"
                  << hall.getNumber() << " ==========\n";
        std::cout << "1. Показать информацию о зале\n";
        std::cout << "2. Продать билеты\n";
        std::cout << "3. Добавить спектакль в репертуар\n";
        std::cout << "4. Удалить спектакль из репертуара\n";
        std::cout << "5. Изменить вместимость зала\n";
        std::cout << "6. Аналитика зала\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число.\n";
            continue;
        }

        if (choice == 1) {
            hall.displayFullInfo();
        } else if (choice == 2) {
            int count = 0;

            std::cout << "Сколько билетов продать: ";

            if (!(std::cin >> count)) {
                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода.\n";
                continue;
            }

            hall.sellTickets(count);
        } else if (choice == 3) {
            int performanceIndex = 0;

            if (selectPerformance(catalog, performanceIndex)) {
                hall += catalog[
                    static_cast<std::size_t>(performanceIndex)];
            }
        } else if (choice == 4) {
            const std::vector<Performance>& performances =
                hall.getPerformances();

            if (performances.empty()) {
                std::cout << "Репертуар пуст.\n";
                continue;
            }

            std::cout << "\nРепертуар зала:\n";

            for (std::size_t i = 0; i < performances.size(); ++i) {
                std::cout << i + 1 << ". "
                          << performances[i].getTitle() << '\n';
            }

            int performanceIndex = 0;
            std::cout << "Выберите номер спектакля для удаления: ";

            if (!(std::cin >> performanceIndex)) {
                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода.\n";
                continue;
            }

            if (performanceIndex < 1 ||
                performanceIndex > static_cast<int>(performances.size())) {
                std::cout << "Указан неверный номер спектакля.\n";
                continue;
            }

            hall -= performances[
                static_cast<std::size_t>(performanceIndex - 1)];
        } else if (choice == 5) {
            int capacity = 0;

            std::cout << "Введите новую вместимость: ";

            if (!(std::cin >> capacity)) {
                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода.\n";
                continue;
            }

            hall.setCapacity(capacity);
        } else if (choice == 6) {
            printHallAnalytics(hall);
        } else if (choice == 0) {
            running = false;
        } else {
            std::cout << "Такого пункта меню нет.\n";
        }
    }
}