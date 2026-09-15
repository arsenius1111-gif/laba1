#include "Hall.h"
#include "Performance.h"
#include "menu/header/MainMenu.h"
int main() {
    Performance p1("Гамлет", "Шекспир У.", "Трагедия", 180, 16);
    Performance p2("Щелкунчик", "Иванов И.", "Балет", 120, 6);
    Performance p3("Ревизор", "Гоголь Н.", "Комедия", 150, 12);
    Hall hall1(1, 150);
    Hall hall2(2, 80);
    hall1.addPerformance(p1);
    hall1.addPerformance(p2);
    hall2.addPerformance(p3);
    runApplication(hall1, hall2);
    return 0;
}