#include "PerformanceMenu.h"
#include "Ballet.h"
#include "Opera.h"
#include "Musical.h"
#include <iostream>

void PerformanceMenu::showAll(const std::vector<Performance>& catalog) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << "         КАТАЛОГ ВСЕХ СПЕКТАКЛЕЙ" << std::endl;
    std::cout << "==========================================" << std::endl;

    if (catalog.empty()) {
        std::cout << "Каталог спектаклей пуст.\n";
        return;
    }

    for (size_t i = 0; i < catalog.size(); ++i) {
        std::cout << i + 1 << ". " << catalog[i] << "\n";
    }
    std::cout << "------------------------------------------\n";
    std::cout << "Всего спектаклей в базе: " << catalog.size() << "\n";
}

void PerformanceMenu::create(std::vector<Performance>& catalog) {
    std::cout << "\n--- Добавление нового спектакля (operator>>) ---" << std::endl;
    Performance p;
    std::cin >> p;
    catalog.push_back(p);
    std::cout << "[Успех]: Спектакль \"" << p.getTitle() << "\" добавлен в базу!\n";
}

void PerformanceMenu::compare(const std::vector<Performance>& catalog) {
    if (catalog.size() < 2) {
        std::cout << "\n[Ошибка]: В базе должно быть минимум 2 спектакля!\n";
        return;
    }

    showAll(catalog);

    size_t i1 = 0;
    size_t i2 = 0;
    std::cout << "Выберите номер первого спектакля: ";
    std::cin >> i1;
    std::cout << "Выберите номер второго спектакля: ";
    std::cin >> i2;

    if (i1 < 1 || i1 > catalog.size() || i2 < 1 || i2 > catalog.size()) {
        std::cout << "Неверный выбор!\n";
        return;
    }

    const auto& p1 = catalog[i1 - 1];
    const auto& p2 = catalog[i2 - 1];

    std::cout << "\n--- Результаты сравнения ---" << std::endl;

    if (p1 == p2) {
        std::cout << "[operator==]: Спектакли одинаковы по названию (\"" << p1.getTitle() << "\")\n";
    } else {
        std::cout << "[operator==]: Названия спектаклей отличаются.\n";
    }

    if (p1 < p2) {
        std::cout << "[operator<]: \"" << p1.getTitle() << "\" (" << p1.getDuration() 
                  << " мин) короче, чем \"" << p2.getTitle() << "\" (" << p2.getDuration() << " мин)\n";
    } else if (p1 > p2) {
        std::cout << "[operator>]: \"" << p1.getTitle() << "\" (" << p1.getDuration() 
                  << " мин) длиннее, чем \"" << p2.getTitle() << "\" (" << p2.getDuration() << " мин)\n";
    } else {
        std::cout << "[operator<=>]: Спектакли равны по длительности.\n";
    }

    printPerformanceSecretDetails(p1);
}
void PerformanceMenu::showInheritanceDemo() {
    Performance performance(
        "Гамлет",
        "Уильям Шекспир",
        "Трагедия",
        150,
        16
    );

    Ballet ballet(
        "Лебединое озеро",
        "Мариус Петипа",
        140,
        6,
        24,
        4,
        60
    );

    Opera opera(
        "Евгений Онегин",
        "Константин Сергеев",
        160,
        12,
        "Баритон",
        35,
        3
    );

    Musical musical(
        "Чикаго",
        "Боб Фосси",
        150,
        16,
        12,
        8,
        true
    );

    std::cout << "\n========== НАСЛЕДОВАНИЕ ==========\n";

    std::cout << "\n--- Базовый класс Performance ---\n";
    performance.displayInfo();

    std::cout << "\n--- Производный класс Ballet ---\n";
    ballet.displayBalletInfo();

    std::cout << "\n--- Производный класс Opera ---\n";
    opera.displayOperaInfo();

    std::cout << "\n--- Производный класс Musical ---\n";
    musical.displayMusicalInfo();

    std::cout << "\n--- Унаследованные методы ---\n";
    std::cout << "Название балета: " << ballet.getTitle() << '\n';
    std::cout << "Режиссер оперы: " << opera.getDirector() << '\n';
    std::cout << "Длительность мюзикла: "
              << musical.getDuration() << " мин.\n";

    std::cout << "\n--- Специализированные методы ---\n";
    std::cout << "Количество танцоров в балете: "
              << ballet.getDancersCount() << '\n';
    std::cout << "Размер хора в опере: "
              << opera.getChorusSize() << '\n';
    std::cout << "Музыкальных номеров в мюзикле: "
              << musical.getMusicalNumbers() << '\n';
}