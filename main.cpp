#include "TransportList.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <Transport/transport.h>
#include <map>
#include <cstdint>
#include <Menu/Menu.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TransportList w;
    w.show();

    Menu menu;
    menu.mainMenu();

    return a.exec();
}
