/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *addNewElementButton;
    QPushButton *editElementButton;
    QPushButton *deleteElementButton;
    QPushButton *showElementButton;
    QPushButton *loadDatabaseButton;
    QPushButton *saveDataBaseButton;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(40, 50, 321, 441));
        addNewElementButton = new QPushButton(centralwidget);
        addNewElementButton->setObjectName("addNewElementButton");
        addNewElementButton->setGeometry(QRect(560, 60, 141, 29));
        editElementButton = new QPushButton(centralwidget);
        editElementButton->setObjectName("editElementButton");
        editElementButton->setGeometry(QRect(560, 100, 141, 29));
        deleteElementButton = new QPushButton(centralwidget);
        deleteElementButton->setObjectName("deleteElementButton");
        deleteElementButton->setGeometry(QRect(560, 140, 141, 29));
        showElementButton = new QPushButton(centralwidget);
        showElementButton->setObjectName("showElementButton");
        showElementButton->setGeometry(QRect(560, 180, 141, 29));
        loadDatabaseButton = new QPushButton(centralwidget);
        loadDatabaseButton->setObjectName("loadDatabaseButton");
        loadDatabaseButton->setGeometry(QRect(560, 270, 141, 29));
        saveDataBaseButton = new QPushButton(centralwidget);
        saveDataBaseButton->setObjectName("saveDataBaseButton");
        saveDataBaseButton->setGeometry(QRect(560, 310, 141, 29));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(630, 490, 141, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addNewElementButton->setText(QCoreApplication::translate("MainWindow", "Add new element", nullptr));
        editElementButton->setText(QCoreApplication::translate("MainWindow", "Edit element", nullptr));
        deleteElementButton->setText(QCoreApplication::translate("MainWindow", "Delete element", nullptr));
        showElementButton->setText(QCoreApplication::translate("MainWindow", "Show element", nullptr));
        loadDatabaseButton->setText(QCoreApplication::translate("MainWindow", "Load database", nullptr));
        saveDataBaseButton->setText(QCoreApplication::translate("MainWindow", "Save database", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
