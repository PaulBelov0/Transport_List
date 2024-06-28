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
    Menu* menu = new Menu;
    uint32_t index;
    QString qString = ui->plainTextEdit->toPlainText();

    if(ui->plainTextEdit != NULL)
    {
        std::string text = qString.toStdString();
        try
        {
            index = std::stoi(text);
        }
        catch(QException& e)
        {
            messageToUserWindow.show();
            messageToUserWindow.setTextMessage("Error! Wrong input data!");
        }
        qString = menu->deleteDatabaseElement(index);
        messageToUserWindow.setTextMessage(qString);
    }
    else
    {
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! Wrong input data!");
    }
    delete menu;
}


void DeleteElementWindow::on_exitButton_clicked()
{
    this->close();
}

