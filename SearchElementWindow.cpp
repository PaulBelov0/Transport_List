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

}


void SearchElementWindow::on_deleteButton_clicked()
{

}

