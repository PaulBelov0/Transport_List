#include <EditElementFieldsWindow_.h>
#include "ui_EditElementFieldsWindow_.h"

EditElementFieldsWindow::EditElementFieldsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditElementFieldsWindow)
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

