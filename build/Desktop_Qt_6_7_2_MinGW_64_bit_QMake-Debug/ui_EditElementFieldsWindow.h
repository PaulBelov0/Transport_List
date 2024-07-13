/********************************************************************************
** Form generated from reading UI file 'EditElementFieldsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITELEMENTFIELDSWINDOW_H
#define UI_EDITELEMENTFIELDSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EditElementFieldsWindow
{
public:
    QPlainTextEdit *brandTextBox;
    QPlainTextEdit *modelTextBox;
    QSpinBox *yearSpinBox;
    QSpinBox *weightSpinBox;
    QPlainTextEdit *secondSpecialFieldTextBox;
    QLabel *labelID;
    QLabel *labelBrand;
    QLabel *labelModel;
    QLabel *labelYear;
    QLabel *labelWeight;
    QLabel *labelSpecialFieldFirst;
    QLabel *labelSpecialFieldSecond;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelType;
    QSpinBox *firstSpecialFieldSpinBox;
    QSpinBox *uinqueIDIntBox;
    QComboBox *typeComboBox;

    void setupUi(QDialog *EditElementFieldsWindow)
    {
        if (EditElementFieldsWindow->objectName().isEmpty())
            EditElementFieldsWindow->setObjectName("EditElementFieldsWindow");
        EditElementFieldsWindow->resize(640, 480);
        brandTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        brandTextBox->setObjectName("brandTextBox");
        brandTextBox->setGeometry(QRect(110, 170, 141, 31));
        QFont font;
        font.setPointSize(10);
        brandTextBox->setFont(font);
        modelTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        modelTextBox->setObjectName("modelTextBox");
        modelTextBox->setGeometry(QRect(110, 210, 141, 31));
        modelTextBox->setFont(font);
        yearSpinBox = new QSpinBox(EditElementFieldsWindow);
        yearSpinBox->setObjectName("yearSpinBox");
        yearSpinBox->setGeometry(QRect(110, 250, 141, 29));
        yearSpinBox->setFont(font);
        yearSpinBox->setMinimum(1860);
        yearSpinBox->setMaximum(2024);
        weightSpinBox = new QSpinBox(EditElementFieldsWindow);
        weightSpinBox->setObjectName("weightSpinBox");
        weightSpinBox->setGeometry(QRect(110, 290, 141, 29));
        weightSpinBox->setFont(font);
        weightSpinBox->setMinimum(50);
        weightSpinBox->setMaximum(2000000);
        secondSpecialFieldTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        secondSpecialFieldTextBox->setObjectName("secondSpecialFieldTextBox");
        secondSpecialFieldTextBox->setGeometry(QRect(110, 370, 141, 31));
        secondSpecialFieldTextBox->setFont(font);
        labelID = new QLabel(EditElementFieldsWindow);
        labelID->setObjectName("labelID");
        labelID->setGeometry(QRect(70, 90, 31, 31));
        QFont font1;
        font1.setPointSize(12);
        labelID->setFont(font1);
        labelID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelBrand = new QLabel(EditElementFieldsWindow);
        labelBrand->setObjectName("labelBrand");
        labelBrand->setGeometry(QRect(30, 170, 71, 31));
        labelBrand->setFont(font1);
        labelBrand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelModel = new QLabel(EditElementFieldsWindow);
        labelModel->setObjectName("labelModel");
        labelModel->setGeometry(QRect(30, 210, 71, 31));
        labelModel->setFont(font1);
        labelModel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelYear = new QLabel(EditElementFieldsWindow);
        labelYear->setObjectName("labelYear");
        labelYear->setGeometry(QRect(50, 250, 51, 31));
        labelYear->setFont(font1);
        labelYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelWeight = new QLabel(EditElementFieldsWindow);
        labelWeight->setObjectName("labelWeight");
        labelWeight->setGeometry(QRect(30, 290, 71, 31));
        labelWeight->setFont(font1);
        labelWeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSpecialFieldFirst = new QLabel(EditElementFieldsWindow);
        labelSpecialFieldFirst->setObjectName("labelSpecialFieldFirst");
        labelSpecialFieldFirst->setGeometry(QRect(10, 330, 91, 31));
        labelSpecialFieldFirst->setFont(font1);
        labelSpecialFieldFirst->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSpecialFieldSecond = new QLabel(EditElementFieldsWindow);
        labelSpecialFieldSecond->setObjectName("labelSpecialFieldSecond");
        labelSpecialFieldSecond->setGeometry(QRect(10, 370, 91, 31));
        labelSpecialFieldSecond->setFont(font1);
        labelSpecialFieldSecond->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        okButton = new QPushButton(EditElementFieldsWindow);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(380, 400, 83, 29));
        cancelButton = new QPushButton(EditElementFieldsWindow);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(480, 400, 83, 29));
        label_1 = new QLabel(EditElementFieldsWindow);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(290, 40, 131, 121));
        label_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_1->setWordWrap(true);
        label_2 = new QLabel(EditElementFieldsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 40, 111, 121));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        label_3 = new QLabel(EditElementFieldsWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 180, 131, 121));
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(true);
        label_4 = new QLabel(EditElementFieldsWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 180, 151, 121));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(true);
        labelType = new QLabel(EditElementFieldsWindow);
        labelType->setObjectName("labelType");
        labelType->setGeometry(QRect(20, 130, 81, 31));
        labelType->setFont(font1);
        labelType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        firstSpecialFieldSpinBox = new QSpinBox(EditElementFieldsWindow);
        firstSpecialFieldSpinBox->setObjectName("firstSpecialFieldSpinBox");
        firstSpecialFieldSpinBox->setGeometry(QRect(110, 330, 141, 29));
        firstSpecialFieldSpinBox->setFont(font);
        firstSpecialFieldSpinBox->setMaximum(99999);
        uinqueIDIntBox = new QSpinBox(EditElementFieldsWindow);
        uinqueIDIntBox->setObjectName("uinqueIDIntBox");
        uinqueIDIntBox->setGeometry(QRect(110, 90, 141, 29));
        uinqueIDIntBox->setFont(font);
        uinqueIDIntBox->setMinimum(1);
        uinqueIDIntBox->setMaximum(99999);
        typeComboBox = new QComboBox(EditElementFieldsWindow);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setGeometry(QRect(110, 130, 141, 28));
        typeComboBox->setFont(font);
        typeComboBox->setMaxVisibleItems(4);

        retranslateUi(EditElementFieldsWindow);

        QMetaObject::connectSlotsByName(EditElementFieldsWindow);
    } // setupUi

    void retranslateUi(QDialog *EditElementFieldsWindow)
    {
        EditElementFieldsWindow->setWindowTitle(QCoreApplication::translate("EditElementFieldsWindow", "Element fields", nullptr));
        labelID->setText(QCoreApplication::translate("EditElementFieldsWindow", "ID:", nullptr));
        labelBrand->setText(QCoreApplication::translate("EditElementFieldsWindow", " Brand:", nullptr));
        labelModel->setText(QCoreApplication::translate("EditElementFieldsWindow", "Model:", nullptr));
        labelYear->setText(QCoreApplication::translate("EditElementFieldsWindow", "Year:", nullptr));
        labelWeight->setText(QCoreApplication::translate("EditElementFieldsWindow", "Weight:", nullptr));
        labelSpecialFieldFirst->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special 1:", nullptr));
        labelSpecialFieldSecond->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special 2:", nullptr));
        okButton->setText(QCoreApplication::translate("EditElementFieldsWindow", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditElementFieldsWindow", "Cancel", nullptr));
        label_1->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for car:\n"
"1) Mileage (in kilometers)\n"
"2) Owners Quantity", nullptr));
        label_2->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for boat: \n"
"1) Displacement (in meters^3)\n"
"2) Screw Depth (in meters)", nullptr));
        label_3->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for Air transport: \n"
"1) Wingspan (in meters)\n"
"2) Payload Capacity", nullptr));
        label_4->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for Space shuttle: \n"
"1) Max Flying Distance (in kilometers)\n"
"2) Fuel type", nullptr));
        labelType->setText(QCoreApplication::translate("EditElementFieldsWindow", "Type:", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("EditElementFieldsWindow", "Car", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("EditElementFieldsWindow", "Air", nullptr));
        typeComboBox->setItemText(2, QCoreApplication::translate("EditElementFieldsWindow", "Boat", nullptr));
        typeComboBox->setItemText(3, QCoreApplication::translate("EditElementFieldsWindow", "Shuttle", nullptr));

    } // retranslateUi

};

namespace Ui {
    class EditElementFieldsWindow: public Ui_EditElementFieldsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITELEMENTFIELDSWINDOW_H
