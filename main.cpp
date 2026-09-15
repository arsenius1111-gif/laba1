#include "include/Performance.h"
#include "include/Hall.h"
#include "menu/header/MainMenu.h"
int main() {
    Performance p1("Гамлет", "Сергей Иванов", "Драма", 180, 16);
    Performance p2("Ревизор", "Андрей Петров", "Комедия", 140, 12);
    Performance p3("Щелкунчик", "Елена Смирнова", "Балет", 120, 6);
    Hall hall1(1, 100);
    Hall hall2(2, 250);
    hall1.addPerformance(p1);
    hall1.addPerformance(p2);
    hall2.addPerformance(p3);
    runApplication(hall1, hall2);
    return 0;
}