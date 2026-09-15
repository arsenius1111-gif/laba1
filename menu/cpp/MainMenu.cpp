#include "../header/MainMenu.h"
#include "../header/HallMenu.h"
#include "../header/PerformanceMenu.h"
#include <iostream>
#include <sstream>
using namespace std;
int inputInt(string_view message) {
    string input;
    int number;
    char extra;
    while (true) {
        cout << message;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> number && !(ss >> extra)) return number;
        cout << "Ошибка! Введите целое число.\n";
    }
}
int inputPositiveInt(string_view message) {
    while (true) {
        int number = inputInt(message);
        if (number > 0) return number;
        cout << "Ошибка! Число должно быть больше 0.\n";
    }
}
string inputString(string_view message) {
    string value;
    while (true) {
        cout << message;
        getline(cin, value);
        if (!value.empty()) return value;
        cout << "Ошибка! Строка не должна быть пустой.\n";
    }
}
void printMainMenu() {
    cout << "\n========== МЕНЮ ==========\n"
         << "1. Показать информацию о зале\n"
         << "2. Показать спектакли\n"
         << "3. Продать билеты\n"
         << "4. Изменить данные спектакля\n"
         << "5. Получить характеристику спектакля\n"
         << "6. Показать полную информацию о спектакле\n"
         << "0. Выход\n"
         << "===========================\n";
}
void runApplication(Hall& hall1, Hall& hall2) {
    int choice;
    do {
        printMainMenu();
        choice = inputInt("Выберите пункт меню: ");
        Hall* selectedHall = nullptr;
        if (choice >= 1 && choice <= 6) {
            int hallNumber = inputInt("Введите номер зала (1 или 2): ");
            if (hallNumber == 1) selectedHall = &hall1;
            else if (hallNumber == 2) selectedHall = &hall2;
            else {
                cout << "Ошибка! Такого зала нет.\n";
                continue;
            }
        }
        switch (choice) {
            case 1: showHallInfo(selectedHall); break;
            case 2: showHallPerformances(selectedHall); break;
            case 3:
            case 4:
            case 5:
            case 6: handlePerformanceAction(selectedHall, choice); break;
            case 0: cout << "Программа завершена.\n"; break;
            default: cout << "Ошибка! Такого пункта меню нет.\n";
        }
    } while (choice != 0);
}