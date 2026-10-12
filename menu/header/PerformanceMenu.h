#ifndef PERFORMANCEMENU_H
#define PERFORMANCEMENU_H

#include "Performance.h"
#include <vector>

class PerformanceMenu {
public:
    static void showAll(const std::vector<Performance>& catalog);
    static void create(std::vector<Performance>& catalog);
    static void compare(const std::vector<Performance>& catalog);
    static void showInheritanceDemo();
};

#endif