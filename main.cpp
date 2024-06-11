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

    std::map<uint32_t, TransportBase&>* transportDB = new std::map<uint32_t, TransportBase&>;

    Menu menu(transportDB);
    menu.mainMenu();

    return a.exec();
}
