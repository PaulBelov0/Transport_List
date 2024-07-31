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

    std::vector<std::string> enterElementFields(bool adding);

    void showDatabase();

    void printElementFields(std::shared_ptr<TransportBase>& element);

    std::string enterTransportField(const std::string fieldName);

    bool checkDataConvertibleToUInt(std::vector<std::string>& value, int elementNumber);

    Controller* controller;

    uint32_t uniqueID;
};

#endif // MENU_H
