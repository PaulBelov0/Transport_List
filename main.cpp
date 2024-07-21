//#include <QApplication>

#include "Menu/Menu.h"

int main(/*int argc, char *argv[]*/)
{
    Menu* menu = new Menu();

    menu->mainProcedure();

    delete menu;
    return 0;
}
