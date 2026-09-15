#include "../header/HallMenu.h"
void showHallInfo(Hall* selectedHall) {
    if (selectedHall) {
        selectedHall->printInfo();
    }
}
void showHallPerformances(Hall* selectedHall) {
    if (selectedHall) {
        selectedHall->printPerformances();
    }
}