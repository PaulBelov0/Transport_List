#include "EditElementFieldsWindow.h"
#include "ui_EditElementFieldsWindow.h"

EditElementFieldsWindow::EditElementFieldsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditElementFieldsWindow)
{
    transportMap.reset(new TransportMap(*db.download()));

    ui->setupUi(this);
}

EditElementFieldsWindow::~EditElementFieldsWindow()
{
    delete ui;
}

void EditElementFieldsWindow::on_okButton_clicked()
{
    ID = ui->uinqueIDIntBox->value();
    type = ui->typeComboBox->currentText();
    brand = ui->brandTextBox->toPlainText();
    model = ui->modelTextBox->toPlainText();
    year = ui->yearSpinBox->value();
    weight = ui->weightSpinBox->value();
    firstSpecialField = ui->firstSpecialFieldSpinBox->value();
    secondSpecialField = ui->secondSpecialFieldTextBox->toPlainText();

    if (actionWithDB == "add" || "Add")
    {
        menu.addNewElement(ID,type, brand, model,year, weight,
                           firstSpecialField, secondSpecialField);
    }
    else if (actionWithDB == "edit" || "Edit")
    {
        menu.editElement(ID, type, brand, model, year, weight,
                         firstSpecialField, secondSpecialField);
    }
    this->close();
}

void EditElementFieldsWindow::setElementByID(const uint32_t &ID)
{
    QVariant converter;

    converter = transportMap->getMap().at(ID)->getID();
    ui->uinqueIDIntBox->setDisplayIntegerBase(converter.toInt());

    converter = transportMap->getMap().at(ID)->getType();
    ui->typeComboBox->setCurrentText(converter.toString());

    converter = transportMap->getMap().at(ID)->getBrand();
    ui->brandTextBox->setPlainText(converter.toString());

    converter = transportMap->getMap().at(ID)->getModel();
    ui->modelTextBox->setPlainText(converter.toString());

    converter = transportMap->getMap().at(ID)->getYear();
    ui->yearSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = transportMap->getMap().at(ID)->getWeight();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = transportMap->getMap().at(ID)->getSpecialFirst();
    ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = transportMap->getMap().at(ID)->getSpecialSecond();
    ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
}

void EditElementFieldsWindow::setActionForRealizationThisWnd(std::string action)
{
    if (action == "add" || "Add")
    {
        actionWithDB = action;
    }
    else if (action == "edit" || "Edit")
    {
        actionWithDB = action;
    }
    else {}
}

void EditElementFieldsWindow::on_cancelButton_clicked()
{
    this->close();
}
