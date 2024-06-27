/********************************************************************************
** Form generated from reading UI file 'DeleteElementWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEELEMENTWINDOW_H
#define UI_DELETEELEMENTWINDOW_H

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
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QDialog *DeleteElementWindow)
    {
        if (DeleteElementWindow->objectName().isEmpty())
            DeleteElementWindow->setObjectName("DeleteElementWindow");
        DeleteElementWindow->resize(480, 320);
        plainTextEdit = new QPlainTextEdit(DeleteElementWindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 64, 241, 51));
        QFont font;
        font.setPointSize(12);
        plainTextEdit->setFont(font);
        deleteButton = new QPushButton(DeleteElementWindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(250, 250, 83, 29));
        exitButton = new QPushButton(DeleteElementWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(350, 250, 83, 29));
        label = new QLabel(DeleteElementWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 311, 41));
        label->setFont(font);

        retranslateUi(DeleteElementWindow);

        QMetaObject::connectSlotsByName(DeleteElementWindow);
    } // setupUi

    void retranslateUi(QDialog *DeleteElementWindow)
    {
        DeleteElementWindow->setWindowTitle(QCoreApplication::translate("DeleteElementWindow", "Delete element", nullptr));
        deleteButton->setText(QCoreApplication::translate("DeleteElementWindow", "Delete", nullptr));
        exitButton->setText(QCoreApplication::translate("DeleteElementWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("DeleteElementWindow", "Enter the ID of deleting element:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteElementWindow: public Ui_DeleteElementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEELEMENTWINDOW_H
