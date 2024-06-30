/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addNewElementButton;
    QPushButton *editElementButton;
    QPushButton *deleteElementButton;
    QPushButton *loadDatabaseButton;
    QPushButton *saveDataBaseButton;
    QPushButton *exitButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1081, 600);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addNewElementButton = new QPushButton(centralwidget);
        addNewElementButton->setObjectName("addNewElementButton");
        addNewElementButton->setGeometry(QRect(900, 90, 141, 29));
        editElementButton = new QPushButton(centralwidget);
        editElementButton->setObjectName("editElementButton");
        editElementButton->setGeometry(QRect(900, 130, 141, 29));
        deleteElementButton = new QPushButton(centralwidget);
        deleteElementButton->setObjectName("deleteElementButton");
        deleteElementButton->setGeometry(QRect(900, 170, 141, 29));
        loadDatabaseButton = new QPushButton(centralwidget);
        loadDatabaseButton->setObjectName("loadDatabaseButton");
        loadDatabaseButton->setGeometry(QRect(900, 270, 141, 29));
        saveDataBaseButton = new QPushButton(centralwidget);
        saveDataBaseButton->setObjectName("saveDataBaseButton");
        saveDataBaseButton->setGeometry(QRect(900, 310, 141, 29));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(910, 490, 141, 29));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 30, 821, 501));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1081, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Transport Database", nullptr));
        addNewElementButton->setText(QCoreApplication::translate("MainWindow", "Add new element", nullptr));
        editElementButton->setText(QCoreApplication::translate("MainWindow", "Edit element", nullptr));
        deleteElementButton->setText(QCoreApplication::translate("MainWindow", "Delete element", nullptr));
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
