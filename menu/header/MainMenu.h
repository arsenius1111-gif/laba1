#ifndef MAINMENU_H
#define MAINMENU_H
#include <string_view>
#include <string>
#include "../../include/Hall.h"
int inputInt(std::string_view message);
int inputPositiveInt(std::string_view message);
std::string inputString(std::string_view message);
void printMainMenu();
void runApplication(Hall& hall1, Hall& hall2);
#endif