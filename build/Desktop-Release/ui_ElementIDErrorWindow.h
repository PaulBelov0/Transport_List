/********************************************************************************
** Form generated from reading UI file 'ElementIDErrorWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEMENTIDERRORWINDOW_H
#define UI_ELEMENTIDERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ElementIDErrorWindow
{
public:
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QDialog *ElementIDErrorWindow)
    {
        if (ElementIDErrorWindow->objectName().isEmpty())
            ElementIDErrorWindow->setObjectName("ElementIDErrorWindow");
        ElementIDErrorWindow->resize(320, 240);
        label = new QLabel(ElementIDErrorWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 70, 231, 71));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        closeButton = new QPushButton(ElementIDErrorWindow);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(120, 190, 83, 29));

        retranslateUi(ElementIDErrorWindow);

        QMetaObject::connectSlotsByName(ElementIDErrorWindow);
    } // setupUi

    void retranslateUi(QDialog *ElementIDErrorWindow)
    {
        ElementIDErrorWindow->setWindowTitle(QCoreApplication::translate("ElementIDErrorWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ElementIDErrorWindow", "Error! Wrong input data!", nullptr));
        closeButton->setText(QCoreApplication::translate("ElementIDErrorWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ElementIDErrorWindow: public Ui_ElementIDErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEMENTIDERRORWINDOW_H
