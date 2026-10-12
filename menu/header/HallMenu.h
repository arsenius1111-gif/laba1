#ifndef HALLMENU_H
#define HALLMENU_H

#include "Hall.h"
#include "Performance.h"
#include <vector>

class HallMenu {
public:
    static void create(std::vector<Hall>& halls);
    static void manage(std::vector<Hall>& halls,
        const std::vector<Performance>& catalog);
};

#endif