/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_QDialog
{
public:
    QTextBrowser *textBrowser;
    QPushButton *addNewElementButton;
    QPushButton *deleteElementButton;
    QPushButton *editElementButton;
    QPushButton *showElementButton;
    QPushButton *saveDatabaseButton;
    QPushButton *loadDatabaseButton;
    QPushButton *exitButton;

    void setupUi(QDialog *QDialog)
    {
        if (QDialog->objectName().isEmpty())
            QDialog->setObjectName("QDialog");
        QDialog->resize(800, 600);
        textBrowser = new QTextBrowser(QDialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 50, 371, 501));
        addNewElementButton = new QPushButton(QDialog);
        addNewElementButton->setObjectName("addNewElementButton");
        addNewElementButton->setGeometry(QRect(570, 70, 171, 24));
        deleteElementButton = new QPushButton(QDialog);
        deleteElementButton->setObjectName("deleteElementButton");
        deleteElementButton->setGeometry(QRect(570, 100, 171, 24));
        editElementButton = new QPushButton(QDialog);
        editElementButton->setObjectName("editElementButton");
        editElementButton->setGeometry(QRect(570, 130, 171, 24));
        showElementButton = new QPushButton(QDialog);
        showElementButton->setObjectName("showElementButton");
        showElementButton->setGeometry(QRect(570, 160, 171, 24));
        saveDatabaseButton = new QPushButton(QDialog);
        saveDatabaseButton->setObjectName("saveDatabaseButton");
        saveDatabaseButton->setGeometry(QRect(570, 340, 171, 24));
        loadDatabaseButton = new QPushButton(QDialog);
        loadDatabaseButton->setObjectName("loadDatabaseButton");
        loadDatabaseButton->setGeometry(QRect(570, 380, 171, 24));
        exitButton = new QPushButton(QDialog);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(630, 520, 111, 24));

        retranslateUi(QDialog);

        QMetaObject::connectSlotsByName(QDialog);
    } // setupUi

    void retranslateUi(QDialog *QDialog)
    {
        QDialog->setWindowTitle(QCoreApplication::translate("QDialog", "Dialog", nullptr));
        addNewElementButton->setText(QCoreApplication::translate("QDialog", "Add new element", nullptr));
        deleteElementButton->setText(QCoreApplication::translate("QDialog", "Delete element", nullptr));
        editElementButton->setText(QCoreApplication::translate("QDialog", "Edit element", nullptr));
        showElementButton->setText(QCoreApplication::translate("QDialog", "Show element", nullptr));
        saveDatabaseButton->setText(QCoreApplication::translate("QDialog", "Save to database", nullptr));
        loadDatabaseButton->setText(QCoreApplication::translate("QDialog", "Load database", nullptr));
        exitButton->setText(QCoreApplication::translate("QDialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDialog: public Ui_QDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
