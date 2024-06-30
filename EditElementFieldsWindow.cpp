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
    QString type = ui->typeTextBox->toPlainText();
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

    ui->uinqueIDIntBox->setDisplayIntegerBase(map.find(ID)->second.getID());
    ui->typeTextBox->setPlainText(map.find(ID)->second.getType());
    ui->brandTextBox->setPlainText(map.find(ID)->second.getBrand());
    ui->modelTextBox->setPlainText(map.find(ID)->second.getModel());
    ui->yearSpinBox->setDisplayIntegerBase(map.find(ID)->second.getYear());
    ui->weightSpinBox->setDisplayIntegerBase(map.find(ID)->second.getWeight());
    ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(map.find(ID)->second.getSpecialFirst());
    ui->secondSpecialFieldTextBox->setPlainText(map.find(ID)->second.getSpecialSecond());
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

