#include <string>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
#include <string_view>

using namespace std;

int inputInt(string_view message);
int inputPositiveInt(string_view message);
string inputString(string_view message);
void printMenu();

class Performance {
private:
    string title;
    string genre;
    string director;
    int duration;
    int ageLimit;

public:
    Performance(string_view title_, string_view director_, string_view genre_, 
                int duration_, int ageLimit_)
        : title(title_), director(director_), genre(genre_), 
          duration(duration_), ageLimit(ageLimit_)
    {
    }

    void setTitle(string_view title_) { this->title = title_; }
    void setDirector(string_view director_) { this->director = director_; }
    void setGenre(string_view genre_) { this->genre = genre_; }
    void setDuration(int duration_) { this->duration = duration_; }
    void setAgeLimit(int ageLimit_) { this->ageLimit = ageLimit_; }

    string getTitle() const { return title; }
    string getDirector() const { return director; }
    string getGenre() const { return genre; }
    int getDuration() const { return duration; }
    int getAgeLimit() const { return ageLimit; }

    void printInfo() const {
        cout << "Название: " << title << endl;
        cout << "Режиссёр: " << director << endl;
        cout << "Жанр: " << genre << endl;
        cout << "Продолжительность: " << duration << " мин." << endl;
        cout << "Возрастное ограничение: " << ageLimit << "+" << endl;
    }
};

class Hall {
private:
    int number;
    int capacity;
    vector<Performance> performances;
    vector<int> soldTickets;

public:
    Hall(int number_, int capacity_)
        : number(number_), capacity(capacity_)
    {
    }

    void addPerformance(const Performance& performance) {
        performances.push_back(performance);
        soldTickets.push_back(0);
    }

    int getPerformanceCount() const {
        return (int)performances.size();
    }

    const Performance& getPerformance(int index) const {
        return performances[index];
    }

    int getSoldTickets(int index) const {
        return soldTickets[index];
    }

    int getNumber() const {
        return number;
    }

    int getCapacity() const {
        return capacity;
    }

    bool sellTickets(int performanceIndex, int count) {
        if (performanceIndex < 0 || performanceIndex >= (int)performances.size()) {
            cout << "Ошибка! Такого спектакля нет.\n";
            return false;
        }

        if (count <= 0) {
            cout << "Ошибка! Количество билетов должно быть больше 0.\n";
            return false;
        }

        if (soldTickets[performanceIndex] + count > capacity) {
            cout << "Ошибка! Нельзя продать столько билетов.\n";
            cout << "Вместимость зала: " << capacity << endl;
            cout << "Уже продано: " << soldTickets[performanceIndex] << endl;
            cout << "Свободно: " << capacity - soldTickets[performanceIndex] << endl;
            return false;
        }

        soldTickets[performanceIndex] += count;
        cout << "Билеты успешно проданы.\n";
        return true;
    }

    void printPerformances() const {
        if (performances.empty()) {
            cout << "В этом зале нет спектаклей.\n";
            return;
        }

        for (int i = 0; i < (int)performances.size(); i++) {
            cout << "\nСпектакль №" << i + 1 << endl;
            performances[i].printInfo();
            cout << "Продано билетов: " << soldTickets[i] << endl;
            cout << "Свободных мест: " << capacity - soldTickets[i] << endl;
        }
    }

    void printInfo() const {
        cout << "\n===== ИНФОРМАЦИЯ О ЗАЛЕ =====\n";
        cout << "Номер зала: " << number << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество спектаклей: " << performances.size() << endl;
    }
};

int inputInt(string_view message) {
    string input;
    int number;
    char extra;

    while (true) {
        cout << message.data();
        getline(cin, input);

        if (stringstream ss(input); ss >> number && !(ss >> extra)) {
            return number;
        }

        cout << "Ошибка! Введите целое число.\n";
    }
}

int inputPositiveInt(string_view message) {
    int number;

    while (true) {
        number = inputInt(message);

        if (number > 0) {
            return number;
        }

        cout << "Ошибка! Число должно быть больше 0.\n";
    }
}

string inputString(string_view message) {
    string value;

    while (true) {
        cout << message.data();
        getline(cin, value);

        if (!value.empty()) {
            return value;
        }

        cout << "Ошибка! Строка не должна быть пустой.\n";
    }
}

void printMenu() {
    cout << "\n========== МЕНЮ ==========\n";
    cout << "1. Показать информацию о зале\n";
    cout << "2. Показать спектакли\n";
    cout << "3. Продать билеты\n";
    cout << "4. Изменить данные спектакля\n";
    cout << "5. Получить характеристику спектакля\n";
    cout << "6. Показать полную информацию о спектакле\n";
    cout << "0. Выход\n";
    cout << "===========================\n";
}

void handlePerformanceAction(Hall* selectedHall, int choice) {
    if (selectedHall->getPerformanceCount() == 0) {
        cout << "В зале нет спектаклей.\n";
        return;
    }

    selectedHall->printPerformances();
    int index = inputInt("\nВведите номер спектакля: ");

    if (index < 1 || index > selectedHall->getPerformanceCount()) {
        cout << "Ошибка! Неверный номер спектакля.\n";
        return;
    }

    index--;

    if (choice == 3) {
        int count = inputPositiveInt("Введите количество билетов: ");
        selectedHall->sellTickets(index, count);
    }
    else if (choice == 4) {
        cout << "\nЧто изменить?\n";
        cout << "1. Название\n";
        cout << "2. Режиссёр\n";
        cout << "3. Жанр\n";
        cout << "4. Продолжительность\n";
        cout << "5. Возрастное ограничение\n";

        int field = inputInt("Выберите характеристику: ");

        switch (field) {
        case 1:
            selectedHall->getPerformance(index).setTitle(inputString("Новое название: "));
            break;
        case 2:
            selectedHall->getPerformance(index).setDirector(inputString("Новый режиссёр: "));
            break;
        case 3:
            selectedHall->getPerformance(index).setGenre(inputString("Новый жанр: "));
            break;
        case 4:
            selectedHall->getPerformance(index).setDuration(inputPositiveInt("Новая продолжительность: "));
            break;
        case 5:
            selectedHall->getPerformance(index).setAgeLimit(inputPositiveInt("Новое возрастное ограничение: "));
            break;
        default:
            cout << "Ошибка! Неверный пункт.\n";
        }
    }
    else if (choice == 5) {
        cout << "\nЧто вывести?\n";
        cout << "1. Название\n";
        cout << "2. Режиссёр\n";
        cout << "3. Жанр\n";
        cout << "4. Продолжительность\n";
        cout << "5. Возрастное ограничение\n";

        int field = inputInt("Выберите характеристику: ");

        switch (field) {
        case 1:
            cout << "Название: " << selectedHall->getPerformance(index).getTitle() << endl;
            break;
        case 2:
            cout << "Режиссёр: " << selectedHall->getPerformance(index).getDirector() << endl;
            break;
        case 3:
            cout << "Жанр: " << selectedHall->getPerformance(index).getGenre() << endl;
            break;
        case 4:
            cout << "Продолжительность: " << selectedHall->getPerformance(index).getDuration() << " мин." << endl;
            break;
        case 5:
            cout << "Возрастное ограничение: " << selectedHall->getPerformance(index).getAgeLimit() << "+" << endl;
            break;
        default:
            cout << "Ошибка! Неверный пункт.\n";
        }
    }
    else if (choice == 6) {
        cout << "\n===== ПОЛНАЯ ИНФОРМАЦИЯ =====\n";
        selectedHall->getPerformance(index).printInfo();
        cout << "Продано билетов: " << selectedHall->getSoldTickets(index) << endl;
        cout << "Свободных мест: " << selectedHall->getCapacity() - selectedHall->getSoldTickets(index) << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Performance p1("Гамлет", "Сергей Иванов", "Драма", 180, 16);
    Performance p2("Ревизор", "Андрей Петров", "Комедия", 140, 12);
    Performance p3("Щелкунчик", "Елена Смирнова", "Балет", 120, 6);

    Hall hall1(1, 100);
    Hall hall2(2, 250);

    hall1.addPerformance(p1);
    hall1.addPerformance(p2);
    hall2.addPerformance(p3);

    int choice;

    do {
        printMenu();
        choice = inputInt("Выберите пункт меню: ");

        Hall* selectedHall = nullptr;

        if (choice >= 1 && choice <= 6) {
            int hallNumber = inputInt("Введите номер зала (1 или 2): ");

            if (hallNumber == 1)
                selectedHall = &hall1;
            else if (hallNumber == 2)
                selectedHall = &hall2;
            else {
                cout << "Ошибка! Такого зала нет.\n";
                continue;
            }
        }

        switch (choice) {
        case 1:
            selectedHall->printInfo();
            break;

        case 2:
            selectedHall->printPerformances();
            break;

        case 3:
        case 4:
        case 5:
        case 6:
            handlePerformanceAction(selectedHall, choice);
            break;

        case 0:
            cout << "Программа завершена.\n";
            break;

        default:
            cout << "Ошибка! Такого пункта меню нет.\n";
        }

    } while (choice != 0);

    return 0;
}