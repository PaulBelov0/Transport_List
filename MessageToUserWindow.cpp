#include "MessageToUserWindow.h"
#include "ui_MessageToUserWindow.h"

MessageToUserWindow::MessageToUserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MessageToUserWindow)
{
    ui->setupUi(this);
}

MessageToUserWindow::~MessageToUserWindow()
{
    delete ui;
}

void MessageToUserWindow::setTextMessage(const QString& textMessage)
{
    ui->textMessage->setText(textMessage);
}

void MessageToUserWindow::on_okButton_clicked()
{
    this->close();
}

