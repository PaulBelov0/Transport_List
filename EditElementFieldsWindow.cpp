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
    std::map<uint32_t, std::unique_ptr<TransportBase>> map = transportMap.getMap();

    QVariant converter;

    converter = map.at(ID)->getID();
    ui->uinqueIDIntBox->setDisplayIntegerBase(converter.toInt());

    converter = map.at(ID)->getType();
    ui->typeComboBox->setCurrentText(converter.toString());

    converter = map.at(ID)->getBrand();
    ui->brandTextBox->setPlainText(converter.toString());

    converter = map.at(ID)->getModel();
    ui->modelTextBox->setPlainText(converter.toString());

    converter = map.at(ID)->getYear();
    ui->yearSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.at(ID)->getWeight();
    ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.at(ID)->getSpecialFirst();
    ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

    converter = map.at(ID)->getSpecialSecond();
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
