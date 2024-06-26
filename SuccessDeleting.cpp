#include "SuccessDeleting.h"
#include "ui_SuccessDeleting.h"

SuccessDeleting::SuccessDeleting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuccessDeleting)
{
    ui->setupUi(this);
}

SuccessDeleting::~SuccessDeleting()
{
    delete ui;
}

void SuccessDeleting::on_Ok_clicked()
{
    this->close();
}

