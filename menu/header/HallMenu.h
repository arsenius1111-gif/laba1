#ifndef HALL_MENU_H
#define HALL_MENU_H

#include <vector>
#include "Hall.h"
#include "Performance.h"

class HallMenu {
public:
    static void create(std::vector<Hall>& halls);
    static void manage(std::vector<Hall>& halls, const std::vector<Performance>& catalog);
};

#endif