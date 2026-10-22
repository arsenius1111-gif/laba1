#ifndef MAINMENU_H
#define MAINMENU_H

#include "Hall.h"
#include "Performance.h"
#include <memory>
#include <vector>

class MainMenu {
private:
    std::vector<Hall> halls;
    std::vector<std::shared_ptr<Performance>> catalog;

    void initDatabase();
    void clearInput() const;

public:
    MainMenu();
    void run();
};

#endif