#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <vector>
#include "Hall.h"
#include "Performance.h"

class MainMenu {
private:
    std::vector<Hall> halls;
    std::vector<Performance> catalog;

    void initDatabase();
    void clearInput() const;

public:
    MainMenu();
    void run();
};

#endif