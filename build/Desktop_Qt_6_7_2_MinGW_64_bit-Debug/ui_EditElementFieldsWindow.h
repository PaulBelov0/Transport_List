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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EditElementFieldsWindow
{
public:
    QPlainTextEdit *IDTextBox;
    QPlainTextEdit *brandTextBox;
    QPlainTextEdit *modelTextBox;
    QSpinBox *yearSpinBox;
    QSpinBox *weightTextBox;
    QPlainTextEdit *firstSpecialFieldTextBox;
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *EditElementFieldsWindow)
    {
        if (EditElementFieldsWindow->objectName().isEmpty())
            EditElementFieldsWindow->setObjectName("EditElementFieldsWindow");
        EditElementFieldsWindow->resize(640, 480);
        IDTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        IDTextBox->setObjectName("IDTextBox");
        IDTextBox->setGeometry(QRect(110, 90, 141, 31));
        brandTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        brandTextBox->setObjectName("brandTextBox");
        brandTextBox->setGeometry(QRect(110, 130, 141, 31));
        modelTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        modelTextBox->setObjectName("modelTextBox");
        modelTextBox->setGeometry(QRect(110, 170, 141, 31));
        yearSpinBox = new QSpinBox(EditElementFieldsWindow);
        yearSpinBox->setObjectName("yearSpinBox");
        yearSpinBox->setGeometry(QRect(110, 210, 141, 29));
        yearSpinBox->setMinimum(1860);
        yearSpinBox->setMaximum(2024);
        weightTextBox = new QSpinBox(EditElementFieldsWindow);
        weightTextBox->setObjectName("weightTextBox");
        weightTextBox->setGeometry(QRect(110, 250, 141, 29));
        weightTextBox->setMinimum(50);
        weightTextBox->setMaximum(2000000);
        firstSpecialFieldTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        firstSpecialFieldTextBox->setObjectName("firstSpecialFieldTextBox");
        firstSpecialFieldTextBox->setGeometry(QRect(110, 290, 141, 31));
        secondSpecialFieldTextBox = new QPlainTextEdit(EditElementFieldsWindow);
        secondSpecialFieldTextBox->setObjectName("secondSpecialFieldTextBox");
        secondSpecialFieldTextBox->setGeometry(QRect(110, 330, 141, 31));
        labelID = new QLabel(EditElementFieldsWindow);
        labelID->setObjectName("labelID");
        labelID->setGeometry(QRect(70, 90, 31, 31));
        QFont font;
        font.setPointSize(12);
        labelID->setFont(font);
        labelID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelBrand = new QLabel(EditElementFieldsWindow);
        labelBrand->setObjectName("labelBrand");
        labelBrand->setGeometry(QRect(30, 130, 71, 31));
        labelBrand->setFont(font);
        labelBrand->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelModel = new QLabel(EditElementFieldsWindow);
        labelModel->setObjectName("labelModel");
        labelModel->setGeometry(QRect(30, 170, 71, 31));
        labelModel->setFont(font);
        labelModel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelYear = new QLabel(EditElementFieldsWindow);
        labelYear->setObjectName("labelYear");
        labelYear->setGeometry(QRect(50, 210, 51, 31));
        labelYear->setFont(font);
        labelYear->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelWeight = new QLabel(EditElementFieldsWindow);
        labelWeight->setObjectName("labelWeight");
        labelWeight->setGeometry(QRect(30, 250, 71, 31));
        labelWeight->setFont(font);
        labelWeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSpecialFieldFirst = new QLabel(EditElementFieldsWindow);
        labelSpecialFieldFirst->setObjectName("labelSpecialFieldFirst");
        labelSpecialFieldFirst->setGeometry(QRect(10, 290, 91, 31));
        labelSpecialFieldFirst->setFont(font);
        labelSpecialFieldFirst->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSpecialFieldSecond = new QLabel(EditElementFieldsWindow);
        labelSpecialFieldSecond->setObjectName("labelSpecialFieldSecond");
        labelSpecialFieldSecond->setGeometry(QRect(10, 330, 91, 31));
        labelSpecialFieldSecond->setFont(font);
        labelSpecialFieldSecond->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        okButton = new QPushButton(EditElementFieldsWindow);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(380, 400, 83, 29));
        cancelButton = new QPushButton(EditElementFieldsWindow);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(480, 400, 83, 29));
        label = new QLabel(EditElementFieldsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 40, 131, 121));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label_2 = new QLabel(EditElementFieldsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 40, 111, 121));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        label_3 = new QLabel(EditElementFieldsWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 190, 131, 121));
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(true);
        label_4 = new QLabel(EditElementFieldsWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 190, 151, 121));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_4->setWordWrap(true);

        retranslateUi(EditElementFieldsWindow);

        QMetaObject::connectSlotsByName(EditElementFieldsWindow);
    } // setupUi

    void retranslateUi(QDialog *EditElementFieldsWindow)
    {
        EditElementFieldsWindow->setWindowTitle(QCoreApplication::translate("EditElementFieldsWindow", "Dialog", nullptr));
        labelID->setText(QCoreApplication::translate("EditElementFieldsWindow", "ID:", nullptr));
        labelBrand->setText(QCoreApplication::translate("EditElementFieldsWindow", " Brand:", nullptr));
        labelModel->setText(QCoreApplication::translate("EditElementFieldsWindow", "Model:", nullptr));
        labelYear->setText(QCoreApplication::translate("EditElementFieldsWindow", "Year:", nullptr));
        labelWeight->setText(QCoreApplication::translate("EditElementFieldsWindow", "Weight:", nullptr));
        labelSpecialFieldFirst->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special 1:", nullptr));
        labelSpecialFieldSecond->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special 2:", nullptr));
        okButton->setText(QCoreApplication::translate("EditElementFieldsWindow", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditElementFieldsWindow", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for car:\n"
"\n"
"1) Mileage\n"
"2) Owners Quantity", nullptr));
        label_2->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for boat: \n"
"\n"
"1) Displacement\n"
"2) Screw Depth", nullptr));
        label_3->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for Air transport: \n"
"\n"
"1) Wingspan\n"
"2) Payload Capacity", nullptr));
        label_4->setText(QCoreApplication::translate("EditElementFieldsWindow", "Special fields for Space shuttle: \n"
"\n"
"1) Fuel Type\n"
"2) Max Flying Distance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditElementFieldsWindow: public Ui_EditElementFieldsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITELEMENTFIELDSWINDOW_H
