#include "EditElementFieldsWindow.h"
#include "ui_EditElementFieldsWindow.h"

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
    Menu menu;

    uint32_t ID = ui->uinqueIDIntBox->value();
    QString type = ui->typeComboBox->currentText();
    QString brand = ui->brandTextBox->toPlainText();
    QString model = ui->modelTextBox->toPlainText();
    uint32_t year = ui->yearSpinBox->value();
    uint32_t weight = ui->weightSpinBox->value();
    uint32_t firstSpecialField = ui->firstSpecialFieldSpinBox->value();
    QString secondSpecialField = ui->secondSpecialFieldTextBox->toPlainText();

    if (actionWithDB == "add" || "Add")
    {
        menu.addNewElement(ID, type, brand, model, year, weight, firstSpecialField, secondSpecialField);
    }
    else if (actionWithDB == "edit" || "Edit")
    {
        menu.editElement(ID, type, brand, model, year, weight, firstSpecialField, secondSpecialField);
    }
    this->close();
}

void EditElementFieldsWindow::setElementByID(const uint32_t& ID)
{
    std::map<uint32_t, TransportBase&> map = transportMap.getMap();

    QVariant converter;

    converter = map.find(ID)->second.getID();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getType();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getBrand();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getModel();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getYear();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getWeight();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getSpecialFirst();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.find(ID)->second.getSpecialSecond();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());
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

