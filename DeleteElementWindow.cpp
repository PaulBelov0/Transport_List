#include "DeleteElementWindow.h"
#include "ui_DeleteElementWindow.h"

DeleteElementWindow::DeleteElementWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteElementWindow)
{
    ui->setupUi(this);
}

DeleteElementWindow::~DeleteElementWindow()
{
    delete ui;
}

void DeleteElementWindow::on_deleteButton_clicked()
{
    if(ui->plainTextEdit != NULL)
    {
        uint32_t index;
        QString qString = ui->plainTextEdit->toPlainText();
        std::string text = qString.toStdString();
        try {
            index = std::stoi(text);
        }
        catch(QException& e){
            messageToUserWindow.show();
            messageToUserWindow.setTextMessage("element successful deleted!");
        }
        Menu menu;
        menu.deleteDatabaseElement(index);
    }
    else
    {
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! Wrong input data!");
    }
}


void DeleteElementWindow::on_exitButton_clicked()
{
    this->close();
}

