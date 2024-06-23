#include <mainwindow.h>
#include <Menu/Menu.h>
#include <QApplication>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu menu;
    menu.loadDatabase();

    MainWindow w;
    w.show();

    return a.exec();
}
