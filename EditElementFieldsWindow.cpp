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
    uint32_t ID = ui->uinqueIDIntBox->value();
    std::string type = ui->typeComboBox->currentText().toStdString();
    std::string brand = ui->brandTextBox->toPlainText().toStdString();
    std::string model = ui->modelTextBox->toPlainText().toStdString();
    uint32_t year = ui->yearSpinBox->value();
    uint32_t weight = ui->weightSpinBox->value();
    uint32_t firstSpecialField = ui->firstSpecialFieldSpinBox->value();
    std::string secondSpecialField = ui->secondSpecialFieldTextBox->toPlainText().toStdString();

    if (actionWithDB == "add" || "Add") {
        menu.addNewElement(ID,
                           type,
                           brand,
                           model,
                           year,
                           weight,
                           firstSpecialField,
                           secondSpecialField);
    } else if (actionWithDB == "edit" || "Edit") {
        menu.editElement(ID, type, brand, model, year, weight, firstSpecialField, secondSpecialField);
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
