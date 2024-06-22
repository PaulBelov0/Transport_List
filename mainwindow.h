#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextStream>
#include <QString>
#include <Transport/transport.h>
#include <TransportMap/transportmap.h>
#include <MEnu/Menu.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QDialog; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showElement(TransportMap& databaseElement, uint32_t index);
    void showElement(std::string& output);

public slots:
    void on_addNewElementButton_clicked();
    void on_deleteElementButton_clicked();
    void on_editElementButton_clicked();
    void on_showElementButton_clicked();
    void on_saveDatabaseButton_clicked();
    void on_loadDatabaseButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::QDialog *ui;
};
#endif // MAINWINDOW_H
