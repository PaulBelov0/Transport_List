#include "EditElementFieldsWindow.h"
#include "ui_EditElementFieldsWindow.h"

EditElementFieldsWindow::EditElementFieldsWindow(std::vector<std::string>* args, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditElementFieldsWindow)
{
    this->args = args;
    ui->setupUi(this);
}

EditElementFieldsWindow::~EditElementFieldsWindow()
{
    delete ui;
}

void EditElementFieldsWindow::on_okButton_clicked()
{
    args->push_back(std::to_string(ui->uinqueIDIntBox->value()));

    args->push_back(ui->typeComboBox->currentText().toStdString());

    args->push_back(ui->brandTextBox->toPlainText().toStdString());

    args->push_back(ui->modelTextBox->toPlainText().toStdString());

    args->push_back(std::to_string(ui->yearSpinBox->value()));

    args->push_back(std::to_string(ui->weightSpinBox->value()));

    args->push_back(std::to_string(ui->firstSpecialFieldSpinBox->value()));

    args->push_back(ui->secondSpecialFieldTextBox->toPlainText().toStdString());

    this->close();
}

void EditElementFieldsWindow::setElementByID(const uint32_t &ID)
{
    QVariant converter;
    std::list<std::shared_ptr<TransportBase>> listTmp = transportStorage->getList();
    for (auto& iter : listTmp)
    {
        if(iter->uniqueID == ID)
        {
            converter = iter->uniqueID;
            ui->uinqueIDIntBox->setDisplayIntegerBase(converter.toInt());

            converter = QString::fromStdString(iter->type);
            ui->typeComboBox->setCurrentText(converter.toString());

            converter = QString::fromStdString(iter->brand);
            ui->brandTextBox->setPlainText(converter.toString());

            converter = QString::fromStdString(iter->model);
            ui->modelTextBox->setPlainText(converter.toString());

            converter = iter->year;
            ui->yearSpinBox->setDisplayIntegerBase(converter.toInt());

            converter = iter->weight;
            ui->weightSpinBox->setDisplayIntegerBase(converter.toInt());

            if(iter->type == "Air")
            {
                std::shared_ptr<AirTransport> airTmp = std::dynamic_pointer_cast<AirTransport>(iter);
                converter = airTmp->wingspan;
                ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

                converter = QString::fromStdString(std::to_string(airTmp->payloadCapacity));
                ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
            }
            else if(iter->type == "Car")
            {
                std::shared_ptr<Car> carTmp = std::dynamic_pointer_cast<Car>(iter);
                converter = carTmp->mileage;
                ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

                converter = QString::fromStdString(std::to_string(carTmp->ownersQuantity));
                ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
            }
            else if (iter->type == "Boat")
            {
                std::shared_ptr<Boat> boatTmp = std::dynamic_pointer_cast<Boat>(iter);
                converter = boatTmp->displacement;
                ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

                converter = QString::fromStdString(std::to_string(boatTmp->screwDepth));
                ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
            }
            else if (iter->type == "Shuttle")
            {
                std::shared_ptr<Shuttle> shuttleTmp = std::dynamic_pointer_cast<Shuttle>(iter);
                converter = shuttleTmp->maxFlyingDistance;
                ui->firstSpecialFieldSpinBox->setDisplayIntegerBase(converter.toInt());

                converter = QString::fromStdString(shuttleTmp->fuelType);
                ui->secondSpecialFieldTextBox->setPlainText(converter.toString());
            }
        }
    }
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
