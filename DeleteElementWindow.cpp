#include "DeleteElementWindow.h"
#include "ui_DeleteElementWindow.h"

DeleteElementWindow::DeleteElementWindow(uint32_t* args, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteElementWindow)
{
    this->args = args;
    ui->setupUi(this);
}

DeleteElementWindow::~DeleteElementWindow()
{
    delete ui;
}

void DeleteElementWindow::on_deleteButton_clicked()
{
    // if (ui->plainTextEdit != NULL) {
    //     userInput = ui->plainTextEdit->toPlainText().toStdString();
    //     try {
    //         index = std::stoi(userInput);
    //     } catch (QException &e) {
    //         messageToUserWindow.show();
    //         messageToUserWindow.setTextMessage("Error! Wrong input data!");
    //     }
    //     QString qString = controller->deleteDatabaseElement(index);
    //     messageToUserWindow.setTextMessage(qString);
    // } else {
    //     messageToUserWindow.show();
    //     messageToUserWindow.setTextMessage("Error! Wrong input data!");
    // }

    if (ui->plainTextEdit != NULL)
    {
        std::string userInput = ui->plainTextEdit->toPlainText().toStdString();
        try
        {
            *args = std::stoi(userInput);
        }
        catch(std::invalid_argument& e)
        {
            args = nullptr;
        }
    }
    else
    {
        args = nullptr;
    }
}

void DeleteElementWindow::on_exitButton_clicked()
{
    this->close();
}
