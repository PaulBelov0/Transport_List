#include "ElementIDErrorWindow.h"
#include "ui_ElementIDErrorWindow.h"

ElementIDErrorWindow::ElementIDErrorWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchErrorWindow)
{
    ui->setupUi(this);
}

ElementIDErrorWindow::~ElementIDErrorWindow()
{
    delete ui;
}

void ElementIDErrorWindow::on_closeButton_clicked()
{

}

