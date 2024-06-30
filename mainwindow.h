#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Menu/Menu.h>
#include <EditElementFieldsWindow.h>
#include <SearchElementWindow.h>
#include <DeleteElementWindow.h>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNewElementButton_clicked();

    void on_editElementButton_clicked();

    void on_deleteElementButton_clicked();

    void on_loadDatabaseButton_clicked();

    void on_saveDataBaseButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;

    Database database;
    Menu menu;

    EditElementFieldsWindow editElementFieldsWindow;
    SearchElementWindow searchElementWindow;
    DeleteElementWindow deleteElementWindow;

    QSqlTableModel* model;
};

#endif // MAINWINDOW_H
