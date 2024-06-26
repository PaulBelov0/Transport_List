/********************************************************************************
** Form generated from reading UI file 'MessageToUserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGETOUSERWINDOW_H
#define UI_MESSAGETOUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MessageToUserWindow
{
public:
    QLabel *textMessage;
    QPushButton *okButton;

    void setupUi(QDialog *MessageToUserWindow)
    {
        if (MessageToUserWindow->objectName().isEmpty())
            MessageToUserWindow->setObjectName("MessageToUserWindow");
        MessageToUserWindow->resize(320, 240);
        textMessage = new QLabel(MessageToUserWindow);
        textMessage->setObjectName("textMessage");
        textMessage->setGeometry(QRect(40, 79, 221, 51));
        okButton = new QPushButton(MessageToUserWindow);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(120, 180, 83, 29));

        retranslateUi(MessageToUserWindow);

        QMetaObject::connectSlotsByName(MessageToUserWindow);
    } // setupUi

    void retranslateUi(QDialog *MessageToUserWindow)
    {
        MessageToUserWindow->setWindowTitle(QCoreApplication::translate("MessageToUserWindow", "Dialog", nullptr));
        textMessage->setText(QString());
        okButton->setText(QCoreApplication::translate("MessageToUserWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessageToUserWindow: public Ui_MessageToUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGETOUSERWINDOW_H
