#include "EditElementFieldsWindow.h"
#include "ui_EditElementFieldsWindow.h"

EditElementFieldsWindow::EditElementFieldsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditElementFieldsWindow)
{
    if (!db.getQuery().value(0).isNull())
        transportStorage.reset(new TransportStorage(*db.download()));

    ui->setupUi(this);
}

EditElementFieldsWindow::~EditElementFieldsWindow()
{
    delete ui;
}

void EditElementFieldsWindow::on_okButton_clicked()
{

    std::vector<std::string> args;
    args.push_back(std::to_string(ui->uinqueIDIntBox->value()));
    args.push_back(ui->typeComboBox->currentText().toStdString());
    args.push_back(ui->brandTextBox->toPlainText().toStdString());
    args.push_back(ui->modelTextBox->toPlainText().toStdString());
    args.push_back(std::to_string(ui->yearSpinBox->value()));
    args.push_back(std::to_string(ui->weightSpinBox->value()));
    args.push_back(std::to_string(ui->firstSpecialFieldSpinBox->value()));
    args.push_back(ui->secondSpecialFieldTextBox->toPlainText().toStdString());

    if (actionWithDB == "add" || "Add") {
        controller.addNewElement(args);
    } else if (actionWithDB == "edit" || "Edit") {
        controller.editElement(args);
    }
    this->close();
}

void EditElementFieldsWindow::setElementByID(const uint32_t &ID)
{
    QVariant converter;

    converter = transportStorage->getMap().at(ID)->getID();
    ui->uinqueIDIntBox->setDisplayIntegerBase(converter.toInt());

    converter = QString::fromStdString(transportStorage->getMap().at(ID)->getType());
    ui->typeComboBox->setCurrentText(converter.toString());

    converter = QString::fromStdString(transportStorage->getMap().at(ID)->getBrand());
    ui->brandTextBox->setPlainText(converter.toString());

    converter = QString::fromStdString(transportStorage->getMap().at(ID)->getModel());
    ui->modelTextBox->setPlainText(converter.toString());

    converter = transportStorage->getMap().at(ID)->getYear();
    ui->yearSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = transportStorage->getMap().at(ID)->getWeight();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = transportStorage->getMap().at(ID)->getSpecialFirst();
    ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = QString::fromStdString(transportStorage->getMap().at(ID)->getSpecialSecond());
    ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
}

void EditElementFieldsWindow::setActionForRealizationThisWnd(std::string action)
{
    if (action == "add" || "Add") {
        actionWithDB = action;
    } else if (action == "edit" || "Edit") {
        actionWithDB = action;
    }
}

void EditElementFieldsWindow::on_cancelButton_clicked()
{
    this->close();
}
