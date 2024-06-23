#include "EditElementFieldsWindow.h"
#include "ui_EditElementFieldsWindow.h"

EditElementFieldsWindow::EditElementFieldsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewElementWindow)
{
    ui->setupUi(this);
}

EditElementFieldsWindow::~EditElementFieldsWindow()
{
    delete ui;
}

void EditElementFieldsWindow::on_okButton_clicked()
{

}


void EditElementFieldsWindow::on_cancelButton_clicked()
{

}

