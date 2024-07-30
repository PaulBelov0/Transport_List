#include "DeleteElementWindow.h"
#include "ui_DeleteElementWindow.h"

DeleteElementWindow::DeleteElementWindow(Controller* controller, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteElementWindow)
{
    this->controller = controller;
    ui->setupUi(this);
}

DeleteElementWindow::~DeleteElementWindow()
{
    delete ui;
}

void DeleteElementWindow::on_deleteButton_clicked()
{
    if (ui->plainTextEdit != NULL) {
        userInput = ui->plainTextEdit->toPlainText().toStdString();
        try {
            index = std::stoi(userInput);
        } catch (QException &e) {
            messageToUserWindow.show();
            messageToUserWindow.setTextMessage("Error! Wrong input data!");
        }
        QString qString = controller->deleteDatabaseElement(index);
        messageToUserWindow.setTextMessage(qString);
    } else {
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! Wrong input data!");
    }
}

void DeleteElementWindow::on_exitButton_clicked()
{
    this->close();
}

uint32_t &DeleteElementWindow::getID()
{
    return controller->getID();
}
