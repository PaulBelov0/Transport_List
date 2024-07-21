#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "Controller/Controller.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void mainProcedure();

private:

    void throwError();

    void enterElementFields();

    void showDatabase();

    std::string enterTransportField(const std::string fieldName);

    bool checkDataConvertibleToUInt(std::vector<std::string>& value);

    Controller* controller;
};

#endif // MENU_H
