#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SearchElementWindow.h>
#include <ElementIDErrorWindow.h>
#include <EditElementFieldsWindow.h>

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

    void on_showElementButton_clicked();

    void on_loadDatabaseButton_clicked();

    void on_saveDataBaseButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;

    EditElementFieldsWindow addNewelementWindow;
    SearchElementWindow deleteElementWindow;
};

#endif // MAINWINDOW_H
