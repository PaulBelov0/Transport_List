#include <mainwindow.h>
#include <Menu/Menu.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    Menu menu;
    menu.mainMenu();

    return a.exec();
}
