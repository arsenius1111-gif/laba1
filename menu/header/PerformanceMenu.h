#ifndef PERFORMANCE_MENU_H
#define PERFORMANCE_MENU_H

#include <vector>
#include "Performance.h"

class PerformanceMenu {
public:
    static void showAll(const std::vector<Performance>& catalog);
    static void create(std::vector<Performance>& catalog);
    static void compare(const std::vector<Performance>& catalog);
};

#endif