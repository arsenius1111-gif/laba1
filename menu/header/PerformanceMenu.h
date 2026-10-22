#ifndef PERFORMANCEMENU_H
#define PERFORMANCEMENU_H

#include "Performance.h"
#include <memory>
#include <vector>

class PerformanceMenu {
public:
    static void showAll(
        const std::vector<std::shared_ptr<Performance>>& catalog);

    static void create(
        std::vector<std::shared_ptr<Performance>>& catalog);

    static void compare(
        const std::vector<std::shared_ptr<Performance>>& catalog);

    static void showInheritanceDemo();
};

#endif