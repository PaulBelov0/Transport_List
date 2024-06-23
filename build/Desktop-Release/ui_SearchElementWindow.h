/********************************************************************************
** Form generated from reading UI file 'SearchElementWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHELEMENTWINDOW_H
#define UI_SEARCHELEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteElementWindow
{
public:
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QPushButton *deleteButton;
    QPushButton *exitButton;

    void setupUi(QDialog *DeleteElementWindow)
    {
        if (DeleteElementWindow->objectName().isEmpty())
            DeleteElementWindow->setObjectName("DeleteElementWindow");
        DeleteElementWindow->resize(480, 320);
        plainTextEdit = new QPlainTextEdit(DeleteElementWindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 70, 191, 41));
        label = new QLabel(DeleteElementWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 181, 31));
        deleteButton = new QPushButton(DeleteElementWindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(180, 240, 121, 29));
        exitButton = new QPushButton(DeleteElementWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(340, 240, 121, 29));

        retranslateUi(DeleteElementWindow);

        QMetaObject::connectSlotsByName(DeleteElementWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteElementWindow)
    {
        DeleteElementWindow->setWindowTitle(QCoreApplication::translate("DeleteElementWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DeleteElementWindow", "Enter the element ID:", nullptr));
        deleteButton->setText(QCoreApplication::translate("DeleteElementWindow", "Ok", nullptr));
        exitButton->setText(QCoreApplication::translate("DeleteElementWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteElementWindow: public Ui_DeleteElementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHELEMENTWINDOW_H
