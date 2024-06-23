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
            elementIDErrorWindow.show();
        }
        Menu menu;
        menu.deleteDatabaseElement(index);
    }
    else
    {
        elementIDErrorWindow.show();
    }
}


void DeleteElementWindow::on_exitButton_clicked()
{

}

