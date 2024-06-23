#include "SearchElementWindow.h"
#include "ui_SearchElementWindow.h"

SearchElementWindow::SearchElementWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchElementWindow)
{
    ui->setupUi(this);
}

SearchElementWindow::~SearchElementWindow()
{
    delete ui;
}

void SearchElementWindow::on_exitButton_clicked()
{
    this->close();
}


void SearchElementWindow::on_okButton_clicked()
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
        menu.showDatabaseElement(index);
    }
    else
    {
        elementIDErrorWindow.show();
    }
}
