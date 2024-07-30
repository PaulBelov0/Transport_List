#ifndef DELETEELEMENTWINDOW_H
#define DELETEELEMENTWINDOW_H

#include <QDialog>
#include <QException>

#include "Controller/Controller.h"
#include "MessageToUserWindow.h"

namespace Ui {
class DeleteElementWindow;
}

class DeleteElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteElementWindow(Controller* controller, QWidget *parent = nullptr);
    ~DeleteElementWindow();
    uint32_t &getID();

private slots:
    void on_deleteButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::DeleteElementWindow *ui;

    MessageToUserWindow messageToUserWindow;

    uint32_t index;

    std::string userInput;

    Controller* controller;
};

#endif // DELETEELEMENTWINDOW_H
