#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QtSql/QtSql>

#include "DeleteElementWindow.h"
#include "EditElementFieldsWindow.h"
#include "Menu/Menu.h"
#include "SearchElementWindow.h"

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
    void reloadDatabase();

    Ui::MainWindow *ui;

    Database database;
    Menu menu;

    EditElementFieldsWindow editElementFieldsWindow;
    SearchElementWindow searchElementWindow;
    DeleteElementWindow deleteElementWindow;

    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
