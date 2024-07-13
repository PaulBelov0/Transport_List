/********************************************************************************
** Form generated from reading UI file 'SearchElementWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
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

class Ui_SearchElementWindow
{
public:
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QPushButton *okButton;
    QPushButton *exitButton;

    void setupUi(QDialog *SearchElementWindow)
    {
        if (SearchElementWindow->objectName().isEmpty())
            SearchElementWindow->setObjectName("SearchElementWindow");
        SearchElementWindow->resize(480, 320);
        plainTextEdit = new QPlainTextEdit(SearchElementWindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 70, 231, 41));
        QFont font;
        font.setPointSize(12);
        plainTextEdit->setFont(font);
        label = new QLabel(SearchElementWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 181, 31));
        label->setFont(font);
        okButton = new QPushButton(SearchElementWindow);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(180, 240, 121, 29));
        exitButton = new QPushButton(SearchElementWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(340, 240, 121, 29));

        retranslateUi(SearchElementWindow);

        QMetaObject::connectSlotsByName(SearchElementWindow);
    } // setupUi

    void retranslateUi(QDialog *SearchElementWindow)
    {
        SearchElementWindow->setWindowTitle(QCoreApplication::translate("SearchElementWindow", "Find element", nullptr));
        label->setText(QCoreApplication::translate("SearchElementWindow", "Enter the element ID:", nullptr));
        okButton->setText(QCoreApplication::translate("SearchElementWindow", "Ok", nullptr));
        exitButton->setText(QCoreApplication::translate("SearchElementWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchElementWindow: public Ui_SearchElementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHELEMENTWINDOW_H
